/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:12:07 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/27 13:12:32 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	colliding(t_game *g, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (g->map->grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	check_collision(t_game *g, double new_x, double new_y)
{
	double b;

	b = 0.38;
	if (colliding(g, new_x - b, new_y - b))
		return (1);
	if (colliding(g, new_x + b, new_y - b))
		return (1);
	if (colliding(g, new_x - b, new_y + b))
		return (1);
	if (colliding(g, new_x + b, new_y + b))
		return (1);
	return (0);
}

void	move_left(t_game *g)
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
}

void	move_right(t_game *g)
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
}

void	move_up(t_game *g)
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
}

void	move_down(t_game *g)
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
}
