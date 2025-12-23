/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:37:06 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/23 18:38:12 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//parse function

void	vertical(t_map *map, t_player *player)
{
	if (map->p == 'E')
    {
        player->dir_x = 1;
        player->dir_y = 0;
        player->plane_x = 0;
        player->plane_y = 0.66;
    }
    else if (map->p == 'W')
    {
        player->dir_x = -1;
        player->dir_y = 0;
        player->plane_x = 0;
        player->plane_y = -0.66;
    }
}
void	horizontal(t_map *map, t_player *player)
{
	if (map->p == 'N')
    {
        player->dir_x = 0.0;
        player->dir_y = -1.0;
        player->plane_x = 0.66;
        player->plane_y = 0.0;
    }
    else if (map->p == 'S')
    {
        player->dir_x = 0.0;
        player->dir_y = 1.0;
        player->plane_x = -0.66;
        player->plane_y = 0.0;
    }
}
void	start_player(t_game *game)
{
	t_player *player;
	t_map *map;

	player = game->player;
	map = game->map;
	player->x = (double)map->p_x + 0.5;
	player->y = (double)map->p_y + 0.5;
	vertical(map, player);
	horizontal(map, player);
}

t_game	*init_game_struct(void)
{
	t_game	*game;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	game->mlx = NULL;
	game->win = NULL;
	game->map = init_map();
	game->player = init_player();
	game->ray = init_ray();
	game->img = init_image();
	game->textures = init_textures();
	game->screen_width = 1280;
	game->screen_height = 720;
	while (i < 256)
	{
		game->keys[i] = 0;
		i++;		
	}
	return (game);
}
