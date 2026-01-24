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

int	complete_parse(char *filename, t_game *game)
{
	char	**lines;

	if (!validate_file_extension(filename))
		return (print_error("Invalid file extension (must be .cub)"));
	if (!validate_file_access(filename))
		return (print_error("Cannot access file"));
	lines = read_entire_file(filename);
	if (!lines)
		return (print_error("Failed to read file"));
	if (!parse_textures(lines, game))
	{
		free_string_array(lines);
		return (0);
	}
	if (!parse_colors(lines, game))
	{
		free_string_array(lines);
		return (0);
	}
	if (!parse_maps(lines, game))
	{
		free_string_array(lines);
		return (0);
	}
	free_string_array(lines);
	if (validate_player(game->map))
		return (0);
	if (!validate_map_closed(game->map))
		return (print_error("Map is not closed/surrounded by walls"));
	return (1);
}


