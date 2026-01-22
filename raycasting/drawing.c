/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:14:58 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/22 16:34:49 by nour             ###   ########.fr       */
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
	pixel = texture->addr + (y * texture->line_length + x
			*(texture->bits_per_pixel / 8));
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

void	draw_line(t_ray *ray, int x)
{
	t_game	*game;
	t_img	*texture;

	game = ray->game;
	if (ray->draw_start >= ray->draw_end)
		return ;
	draw_ceiling(game, x, ray->draw_start);
	texture = get_wall_texture(ray, game);
	if (texture && texture->addr)
		draw_textured_wall(ray, game, texture, x);
	else
		draw_solid_wall(ray, game, x);
	draw_floor(game, x, ray->draw_end);
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