/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:43:51 by miwehbe           #+#    #+#             */
/*   Updated: 2026/01/23 16:38:53 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	print_error(char *message)
{
	write(2, "Error\n", 6);
	if (message)
		write(2, message, ft_strlen(message));
	else
		write(2, "Unknown error", 13);
	write(2, "\n", 1);
	return (0);
}

int	validate_file_access(char *filepath)
{
	int	fd;

	if (!filepath)
		return (0);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
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

void	error_exit(char *message, t_game *game)
{
	write(2, "Error\n", 6);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	cleanup_parsing(game);
	exit(1);
}

void	cleanup_parsing(t_game *game)
{
	if (!game)
		return ;
	if (game->map && game->map->grid)
		free_string_array(game->map->grid);
}

/* .int print_error(char *message):la ektub l error mtl 
invalid file extension */

/* .int validate_file_access(char *filepath):Checks if the file exists,and can be open
Prevent crashes from trying to read non-existent files*/

/*void error_exit(char *message, t_game *game):used Free all allocated memory 
in game structure*/

/*void cleanup_parsing(t_game *game):used to free map if alloc*/