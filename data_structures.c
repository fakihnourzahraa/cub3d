/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:51:55 by nour              #+#    #+#             */
/*   Updated: 2025/12/21 19:03:13 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/*
** Initializes the map structure
** Allocates memory for grid (to be filled by parser)
*/

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->p = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->ff_grid = NULL;
	return (map);
}

/*
** Initializes textures to NULL
** Parser will load actual .xpm files
*/
static t_textures	*init_textures(void)
{
	t_textures	*tex;

	tex = malloc(sizeof(t_textures));
	if (!tex)
		return (NULL);
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->east = NULL;
	tex->north_path = NULL;
	tex->south_path = NULL;
	tex->west_path = NULL;
	tex->east_path = NULL;
	tex->floor_color = 0;
	tex->ceiling_color = 0;
	return (tex);
}

/*
** Initializes the player structure
** Position and direction will be set from map parsing (N/S/E/W)
*/
t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	return (player);
}

/*
** Initializes the ray structure
** Will be recalculated for each column during rendering
*/
t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->camera_x = 0.0;
	ray->ray_dir_x = 0.0;
	ray->ray_dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->perp_wall_dist = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_x = 0.0;
	ray->tex_x = 0;
	return (ray);
}

/*
** Initializes the image structure (frame buffer)
** img will be created with mlx_new_image
*/
t_img	*init_image(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (img);
}

/*
** Initializes the entire game structure
** Returns NULL if any allocation fails
*/
t_game	*init_game_struct(void)
{
	t_game	*game;
	int		i;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->win = NULL;
	game->map = init_map();
	game->player = init_player();
	game->ray = init_ray();
	game->img = init_image();
	game->textures = init_textures();
	game->screen_width = NULL;
	game->screen_height = NULL;
	i = 0;
	while (i < 256)
		game->keys[i++] = 0;
	if (!game->map || !game->player || !game->ray 
		|| !game->img || !game->textures)
	{
		free_game(game);
		return (NULL);
	}
	return (game);
}

/*
** Sets player position and direction based on spawn character
** spawn_char: 'N', 'S', 'E', or 'W'
** x, y: grid position where player spawned
*/
void	set_player_spawn(t_player *player, char spawn_char, int x, int y)
{
	player->x = (double)x + 0.5;
	player->y = (double)y + 0.5;
	if (spawn_char == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
	else if (spawn_char == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else if (spawn_char == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
	else if (spawn_char == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
}
