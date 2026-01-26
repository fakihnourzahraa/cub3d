/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:54:23 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/23 16:57:20 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	validate_file(char *filename)
{
	if (!validate_file_extension(filename))
		return (print_error("Invalid file extension (must be .cub)"));
	if (!validate_file_access(filename))
		return (print_error("Cannot access file"));
	return (1);
}

static char	**load_file_lines(char *filename)
{
	char	**lines;

	lines = read_entire_file(filename);
	if (!lines)
		print_error("Failed to read file");
	return (lines);
}

static int	parse_file_content(char **lines, t_game *game)
{
	if (!parse_textures(lines, game))
		return (0);
	if (!parse_colors(lines, game))
		return (0);
	if (!parse_maps(lines, game))
		return (0);
	return (1);
}

static int	validate_parsed_map(t_map *map)
{
	if (validate_player(map))
		return (0);
	if (!validate_map_closed(map))
		return (print_error("Map is not closed/surrounded by walls"));
	return (1);
}

static int	has_config_after_map(char **lines, int map_start)
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

static int	validate_file_order(char **lines)
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

/*int	complete_parse(char *filename, t_game *game)
{
	char	**lines;
	int		success;

	if (!validate_file(filename))
		return (0);
	lines = load_file_lines(filename);
	if (!lines)
		return (0);
	success = parse_file_content(lines, game);
	free_string_array(lines);
	if (!success)
		return (0);
	return (validate_parsed_map(game->map));
}*/

/*
complete_parse()
    1. validate_file()           Check extension & access
    2. load_file_lines()         Read all lines into memory
    3. parse_file_content()      Parse textures, colors, map
    4. free_string_array()       Clean up lines
    5. validate_parsed_map()     Validate player & walls
    Return success/failure*/


/*static int	has_config_after_map(char **lines, int map_start)
{
	int		i;
	char	*trimmed;

	if (map_start < 0)
		return (0);
	
	i = map_start;

	while (lines[i] && !is_empty_line(lines[i]))
		i++;
	while (lines[i])
	{
		trimmed = skip_whitespace(lines[i]);
		
		if (!is_empty_line(trimmed))
		{
			if (starts_with(trimmed, "NO ") || starts_with(trimmed, "SO ")
				|| starts_with(trimmed, "WE ") || starts_with(trimmed, "EA ")
				|| starts_with(trimmed, "F ") || starts_with(trimmed, "C "))
				return (1);
		}
		i++;
	}
	return (0);
}*/