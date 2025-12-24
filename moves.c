/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:12:07 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/24 18:21:04 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_left(t_game *g)
{
	char	t;

	if (g->map->p_y - 1 < 0)
		return ;
	t = g->map->grid[g->map->p_x][g->map->p_y - 1];
	if (t == '0')
	{
		g->map->grid[g->map->p_x][g->map->p_y] = '0';
		g->map->grid[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y--;
		g->player->y--;
		update(g);
	}
}
void	move_right(t_game *g)
{
	char	t;
	double	x;
	double	y;

	x = g->player->x + (g->player->dir_x * g->move_speed);
    y = g->player->y + (g->player->dir_y * g->move_speed);
	t = g->map->grid[(int)x - 1][(int)y];
	if (t == '0')
	{
        g->player->x = x;
        g->player->y = y;
		update(g);
	}	
}
//WRONG FIX
void	move_up(t_game *g)
{
	char	t;
	double	x;
	double	y;

	x = g->player->x + (g->player->dir_x * g->move_speed);
    y = g->player->y + (g->player->dir_y * g->move_speed);
	t = g->map->grid[(int)x - 1][(int)y];
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

	if (g->map->p_x + 1 < 0)
		return ;
	t = g->map->grid[g->map->p_x + 1][g->map->p_y];
	if (t == '0')
	{
		g->map->grid[g->map->p_x][g->map->p_y] = '0';
		g->map->grid[g->map->p_x + 1][g->map->p_y] = 'P';
		g->map->p_x++;
		update(g);
	}

}
