/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:57:13 by nour              #+#    #+#             */
/*   Updated: 2026/01/29 20:23:28 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

void	free_texture_img(void *mlx, t_img *texture)
{
	if (!texture)
		return ;
	if (texture->img && mlx)
		mlx_destroy_image(mlx, texture->img);
	free(texture);
}

void	free_textures_struct(void *mlx, t_textures *tex)
{
	if (!tex)
		return ;
	free_texture_img(mlx, tex->north);
	free_texture_img(mlx, tex->south);
	free_texture_img(mlx, tex->west);
	free_texture_img(mlx, tex->east);
	free_texture_img(mlx, tex->gun);
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

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_grid(map->grid);
	free_grid(map->ff_grid);
	free(map);
}

void	free_image(void *mlx, t_img *img)
{
	if (!img)
		return ;
	if (img->img && mlx)
		mlx_destroy_image(mlx, img->img);
	free(img);
}
