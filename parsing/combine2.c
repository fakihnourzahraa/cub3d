/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    combine2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:22:54 by nour              #+#    #+#             */
/*   Updated: 2026/01/27 10:24:48 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	validate_file(char *filename)
{
	if (!validate_file_extension(filename))
		return (print_error("Invalid file extension (must be .cub)"));
	if (!validate_file_access(filename))
		return (print_error("Cannot access file"));
	return (1);
}

char	**load_file_lines(char *filename)
{
	char	**lines;

	lines = read_entire_file(filename);
	if (!lines)
		print_error("Failed to read file");
	return (lines);
}
