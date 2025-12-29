/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:56:04 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/29 11:56:04 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

char	*extract_rgb_string(char *line)
{
	// TODO: Extract "220,100,0" from "F 220,100,0"
}

int	parse_rgb_values(char *rgb_str, int *r, int *g, int *b)
{
	// TODO: Parse "220,100,0" into r, g, b
	// Validate 0-255 range
}

int	parse_one_color(char *line, int *dest, char *id)
{
	// TODO: Process one F or C line
	// Check duplicate, extract, parse, convert, store
}

int	parse_colors(char **lines, t_game *game)
{
	// TODO: Loop through lines
	// Find F and C
	// Verify both found
}