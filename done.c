/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:39:14 by nour              #+#    #+#             */
/*   Updated: 2025/12/16 17:40:59 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(void)
{
	ft_printf("Error\n");
}

void	nothinn(void)
{
	write(1, "", 0);
}


void	intialize(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_message(), nothinn());
	game->w = mlx_new_window(game->mlx, (game->map->width + 1) * 64,
			game->map->height * 64, "cub3d");
	if (!game->w)
		return (error_message(), nothinn());
	get_image(game);
}
int	handle_keypress(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code == 65361)
		move_left(game);
	else if (code == 65363)
		move_right(game);
	else if (code == 65362)
		move_up(game);
	else if (code == 65364)
		move_down(game);
	else if (code == 65307)
		escape_game_no_update(game);
	return (0);
}

int	escape_game(t_game *game)
{
	// update(game);
	// free_twod(game->map->g);
	// free_twod(game->map->ff_grid);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_image(game->mlx, (game)->txt.bg);
	// mlx_destroy_image(game->mlx, (game)->txt.collec);
	// mlx_destroy_image(game->mlx, (game)->txt.exit);
	// mlx_destroy_image(game->mlx, (game)->txt.player);
	// mlx_destroy_image(game->mlx, (game)->txt.wall);
	mlx_destroy_display(game->mlx);
	game->mlx = NULL;
	exit(0);
	return (1);
}