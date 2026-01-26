/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:35:29 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/26 23:35:29 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char    *skip_whitespace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (&str[i]);

}

int     is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && 
            line[i] != '\n' && line[i] != '\r')
            return (0);
        i++;
    }
	return (1);

}

int     count_lines(char **lines)
{
	int	count;

	count = 0;
	if (!lines)
		return (0);
	while (lines[count])
		count++;
	return (count);
}

void    free_string_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_file_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

/* .char *skip_whitespace(char *str):used bcz .cub files can have 
spaces before identifiers yani "         NO./...XPM" so it handlke it*/

/* .int is_empty_line(char *line) :used bcz .cub files can have blank 
lines between sections ,returns 1 if empty, 0 if it has actual content*/

/* .int count_lines(char **lines) :used bcz btkhud array of string and count it
char **lines = {"NO ./path1","SO ./path2","F 220,100,0",NULL };
muhme laan need to know how many lines read from file and to know array size*/

/* .void free_string_array(char **arr) : used for free array leaks yane*/