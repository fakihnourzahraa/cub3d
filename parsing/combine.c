/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:54:23 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/27 10:34:50 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	parse_file_content(char **lines, t_game *game)
{
	if (!parse_textures(lines, game))
		return (0);
	if (!parse_colors(lines, game))
		return (0);
	if (!parse_maps(lines, game))
		return (0);
	return (1);
}

int	validate_parsed_map(t_map *map)
{
	if (validate_player(map))
		return (0);
	if (!validate_map_closed(map))
		return (print_error("Map is not closed/surrounded by walls"));
	return (1);
}

int	has_config_after_map(char **lines, int map_start)
{
	int		i;

	if (map_start < 0)
		return (0);
	i = map_start;
	while (lines[i] && !is_empty_line(lines[i]))
		i++;
	if (lines[i])
		return (1);
	return (0);
}

int	validate_file_order(char **lines)
{
	int	map_start;

	map_start = find_map_start(lines);
	if (has_config_after_map(lines, map_start))
		return (print_error("Map must be the last element in file"));
	return (1);
}

int	complete_parse(char *filename, t_game *game)
{
	char	**lines;
	int		success;

	if (!validate_file(filename))
		return (0);
	lines = load_file_lines(filename);
	if (!lines)
		return (0);
	if (!validate_file_order(lines))
	{
		free_string_array(lines);
		return (0);
	}
	success = parse_file_content(lines, game);
	free_string_array(lines);
	if (!success)
		return (0);
	return (validate_parsed_map(game->map));
}

/*
complete_parse()
    1. validate_file()           Check extension & access
    2. load_file_lines()         Read all lines into memory
    3. parse_file_content()      Parse textures, colors, map
    4. free_string_array()       Clean up lines
    5. validate_parsed_map()     Validate player & walls
    Return success/failure*/

/*
while (lines[i] && !is_empty_line(lines[i]))
		i++;//Skip all map lines
	if (lines[i])
		return (1);If after the map there is still a line
		 that is not empty, it means there is extra content 
		 after the map, which is forbidden
*/