/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:12:07 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/27 16:30:22 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_left(t_game *g)
{
	char	t;
	double	x;
	double	y;

	x = g->player->x - (g->player->plane_x * g->move_speed);
	y = g->player->y - (g->player->plane_y * g->move_speed);
	t = g->map->grid[(int)y][(int)x];
	if (t == '0')
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
	if (t == '0')
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
	if (t == '0')
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
	if (t == '0')
	{
		g->player->x = x;
		g->player->y = y;
		update(g);
	}
}
