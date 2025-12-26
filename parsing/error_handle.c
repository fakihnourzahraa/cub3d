/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:43:51 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/27 00:43:51 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int     print_error(char *message)
{
	write(2, "Error\n", 6);
	if (message)
        write(2, message, ft_strlen(message));
	else
        write(2, "Unknown error", 13);
	write(2, "\n", 1);
	return (0);
}

int     validate_file_access(char *filepath)
{
	int fd;

    if (!filepath)
        return (0);
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (0);
    close(fd);
    return (1);
}



/* .int print_error(char *message):la ektub l error mtl 
invalid file extension */

/* .int validate_file_access(char *filepath):Checks if the file exists,
Prevent crashes from trying to read non-existent files*/