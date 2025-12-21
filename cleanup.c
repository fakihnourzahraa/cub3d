/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:57:13 by nour              #+#    #+#             */
/*   Updated: 2025/12/21 19:01:49 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Frees a 2D array (map grid)
*/
void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

/*
** Frees a single texture image
*/
static void	free_texture_img(void *mlx, t_img *texture)
{
	if (!texture)
		return ;
	if (texture->img && mlx)
		mlx_destroy_image(mlx, texture->img);
	free(texture);
}

/*
** Frees all textures
*/
static void	free_textures_struct(void *mlx, t_textures *tex)
{
	if (!tex)
		return ;
	free_texture_img(mlx, tex->north);
	free_texture_img(mlx, tex->south);
	free_texture_img(mlx, tex->west);
	free_texture_img(mlx, tex->east);
	if (tex->north_path)
		free(tex->north_path);
	if (tex->south_path)
		free(tex->south_path);
	if (tex->west_path)
		free(tex->west_path);
	if (tex->east_path)
		free(tex->east_path);
	free(tex);
}

/*
** Frees the map structure
*/
void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_grid(map->grid);
	free_grid(map->ff_grid);
	free(map);
}

/*
** Frees the image structure
*/
static void	free_image(void *mlx, t_img *img)
{
	if (!img)
		return ;
	if (img->img && mlx)
		mlx_destroy_image(mlx, img->img);
	free(img);
}

/*
** Frees the entire game structure
*/
void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->textures)
		free_textures_struct(game->mlx, game->textures);
	if (game->map)
		free_map(game->map);
	free_image(game->mlx, game->img);
	free(game->player);
	free(game->ray);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

/*
** Error cleanup - frees everything and exits with error message
*/
// void	error_exit(t_game *game)
// {
// 	ft_putendl_fd("Error", 2);
// 	free_game(game);
// 	exit(1);
// }
void	error_message(void)
{
	ft_printf("Error\n");
}