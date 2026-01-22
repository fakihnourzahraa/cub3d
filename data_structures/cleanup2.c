/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:02:33 by nour              #+#    #+#             */
/*   Updated: 2026/01/22 16:42:00 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->textures)
		free_textures_struct(game->mlx, game->textures);
	if (game->map)
		free_map(game->map);
	free_image(game->mlx, game->img);
	free(game->player);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

// void	error_exit(t_game *game)
// {
// 	ft_putendl_fd("Error", 2);
// 	free_game(game);
// 	exit(1);
// }

void	error_message(void)
{
	ft_printf("Error\n");
}

int	escape_game_no_update(t_game *game)
{
	free_game(game);
	exit(0);
	return (1);
}
