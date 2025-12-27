/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:20:50 by nour              #+#    #+#             */
/*   Updated: 2025/12/27 16:31:04 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*int	main(int argc, char **argv)
{
	t_game	*game;

	// parsing
	//  game = init_game_struct();
	(void)argc;
	(void)argv;
	game = create_test_game(1);
	init_game(game);
	update(game);
	mlx_hook(game->win, 2, 1, keys, game);
	mlx_hook(game->win, 3, 2, key_release, game);
	mlx_hook(game->win, 17, 0, escape_game_no_update, game);
	mlx_loop_hook(game->mlx, key_loop, game);
	mlx_loop(game->mlx);
}*/
int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		print_error("Usage: ./cub3D <map.cub>");
		return (1);
	}
	
	if (!parse_cub_file(argv[1], &game))
	{
		printf("❌ Parsing failed!\n");
		return (1);
	}
	
	printf("\n✅ Parsing successful!\n");
	return (0);
}

// key hook doesnt register how long we're pressing for
// 2 -> key is pressed, 3 -> key is released
// 1 key press, 2 key release, 0 no mask needed
