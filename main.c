/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:20:50 by nour              #+#    #+#             */
/*   Updated: 2026/01/26 21:01:28 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        free_game(game);
        exit(1);
    }
    if (!load_wall_textures(game))
    {
        free_game(game);
        exit(1);
    }
    game->win = mlx_new_window(game->mlx, game->screen_width,
            game->screen_height, "cub3d");

    game->img->img = mlx_new_image(game->mlx, game->screen_width,
            game->screen_height);
    game->img->addr = mlx_get_data_addr(game->img->img,
            &game->img->bits_per_pixel, &game->img->line_length,
            &game->img->endian);

    start_player(game);
}

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2)
    {
        print_error("Usage: ./cub3D <map.cub>");
        return (1);
    }
    game = init_game_struct();
    if (!game)
        return (1);

    if (!parse_cub_file(argv[1], game))
    {
        free_game(game);
        return (1);
    }
    init_game(game);
    update(game);
    mlx_hook(game->win, 2, 1, keys, game);
    mlx_hook(game->win, 3, 2, key_release, game);
    mlx_hook(game->win, 17, 0, escape_game_no_update, game);
    mlx_loop_hook(game->mlx, key_loop, game);
    mlx_loop(game->mlx);
    return (0);
}
// key hook doesnt register how long we're pressing for
// 2 -> key is pressed, 3 -> key is released
// 1 key press, 2 key release, 0 no mask needed

