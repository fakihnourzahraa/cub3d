/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:20:50 by nour              #+#    #+#             */
/*   Updated: 2025/12/21 19:04:52 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	init_game(t_game *game)
{

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		error_message();
		return ;
	}
	game->win = mlx_new_window(game->mlx, 1280, 720, "cub3d");
	game->img->img = mlx_new_image(game->mlx, 1280, 720);
	if (!game->win)
	{
		error_message();
		return ;
	}
	//get_image(game);
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

	game = 	init_game_struct();
	init_game(game);
	mlx_key_hook(game->win, keys, game);
	mlx_hook(game->win, 17, 0, escape_game_no_update, game);
	mlx_loop(game->mlx);
}

