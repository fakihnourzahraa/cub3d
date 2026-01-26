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

int	find_map_start(char **lines)
{
	int	i;
	char	*trimmed;

	i = 0;
	while (lines[i])
	{
		trimmed = skip_whitespace(lines[i]);

		if (is_empty_line(trimmed))
		{
			i++;
			continue;
		}
		if (starts_with(trimmed, "NO ")
			|| starts_with(trimmed, "SO ")
			|| starts_with(trimmed, "WE ")
			|| starts_with(trimmed, "EA ")
			|| starts_with(trimmed, "F ")
			|| starts_with(trimmed, "C "))
		{
			i++;
			continue;
		}
		if (ft_strchr(trimmed, '1') || ft_strchr(trimmed, '0'))
			return (i);
		return (-1);
	}
	return (-1);
}

int 	count_map_lines(char **lines, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (lines[i])
	{
		if (is_empty_line(lines[i]))
			break;
		count++;
		i++;
	}
	return (count);
}

char **extract_map_lines(char **lines, int start, int count)
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

int 	parse_maps(char **lines, t_game *game)
{
	int		map_start;
	int		map_height;
	char	**map_grid;

	map_start = find_map_start(lines);
	if (map_start < 0)
		return (print_error("No map found"));
	map_height = count_map_lines(lines, map_start);
	if (map_height == 0)
		return (print_error("Empty map"));
	map_grid = extract_map_lines(lines, map_start, map_height);
	if (!map_grid)
		return (print_error("Failed to extract map"));
	if (!validate_map_chars(map_grid))
	{
		free_string_array(map_grid);
		return (print_error("Invalid map characters"));
	}
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		free_string_array(map_grid);
		return (0);
	}
	game->map->grid = map_grid;
	game->map->height = map_height;
	game->map->width = get_map_width(map_grid);
	if (!normalize_map(game->map))
	{
		free_string_array(map_grid);
		return (print_error("Failed to normalize map"));
	}
	return (1);
}


/*int find_map_start(char **lines)
{
    int     i;
    char    *trimmed;

    i = 0;
    while (lines[i])
    {
        printf("DEBUG MAP: Line %d: [%s]\n", i, lines[i]);  // ADD THIS
        
        trimmed = skip_whitespace(lines[i]);

        if (is_empty_line(trimmed))
        {
            printf("DEBUG MAP: Line %d is empty, skipping\n", i);  // ADD THIS
            i++;
            continue;
        }
        if (starts_with(trimmed, "NO ")
            || starts_with(trimmed, "SO ")
            || starts_with(trimmed, "WE ")
            || starts_with(trimmed, "EA ")
            || starts_with(trimmed, "F ")
            || starts_with(trimmed, "C "))
        {
            printf("DEBUG MAP: Line %d is config, skipping\n", i);  // ADD THIS
            i++;
            continue;
        }
        if (ft_strchr(trimmed, '1') || ft_strchr(trimmed, '0'))
        {
            printf("DEBUG MAP: Line %d is map! Returning %d\n", i, i);  // ADD THIS
            return (i);
        }
        printf("DEBUG MAP: Line %d doesn't match any pattern, returning -1\n", i);  // ADD THIS
        return (-1);
    }
    printf("DEBUG MAP: Reached end of file, no map found\n");  // ADD THIS
    return (-1);
}*/