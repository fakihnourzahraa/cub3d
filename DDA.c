/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:40:17 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/19 15:33:44 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start(t_game *game)
{
	t_map *map = game->map;

	game->ray->map_x = (int)game->player->dir_x;
	game->ray->map_y = (int)game->player->dir_y;
}