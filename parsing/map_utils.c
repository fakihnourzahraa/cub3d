/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 00:47:22 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/31 00:47:22 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int  get_map_width(char **map)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);

}
int  is_map_char(char c)
{
	if (c == '0' || c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	if (c == ' ')
		return (1);
	 if (c == '\n' || c == '\r')
        return (1);
	return (0);
}

int  validate_map_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_map_char(map[i][j]))
				return (print_error("Invalid map character"));
			j++;
		}
		i++;
	}
	return (1);
}

char *copy_map_line(char *line, int width)
{
	char	*new_line;
	int		i;
	int		len;

	len = ft_strlen(line);
	new_line = malloc(sizeof(char) * (width + 1));
	if (!new_line)
		return (NULL);

	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}

	while (i < width)
	{
		new_line[i] = ' ';
		i++;
	}

	new_line[i] = '\0';
	return (new_line);
}

int  normalize_map(t_map *map)
{
	int		i;
	int		max_width;
	char	*new_line;
	int		current_length;

	if (!map || !map->grid)
		return (0);
	max_width = get_map_width(map->grid);
	map->width = max_width;

	i = 0;
	while (map->grid[i])
	{
		current_length = ft_strlen(map->grid[i]);
		if (current_length < max_width)
		{
			new_line = copy_map_line(map->grid[i], max_width);
			if (!new_line)
				return (0);
			free(map->grid[i]);
			map->grid[i] = new_line;
		}
		i++;
	}
	return (1);
}

/*char *copy_map_line(char *line, int width):btkhli lint klun nfs ltul mn khilel ene t3be l
width be2e space laan raycasting mtwak3a rect */
/*int  is_map_char(char c):bteml check ize lcahr masmuh ykun bl map (0,1,n,s,e,w,space)*/

/*int  get_map_width(char **map):bttl3 length la atwal line bl map*/