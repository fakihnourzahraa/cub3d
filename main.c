/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:20:50 by nour              #+#    #+#             */
/*   Updated: 2025/12/23 18:34:38 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

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
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "cub3d");
	game->img->img = mlx_new_image(game->mlx, game->screen_width, game->screen_height);
	start_player(game);
	get_image(game);
}
int	escape_game_no_update(t_game *game)
{
	exit(0);
	return (1);
}
int	keys(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code == 30)
		move_left(game);
	else if (code == 32)
		move_right(game);
	else if (code == 17)
		move_up(game);
	else if (code == 31)
		move_down(game);
	if (code == 65307)
		escape_game_no_update(game);
	// mlx_put_image_to_window(m, game->win, game->txt.player, j * 64, i * 64);
	return (0);
}
int main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	game = init_game_struct();
	init_game(game);
	draw_map(game);
	mlx_key_hook(game->win, keys, game);
	mlx_hook(game->win, 17, 0, escape_game_no_update, game);
	mlx_loop(game->mlx);
}

