/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:57:48 by nour              #+#    #+#             */
/*   Updated: 2025/12/24 14:51:49 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void	set_player_spawn(t_player *player, char spawn_char, int x, int y)
{
	player->x = (double)x + 0.5;
	player->y = (double)y + 0.5;
	if (spawn_char == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (spawn_char == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (spawn_char == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (spawn_char == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}
static char	**create_test_grid(void)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * 9);
	if (!grid)
		return (NULL);
	i = 0;
	grid[i++] = ft_strdup("11111111111111111111");
	grid[i++] = ft_strdup("10000000000000000001");
	grid[i++] = ft_strdup("10000000000000000001");
	grid[i++] = ft_strdup("10000000000000000001");
	grid[i++] = ft_strdup("11111N00000000000001");
	grid[i++] = ft_strdup("10000000000000000001");
	grid[i++] = ft_strdup("10000000000000000001");
	grid[i++] = ft_strdup("11111111111111111111");
	grid[i] = NULL;
	return (grid);
}

/*
** Creates a more complex test map with some walls
** Better for testing raycasting
*/
static char	**create_complex_grid(void)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * 13);
	if (!grid)
		return (NULL);
	i = 0;
	grid[i++] = ft_strdup("1111111111111111111111111");
	grid[i++] = ft_strdup("1000000000110000000000001");
	grid[i++] = ft_strdup("1011000001110000000000001");
	grid[i++] = ft_strdup("1001000000000000000000001");
	grid[i++] = ft_strdup("111111111011000001110000000000001");
	grid[i++] = ft_strdup("100000000011000001110111111111111");
	grid[i++] = ft_strdup("11110111111111011100000010001");
	grid[i++] = ft_strdup("11110111111111011101010010001");
	grid[i++] = ft_strdup("11000000110101011100000010001");
	grid[i++] = ft_strdup("10000N00000000001100000010001");
	grid[i++] = ft_strdup("10000000000000001101010010001");
	grid[i++] = ft_strdup("11000001110101011111011110N0111");
	grid[i++] = ft_strdup("11110111 1110101 101111010001");
	grid[i++] = ft_strdup("11111111 1111111 111111111111");
	grid[i] = NULL;
	return (grid);
}

/*
** Finds the player spawn position in the grid
** Returns 1 if found, 0 if not
*/
static int	find_player_spawn(char **grid, int *spawn_x, 
								int *spawn_y, char *spawn_char)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'N' || grid[y][x] == 'S'
				|| grid[y][x] == 'E' || grid[y][x] == 'W')
			{
				*spawn_x = x;
				*spawn_y = y;
				*spawn_char = grid[y][x];
				grid[y][x] = '0';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Calculates map dimensions from grid
*/
static void	calculate_dimensions(char **grid, int *width, int *height)
{
	int	y;
	int	x;
	int	max_width;

	y = 0;
	max_width = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
			x++;
		if (x > max_width)
			max_width = x;
		y++;
	}
	*width = max_width;
	*height = y;
}

/*
** Loads a fake map for testing
** simple: 0 for complex map, 1 for simple map
*/
t_map	*load_fake_map(int simple)
{
	t_map		*map;
	int			spawn_x;
	int			spawn_y;
	char		spawn_char;

	map = init_map();
	if (!map)
		return (NULL);
	if (simple)
		map->grid = create_test_grid();
	else
		map->grid = create_complex_grid();
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	calculate_dimensions(map->grid, &map->width, &map->height);
	if (!find_player_spawn(map->grid, &spawn_x, &spawn_y, &spawn_char))
	{
		free_map(map);
		return (NULL);
	}
	map->p = spawn_char;
	map->p_x = spawn_x;
	map->p_y = spawn_y;
	return (map);
}

/*
** Creates a complete game with fake map
** Use this for testing execution while parser is being developed
*/
t_game	*create_test_game(int simple_map)
{
	t_game		*game;
	int			spawn_x;
	int			spawn_y;
	char		spawn_char;

	game = init_game_struct();
	if (!game)
		return (NULL);
	free(game->map);
	game->map = load_fake_map(simple_map);
	if (!game->map)
	{
		free_game(game);
		return (NULL);
	}
	spawn_x = game->map->p_x;
	spawn_y = game->map->p_y;
	spawn_char = game->map->p;
	set_player_spawn(game->player, spawn_char, spawn_x, spawn_y);
	if (game->textures)
	{
		game->textures->floor_color = create_rgb(220, 100, 0);
		game->textures->sky_color = create_rgb(135, 206, 235);
	}
	return (game);
}

/*
** Helper function to create RGB color
*/
int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*
** Usage example:
**
** int main(void)
** {
**     t_game *game;
**
**     // Create simple test map
**     game = create_test_game(1);
**     
**     // OR create complex test map
**     // game = create_test_game(0);
**
**     if (!game)
**         return (1);
**
**     // Initialize MLX and start rendering
**     game->mlx = mlx_init();
**     game->win = mlx_new_window(game->mlx, 1920, 1080, "cub3D");
**     game->img->img = mlx_new_image(game->mlx, 1920, 1080);
**     game->img->addr = mlx_get_data_addr(game->img->img, 
**         &game->img->bits_per_pixel,
**         &game->img->line_length, &game->img->endian);
**     
**     // Your rendering code here...
**     // mlx_loop_hook(game->mlx, render_frame, game);
**     // mlx_hook(game->win, 2, 1L<<0, key_press, game);
**     // mlx_hook(game->win, 17, 0, close_game, game);
**     // mlx_loop(game->mlx);
**
**     return (0);
** }
*/