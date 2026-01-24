/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:34:15 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/24 12:01:37 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int parse_cub_file(char *filename, t_game *game)
{
    char **lines;
    
    if (!validate_file_extension(filename))
        return (print_error("Invalid file extension"));

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
 
    if (validate_player(game->map))
    {
        free_string_array(lines);
        return (0);
    }
    if (!validate_map_closed(game->map))
    {
        free_string_array(lines);
        return (print_error("Map is not closed by walls"));
    }
    
    free_string_array(lines);
    return (1);
}

char **fill_lines(int fd, int lines_count)
{
    char	**lines;
    char	*line;
    int		i;

    lines = malloc(sizeof(char *) * (lines_count + 1));
    if (!lines)
        return (NULL);
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
        lines[i++] = line;
    lines[i] = NULL;
    return (lines);
}

char **read_entire_file(char *filename)
{
    int fd;
    int lines_count;
    char **lines;

    lines_count = count_file_lines(filename);
    if (lines_count <= 0)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    lines = fill_lines(fd, lines_count);
    close(fd);
    return (lines);
}

int     validate_file_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strcmp(filename + len - 4, ".cub") == 0)
		return (1);
	return (0);
}

/*int parse_cub_file(char *filename, t_game *game): bthud file as input ,bt3ml check ize
mnthe b .cub 1 valid,o error,find length,check if at least 5 char
*/

/*char **read_entire_file(char *filename):take file ,open it ,read it,store each line in line(gnl)
read .cub file and store all lines in memory as a char ** array, so parser can process it later
*/

/*int     validate_file_extension(char *filename):its is the main one
*/