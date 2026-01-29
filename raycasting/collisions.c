/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:42:55 by nour              #+#    #+#             */
/*   Updated: 2026/01/29 20:45:33 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	colliding(t_game *g, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (g->map->grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	check_collision(t_game *g, double new_x, double new_y)
{
	double	b;

	b = 0.075;
	if (colliding(g, new_x - b, new_y - b))
		return (1);
	if (colliding(g, new_x + b, new_y - b))
		return (1);
	if (colliding(g, new_x - b, new_y + b))
		return (1);
	if (colliding(g, new_x + b, new_y + b))
		return (1);
	return (0);
}
