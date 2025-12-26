/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:20:50 by nour              #+#    #+#             */
/*   Updated: 2025/12/26 16:28:57 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	//parsing
	// game = init_game_struct();
	game = create_test_game(1);
	init_game(game);
	draw_map(game);
	mlx_key_hook(game->win, keys, game);
	mlx_hook(game->win, 17, 0, escape_game_no_update, game);
	mlx_loop(game->mlx);
}

