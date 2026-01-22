/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:33:22 by nour              #+#    #+#             */
/*   Updated: 2026/01/22 16:37:49 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		put_pixel(game->img, x, y, game->textures->sky_color);
		y++;
	}
}

void	draw_floor(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end;
	while (y < game->screen_height)
	{
		put_pixel(game->img, x, y, game->textures->floor_color);
		y++;
	}
}

int	calculate_tex_x(t_ray *ray, t_game *game, t_img *texture)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player->y + ray->calc->perp_wall_dist
			* ray->calc->ray_dir_y;
	else
		wall_x = game->player->x + ray->calc->perp_wall_dist
			* ray->calc->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->calc->ray_dir_x > 0)
		|| (ray->side == 1 && ray->calc->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	draw_textured_wall(t_ray *ray, t_game *game, t_img *texture, int x)
{
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		y;

	tex_x = calculate_tex_x(ray, game, texture);
	step = (double)texture->height / (double)(ray->draw_end - ray->draw_start);
	tex_pos = (ray->draw_start - game->screen_height / 2
			+ (ray->draw_end - ray->draw_start) / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		put_pixel(game->img, x, y, get_texture_color(texture, tex_x, tex_y));
		y++;
	}
}

void	draw_solid_wall(t_ray *ray, t_game *game, int x)
{
	int	color;
	int	y;

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
