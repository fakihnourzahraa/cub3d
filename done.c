/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:39:14 by nour              #+#    #+#             */
/*   Updated: 2025/12/19 14:38:45 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(void)
{
	ft_printf("Error\n");
}

void	nothinn(void)
{
	write(1, "", 0);
}


void	intialize(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_message(), nothinn());
	game->w = mlx_new_window(game->mlx, (game->map->width + 1) * 64,
			game->map->height * 64, "cub3d");
	if (!game->w)
		return (error_message(), nothinn());
	get_image(game);
}
int	handle_keypress(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code == 65361)
		move_left(game);
	else if (code == 65363)
		move_right(game);
	else if (code == 65362)
		move_up(game);
	else if (code == 65364)
		move_down(game);
	else if (code == 65307)
		escape_game_no_update(game);
	return (0);
}

int	escape_game(t_game *game)
{
	// update(game);
	// free_twod(game->map->g);
	// free_twod(game->map->ff_grid);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_image(game->mlx, (game)->txt.bg);
	// mlx_destroy_image(game->mlx, (game)->txt.collec);
	// mlx_destroy_image(game->mlx, (game)->txt.exit);
	// mlx_destroy_image(game->mlx, (game)->txt.player);
	// mlx_destroy_image(game->mlx, (game)->txt.wall);
	mlx_destroy_display(game->mlx);
	game->mlx = NULL;
	exit(0);
	return (1);
}
//old ones

// int	parse(t_map *map, int argc, char **argv)
// {
// 	int		fd;
// 	char	**a;

// 	a = NULL;
// 	// map->g = a;
// 	// map->ff_grid = a;
// 	if (argc != 2 || !ft_strstr(argv[1], ".cub"))
// 		return (-1);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1 || !read_and_parse(map, fd, argv[1]))
// 		return (-1);
// 	return (1);
// }

// void	init_game(t_game *game)
// {

// }
int main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	map = malloc(sizeof(t_map));
	// if (parse(map, argc, argv) == -1)
	// {
	// 	if (map->g)
	// 		free_twod(map->g);
	// 	if (map->ff_grid)
	// 		free_twod(map->ff_grid);
	// 	free(map);
	// 	return (error_message(), 0);
	// }
	// mlx_key_hook(game->w, keys, game);
	// mlx_hook(game->w, 17, 0, escape_game_no_update, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1280, 720, "cub3d");
	game->img.img = mlx_new_image(game->mlx, 1280, 720);
	mlx_loop(game->mlx);
}