/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:44:31 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/04 09:44:31 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char	*allocate_ff_row(int width)
{
	char	*row;
	int		j;

	row = malloc(sizeof(char) * (width + 1));
	if (!row)
		return (NULL);
	j = 0;
	while (j < width)
	{
		row[j] = '0';
		j++;
	}
	row[j] = '\0';
	return (row);
}

void	copy_grid_for_flood_fill(t_map *map)
{
	int	i;

	map->ff_grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->ff_grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		map->ff_grid[i] = allocate_ff_row(map->width);
		if (!map->ff_grid[i])
		{
			while (--i >= 0)
				free(map->ff_grid[i]);
			free(map->ff_grid);
			map->ff_grid = NULL;
			return ;
		}
		i++;
	}
	map->ff_grid[i] = NULL;
}

static int	is_valid_position(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height || x < 0)
		return (0);
	if (x >= (int)ft_strlen(map->grid[y]))
		return (0);
	if (map->grid[y][x] == '1' || map->ff_grid[y][x] == '1')
		return (0);
	return (1);
}

void	flood_fill(t_map *map, int x, int y, int *error)
{
	if (*error)
		return ;
	if (!is_valid_position(map, x, y))
	{
		if (y < 0 || y >= map->height || x < 0
			|| x >= (int)ft_strlen(map->grid[y]))
			*error = 1;
		return ;
	}
	map->ff_grid[y][x] = '1';
	flood_fill(map, x + 1, y, error);
	flood_fill(map, x - 1, y, error);
	flood_fill(map, x, y + 1, error);
	flood_fill(map, x, y - 1, error);
}

int	validate_map_closed(t_map *map)
{
	int	error;
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (y == 0 || y == map->height - 1 || 
			    x == 0 || x == (int)ft_strlen(map->grid[y]) - 1)
			{
				if (map->grid[y][x] == '0' || 
				    map->grid[y][x] == 'N' || 
				    map->grid[y][x] == 'S' || 
				    map->grid[y][x] == 'E' || 
				    map->grid[y][x] == 'W')
					return (0);
			}
			x++;
		}
		y++;
	}
	error = 0;
	copy_grid_for_flood_fill(map);
	if (!map->ff_grid)
		return (0);
	flood_fill(map, map->p_x, map->p_y, &error);
	free_ff_grid(map);
	if (error)
		return (0);
	return (1);
}

/*int	validate_map_closed(t_map *map)
{
	int	error;

	error = 0;
	copy_grid_for_flood_fill(map);
	if (!map->ff_grid)
		return (0);
	flood_fill(map, map->p_x, map->p_y, &error);
	free_ff_grid(map);
	if (error)
		return (0);
	return (1);
}*/

/*
.void	copy_grid_for_flood_fill(t_map *map):
create a copy for map  and see who which cell 
is visited ,awal shi btkun m3btun klun 0 yani manu visited abl
.void	flood_fill(t_map *map, int x, int y, int *error):
*/


/*flood fill is algo that test if map is valid or not,
there is many cas when map is not vlaid:
if edge are not all 1, space in wall yani 11 11, 
line different length,
internal space 1100 1, player is outside , tabs inside map*/

/*Goes above the map (y < 0)
Goes below the map (y >= height)
Goes left of the map (x < 0)
Goes past the right edge of a row (x >= strlen(row))
Touches a space ' ' (outside the map)
kl hol l cases yani:
Water (flood fill) escaped the walls , the map is
open ,invalid*/