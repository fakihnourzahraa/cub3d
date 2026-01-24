/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:35:25 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/24 12:38:30 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_loop(t_game *game)
{
	int	*keys;

	keys = game->keys;
	if (keys[97])
		move_left(game);
	else if (keys[100])
		move_right(game);
	else if (keys[119])
		move_up(game);
	else if (keys[115])
		move_down(game);
	return (0);
}

int	keys(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code < 256)
		game->keys[code] = 1;
	else if (code == 65307)
		escape_game_no_update(game);
	else if (code == 65361)
		rotate_left(game);
	else if (code == 65363)
		rotate_right(game);
	return (0);
}

int	key_release(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code < 256)
		game->keys[code] = 0;
	return (0);
}

t_img	*load_texture(void *mlx, char *path)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->img = mlx_xpm_file_to_image(mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	return (texture);
}

/*int	load_wall_textures(t_game *game)
{
	game->textures->north = load_texture(game->mlx, "./txt/wall.xpm");
	if (!game->textures->north)
		return (0);
	game->textures->south = load_texture(game->mlx, "./txt/wall.xpm");
	if (!game->textures->south)
		return (0);
	game->textures->east = load_texture(game->mlx, "./txt/wall.xpm");
	if (!game->textures->east)
		return (0);
	game->textures->west = load_texture(game->mlx, "./txt/wall.xpm");
	if (!game->textures->west)
		return (0);
	return (1);
}
*/
int load_wall_textures(t_game *game)
{
    game->textures->north = load_texture(game->mlx, 
                                         game->textures->north_path);
    if (!game->textures->north)
        return (0);

    game->textures->south = load_texture(game->mlx, 
                                         game->textures->south_path);
    if (!game->textures->south)
        return (0);

    game->textures->east = load_texture(game->mlx, 
                                        game->textures->east_path);
    if (!game->textures->east)
        return (0);

    game->textures->west = load_texture(game->mlx, 
                                        game->textures->west_path);
    if (!game->textures->west)
        return (0);

    return (1);
}