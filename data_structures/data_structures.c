/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:51:55 by nour              #+#    #+#             */
/*   Updated: 2026/01/22 15:40:35 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->p = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->ff_grid = NULL;
	return (map);
}

t_textures	*init_textures(void)
{
	t_textures	*text;

	text = malloc(sizeof(t_textures));
	text->north = NULL;
	text->south = NULL;
	text->west = NULL;
	text->east = NULL;
	text->north_path = NULL;
	text->south_path = NULL;
	text->west_path = NULL;
	text->east_path = NULL;
	text->floor_color = -1;
	text->sky_color = -1;
	return (text);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	return (player);
}

t_ray	*init_ray(t_game *game)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->calc = malloc(sizeof(t_calc));
	ray->calc->ray_dir_x = 0;
	ray->calc->ray_dir_y = 0;
	ray->calc->side_dist_x = 0;
	ray->calc->side_dist_y = 0;
	ray->calc->delta_dist_x = 0;
	ray->calc->delta_dist_y = 0;
	ray->calc->perp_wall_dist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_x = 0;
	ray->tex_x = 0;
	ray->game = game;
	ray->map_x = (int)game->player->x;
	ray->map_y = (int)game->player->y;
	return (ray);
}

t_img	*init_image(t_game *game)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	img->width = game->screen_width;
	img->height = game->screen_height;
	return (img);
}
