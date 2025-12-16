/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:20:50 by nour              #+#    #+#             */
/*   Updated: 2025/12/16 17:34:19 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse(t_map *map, int argc, char **argv)
{
	int		fd;
	char	**a;

	a = NULL;
	// map->g = a;
	// map->ff_grid = a;
	if (argc != 2 || !ft_strstr(argv[1], ".cub"))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !read_and_parse(map, fd, argv[1]))
		return (-1);
	return (1);
}
int main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	map = malloc(sizeof(t_map));
	if (parse(map, argc, argv) == -1)
	{
		if (map->g)
			free_twod(map->g);
		if (map->ff_grid)
			free_twod(map->ff_grid);
		free(map);
		return (error_message(), 0);
	}
	mlx_key_hook(game->w, keys, game);
	mlx_hook(game->w, 17, 0, escape_game_no_update, game);
	mlx_loop(game->mlx);
}

