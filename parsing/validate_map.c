/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:44:03 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/23 16:36:35 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

int	find_player(t_map *map, int *count)
{
	int	y;
	int	x;

	y = 0;
	*count = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player(map->grid[y][x]))
			{
				map->p = map->grid[y][x];
				map->p_x = x;
				map->p_y = y;
				map->grid[y][x] = '0'; 
				(*count)++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
