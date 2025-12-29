/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:02:39 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/28 00:02:39 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*extract_texture_path(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	return (ft_strtrim(line + i, "\n"));
}

int	validate_texture_path(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}

int	check_duplicate_texture(char *existing, char *id)
{
	if (existing)
	{
		ft_printf("Error\nDuplicate texture: %s\n", id);
		return (1);
	}
	return (0);
}

int	parse_texture_line(char *line, char **dest, char *id)
{
	char	*path;

	if (check_duplicate_texture(*dest, id))
		return (0);
	path = extract_texture_path(line);
	if (!validate_texture_path(path))
	{
		free(path);
		return (print_error("Invalid texture path"));
	}
	*dest = path;
	return (1);
}

static int	process_texture_line(char *line, t_game *game)
{
	if (starts_with(line, "NO "))
		return (parse_texture_line(line,
				&game->textures->north_path, "NO"));
	if (starts_with(line, "SO "))
		return (parse_texture_line(line,
				&game->textures->south_path, "SO"));
	if (starts_with(line, "WE "))
		return (parse_texture_line(line,
				&game->textures->west_path, "WE"));
	if (starts_with(line, "EA "))
		return (parse_texture_line(line,
				&game->textures->east_path, "EA"));
	return (1);
}

int	parse_textures(char **lines, t_game *game)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (!process_texture_line(lines[i], game))
			return (0);
		i++;
	}
	if (!game->textures->north_path || !game->textures->south_path
		|| !game->textures->west_path || !game->textures->east_path)
		return (print_error("Missing texture configuration"));
	return (1);
}

/*parse texture:hye l main fct lal parsing text laan ht3ml loop ala kl line bl texture
wtshuf shu no3e ize fi NO bt3mle parse wbthte bl north_path ...,wbt3ml
check enu 4 text are found(NO,SO,WE,EA)*/

/*parse_texture_line:hyde bteml extra lal path yane ize ana amle NO ./textures/north.xpm
btkhlye tser ./textures/north.xpm
bteml skip lal space,skip lal identifier,Check duplicate,skip space after ident,extrat la b2e l path*/

/* validate_texture_path: bteml check ize opath valid,ize mnthe bi .xpm,if exist 
(path not null,not empty,end with.xpm,)*/

/* check_duplicate_texture:btmn3 l dup mtl enu ykun ende tnen NO*/

/**extract_texture_path(char *line): Extract path from line  "NO ./textures/north.xpm" btsr "./textures/north.xpm */
