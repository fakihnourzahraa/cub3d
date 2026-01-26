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

int	complete_parse(char *filename, t_game *game)
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
}
/*
complete_parse()
    1. validate_file()           → Check extension & access
    2. load_file_lines()         → Read all lines into memory
    3. parse_file_content()      → Parse textures, colors, map
    4. free_string_array()       → Clean up lines
    5. validate_parsed_map()     → Validate player & walls
    Return success/failure*/
