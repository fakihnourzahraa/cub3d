/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:14:58 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/14 11:50:12 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// were just finding offset and writing the 32 bit color to it

int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel;

	if (!texture || !texture->addr)
		return (0);
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

t_img	*get_wall_texture(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
	{
		if (ray->calc->ray_dir_x > 0)
			return (game->textures->east);
		else
			return (game->textures->west);
	}
	else
	{
		if (ray->calc->ray_dir_y > 0)
			return (game->textures->south);
		else
			return (game->textures->north);
	}
}

// void	draw_line(t_ray *ray, int x)
// {
// 	t_game	*game;
// 	int		y;
// 	int		color;

// 	game = ray->game;
// 	if (ray->draw_start >= ray->draw_end)
// 		return ;
// 	y = 0;
// 	while (y < ray->draw_start)
// 	{
// 		put_pixel(game->img, x, y, game->textures->sky_color);
// 		y++;
// 	}
// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		if (ray->side == 1)
// 			color = 0x808080;
// 		else
// 			color = 0xFFFFFF;
// 		put_pixel(game->img, x, y, color);
// 		y++;
// 	}
// 	y = ray->draw_end;
// 	while (y < game->screen_height)
// 	{
// 		put_pixel(game->img, x, y, game->textures->floor_color);
// 		y++;
// 	}
// }

void	draw_line(t_ray *ray, int x)
{
	t_game	*game;
	int		y;
	int		color;
	t_img	*texture;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;

	game = ray->game;
	if (ray->draw_start >= ray->draw_end)
		return ;
	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(game->img, x, y, game->textures->sky_color);
		y++;
	}
	texture = get_wall_texture(ray, game);
	if (texture && texture->addr)
	{
		if (ray->side == 0)
			wall_x = game->player->y + ray->calc->perp_wall_dist * ray->calc->ray_dir_y;
		else
			wall_x = game->player->x + ray->calc->perp_wall_dist * ray->calc->ray_dir_x;
		wall_x -= floor(wall_x);

		tex_x = (int)(wall_x * (double)texture->width);
		if ((ray->side == 0 && ray->calc->ray_dir_x > 0) || (ray->side == 1 && ray->calc->ray_dir_y < 0))
			tex_x = texture->width - tex_x - 1;

		step = (double)texture->height / (double)(ray->draw_end - ray->draw_start);
		tex_pos = (ray->draw_start - game->screen_height / 2 + (ray->draw_end - ray->draw_start) / 2) * step;
		y = ray->draw_start;
		while (y < ray->draw_end)
		{
			tex_y = (int)tex_pos & (texture->height - 1);
			tex_pos += step;
			color = get_texture_color(texture, tex_x, tex_y);
			put_pixel(game->img, x, y, color);
			y++;
		}
	}
	else
	{
		y = ray->draw_start;
		while (y < ray->draw_end)
		{
			if (ray->side == 1)
				color = 0x808080;
			else
				color = 0xFFFFFF;
			put_pixel(game->img, x, y, color);
			y++;
		}
	}
	
	y = ray->draw_end;
	while (y < game->screen_height)
	{
		put_pixel(game->img, x, y, game->textures->floor_color);
		y++;
	}
}

void	update(t_game *game)
{
	int		i;
	t_ray	*ray;

	i = 0;
	while (i < game->screen_width)
	{
		ray = init_ray(game);
		init_for_col(ray, i);
		dda(ray, game);
		calc_to_draw(ray);
		draw_line(ray, i);
		i++;
		free(ray->calc);
		free(ray);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
// we're drawing pixel by pixel into the buffer, then putting the buffer
// that way its smoother execution
// to do: put pixel function