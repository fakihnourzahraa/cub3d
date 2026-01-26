/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 00:47:08 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/31 00:47:08 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	get_map_position(char **lines, int *map_start, int *map_height)
{
	*map_start = find_map_start(lines);
	if (*map_start < 0)
	{
		print_error("No map found");
		return (0);
	}
	*map_height = count_map_lines(lines, *map_start);
	if (*map_height == 0)
	{
		print_error("Empty map");
		return (0);
	}
	return (1);
}

static char	**get_validated_map(char **lines, int *map_start, int *map_height)
{
	char	**map_grid;

	if (!get_map_position(lines, map_start, map_height))
		return (NULL);
	map_grid = extract_map_lines(lines, *map_start, *map_height);
	if (!map_grid)
	{
		print_error("Failed to extract map");
		return (NULL);
	}
	if (!validate_map_chars(map_grid))
	{
		free_string_array(map_grid);
		print_error("Invalid map characters");
		return (NULL);
	}
	return (map_grid);
}

static int	init_map_struct(t_game *game, char **map_grid, int map_height)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		free_string_array(map_grid);
		return (0);
	}
	game->map->grid = map_grid;
	game->map->height = map_height;
	game->map->width = get_map_width(map_grid);
	return (1);
}

int	parse_maps(char **lines, t_game *game)
{
	int		map_start;
	int		map_height;
	char	**map_grid;

	map_grid = get_validated_map(lines, &map_start, &map_height);
	if (!map_grid)
		return (0);
	if (!init_map_struct(game, map_grid, map_height))
		return (0);
	if (!normalize_map(game->map))
	{
		free_string_array(map_grid);
		return (print_error("Failed to normalize map"));
	}
	return (1);
}
