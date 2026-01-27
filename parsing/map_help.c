/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:24:45 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/27 10:33:50 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	count_map_lines(char **lines, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (lines[i])
	{
		if (is_empty_line(lines[i]))
			break ;
		count++;
		i++;
	}
	return (count);
}

char	**extract_map_lines(char **lines, int start, int count)
{
	char	**map;
	char	*temp;
	int		i;

	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		temp = ft_strtrim(lines[start + i], "\n");
		if (!temp)
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		map[i] = temp;
		i++;
	}
	map[i] = NULL;
	return (map);
}

static int	is_config_or_empty(char *trimmed)
{
	if (is_empty_line(trimmed))
		return (1);
	if (starts_with(trimmed, "NO "))
		return (1);
	if (starts_with(trimmed, "SO "))
		return (1);
	if (starts_with(trimmed, "WE "))
		return (1);
	if (starts_with(trimmed, "EA "))
		return (1);
	if (starts_with(trimmed, "F "))
		return (1);
	if (starts_with(trimmed, "C "))
		return (1);
	return (0);
}

int	find_map_start(char **lines)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (lines[i])
	{
		trimmed = skip_whitespace(lines[i]);
		if (is_config_or_empty(trimmed))
		{
			i++;
			continue ;
		}
		if (ft_strchr(trimmed, '1') || ft_strchr(trimmed, '0'))
			return (i);
		return (-1);
	}
	return (-1);
}
