/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:28:53 by nour              #+#    #+#             */
/*   Updated: 2025/12/27 16:30:34 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotate_right(t_game *g)
{
	double	old_dir;
	double	old_plane;

	old_dir = g->player->dir_x;
	old_plane = g->player->plane_x;
	g->player->dir_x = g->player->dir_x * cos(g->rot_speed) - g->player->dir_y
		* sin(g->rot_speed);
	g->player->dir_y = old_dir * sin(g->rot_speed) + g->player->dir_y
		* cos(g->rot_speed);
	g->player->plane_x = g->player->plane_x * cos(g->rot_speed)
		- g->player->plane_y * sin(g->rot_speed);
	g->player->plane_y = old_plane * sin(g->rot_speed) + g->player->plane_y
		* cos(g->rot_speed);
	update(g);
}

void	rotate_left(t_game *g)
{
	double	old_dir;
	double	old_plane;

	old_dir = g->player->dir_x;
	old_plane = g->player->plane_x;
	g->player->dir_x = g->player->dir_x * cos(-1 * g->rot_speed)
		- g->player->dir_y * sin(-1 * g->rot_speed);
	g->player->dir_y = old_dir * sin(-1 * g->rot_speed) + g->player->dir_y
		* cos(-1 * g->rot_speed);
	g->player->plane_x = g->player->plane_x * cos(-1 * g->rot_speed)
		- g->player->plane_y * sin(-1 * g->rot_speed);
	g->player->plane_y = old_plane * sin(-1 * g->rot_speed)
		+ g->player->plane_y * cos(-1 * g->rot_speed);
	update(g);
}
