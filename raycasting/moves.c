/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:12:07 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/30 00:07:43 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_left(t_game *g, bool glide)
{
	char	t;
	double	x;
	double	y;

	x = g->player->x - (g->player->plane_x * g->move_speed);
	y = g->player->y - (g->player->plane_y * g->move_speed);
	t = g->map->grid[(int)y][(int)x];
	if (t == '0' && !check_collision(g, x, y))
	{
		g->player->x = x;
		g->player->y = y;
		update(g);
	}
	else if (!glide)
	{
		move_up(g, true);
	}
}

void	move_right(t_game *g, bool glide)
{
	char	t;
	double	x;
	double	y;

	x = g->player->x + (g->player->plane_x * g->move_speed);
	y = g->player->y + (g->player->plane_y * g->move_speed);
	t = g->map->grid[(int)y][(int)x];
	if (t == '0' && !check_collision(g, x, y))
	{
		g->player->x = x;
		g->player->y = y;
		update(g);
	}
	else if (!glide)
	{
		move_up(g, true);
	}
}

void	move_up(t_game *g, bool glide)
{
	char	t;
	double	x;
	double	y;

	x = g->player->x + (g->player->dir_x * g->move_speed);
	y = g->player->y + (g->player->dir_y * g->move_speed);
	t = g->map->grid[(int)y][(int)x];
	if (t == '0' && !check_collision(g, x, y) && !check_collision(g, x, y))
	{
		g->player->x = x;
		g->player->y = y;
		update(g);
	}
	else if (!glide)
		move_right(g, true);
}

void	move_down(t_game *g, bool glide)
{
	char	t;
	double	x;
	double	y;

	x = g->player->x - (g->player->dir_x * g->move_speed);
	y = g->player->y - (g->player->dir_y * g->move_speed);
	t = g->map->grid[(int)y][(int)x];
	if (t == '0' && !check_collision(g, x, y))
	{
		g->player->x = x;
		g->player->y = y;
		update(g);
	}
	else if (!glide)
		move_left(g, true);
}

void	update(t_game *game)
{
	int		i;
	t_ray	*ray;

	i = 0;
	while (i < game->screen_width)
	{
		ray = init_ray(game);
		init_for_col(ray, i);
		dda(ray, game);
		calc_to_draw(ray);
		draw_line(ray, i);
		i++;
		free(ray->calc);
		free(ray);
	}
	draw_gun(game, game->textures->gun);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
// we're drawing pixel by pixel into the buffer, then putting the buffer
// that way its smoother execution
