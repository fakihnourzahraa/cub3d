/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:14:58 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/29 20:45:24 by nour             ###   ########.fr       */
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
//start of image data + correct row + correct column
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

void	draw_gun(t_game *game, t_img *gun_texture)
{
	int					x;
	int					y;
	int					start_x;
	int					start_y;
	unsigned int		color;

	start_x = (game->screen_width - gun_texture->width) / 2;
	start_y = game->screen_height - gun_texture->height;
	y = 0;
	while (y < gun_texture->height)
	{
		x = 0;
		while (x < gun_texture->width)
		{
			color = get_texture_color(gun_texture, x, y);
			if (color != 0xFF000000)
				put_pixel(game->img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}
