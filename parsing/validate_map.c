/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:44:03 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/23 16:13:20 by miwehbe          ###   ########.fr       */
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
				(*count)++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_player_count(int count)
{
	if (count == 0)
	{
		print_error("Error: No player found");
		return (1); 
	}
	if (count > 1)
	{
		print_error("Error: Multiple players found");
		return (1);
	}
	return (0);
}

int	validate_player(t_map *map)
{
	int	count;

	if (find_player(map, &count))
		return (1);
	if (validate_player_count(count))
		return (1);
	return (0);
}
