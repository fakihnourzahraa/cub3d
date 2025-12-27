/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:35:25 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/27 16:32:32 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_loop(t_game *game)
{
	int	*keys;

	keys = game->keys;
	if (keys[97])
		move_left(game);
	else if (keys[100])
		move_right(game);
	else if (keys[119])
		move_up(game);
	else if (keys[115])
		move_down(game);
	return (0);
}

int	keys(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code < 256)
		game->keys[code] = 1;
	else if (code == 65307)
		escape_game_no_update(game);
	else if (code == 65361)
		rotate_left(game);
	else if (code == 65363)
		rotate_right(game);
	return (0);
}

int	key_release(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code < 256)
		game->keys[code] = 0;
	return (0);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "cub3d");
	game->img->img = mlx_new_image(game->mlx, game->screen_width,
			game->screen_height);
	game->img->addr = mlx_get_data_addr(game->img->img,
			&game->img->bits_per_pixel, &game->img->line_length,
			&game->img->endian);
	start_player(game);
}

int	escape_game_no_update(t_game *game)
{
	free_game(game);
	exit(0);
	return (1);
}
