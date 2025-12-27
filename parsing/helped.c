/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helped.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 23:10:58 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/27 23:10:58 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	identify_line_type(char *line, int line_num)
{
	char	*trimmed;

	trimmed = skip_whitespace(line);
	if (is_empty_line(trimmed))
		printf("Line %d: Empty (skip)\n", line_num);
	else if (starts_with(trimmed, "NO "))
		printf("Line %d: Texture identifier (NO)\n", line_num);
	else if (starts_with(trimmed, "SO "))
		printf("Line %d: Texture identifier (SO)\n", line_num);
	else if (starts_with(trimmed, "WE "))
		printf("Line %d: Texture identifier (WE)\n", line_num);
	else if (starts_with(trimmed, "EA "))
		printf("Line %d: Texture identifier (EA)\n", line_num);
	else if (starts_with(trimmed, "F "))
		printf("Line %d: Color identifier (F)\n", line_num);
	else if (starts_with(trimmed, "C "))
		printf("Line %d: Color identifier (C)\n", line_num);
	else
		printf("Line %d: Map line\n", line_num);
}

void	process_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		identify_line_type(lines[i], i + 1);
		i++;
	}
}
