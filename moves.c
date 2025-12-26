/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:12:07 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/26 16:54:11 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

// void	move_up(t_game *g)
// {
// 	char	t;
// 	double	x;
// 	double	y;

// 	    printf("Before: (%.2f, %.2f) -> After: (%.2f, %.2f)\n", 
//            g->player->x, g->player->y, x, y);
// 	x = g->player->x + (g->player->dir_x * g->move_speed);
//     y = g->player->y + (g->player->dir_y * g->move_speed);
// 	t = g->map->grid[(int)y][(int)x];
// 	printf("Tile at new position: '%c'\n", t);  
// 	if (t == '0')
// 	{
//         g->player->x = x;
//         g->player->y = y;
// 		update(g);
// 	}
// }
void move_up(t_game *g)
{
    char t;
    double x;
    double y;

    // DEBUG: Print what we have BEFORE any calculation
    printf("=== MOVE UP ===\n");
    printf("Player pos: (%.2f, %.2f)\n", g->player->x, g->player->y);
    printf("Direction: (%.2f, %.2f)\n", g->player->dir_x, g->player->dir_y);
    printf("Move speed: %.2f\n", g->move_speed);

    x = g->player->x + (g->player->dir_x * g->move_speed);
    y = g->player->y + (g->player->dir_y * g->move_speed);
    
    printf("Calculated new pos: (%.2f, %.2f)\n", x, y);
    printf("Grid check at [%d][%d]\n", (int)y, (int)x);
    
    t = g->map->grid[(int)y][(int)x];
    printf("Tile value: '%c'\n", t);
    
    if (t == '0')
    {
        g->player->x = x;
        g->player->y = y;
        printf("✓ MOVED!\n");
        update(g);
    }
    else
        printf("✗ BLOCKED\n");
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
void	rotate_left(t_game *g)
{
	double	old_dir;
	double	old_plane;

	old_dir = g->player->dir_x;
	old_plane = g->player->plane_x;
	g->player->dir_x = g->player->dir_x * cos(g->rot_speed)
		- g->player->dir_y * sin(g->rot_speed);
	g->player->dir_y = old_dir * sin(g->rot_speed)
		+ g->player->dir_y * cos(g->rot_speed); 
	g->player->plane_x = g->player->plane_x * cos(g->rot_speed)
		- g->player->plane_y * sin(g->rot_speed);
	g->player->plane_y = old_plane * sin(g->rot_speed)
		+ g->player->plane_y * cos(g->rot_speed);
}
void	rotate_right(t_game *g)
{
	double	old_dir;
	double	old_plane;

	old_dir = g->player->dir_x;
	old_plane = g->player->plane_x;
	g->player->dir_x = g->player->dir_x * cos(-1 * g->rot_speed)
		- g->player->dir_y * sin(-1 * g->rot_speed);
	g->player->dir_y = old_dir * sin(-1 * g->rot_speed)
		+ g->player->dir_y * cos(-1 * g->rot_speed); 
	g->player->plane_x = g->player->plane_x * cos(-1 * g->rot_speed)
		- g->player->plane_y * sin(-1 * g->rot_speed);
	g->player->plane_y = old_plane * sin(-1 * g->rot_speed)
		+ g->player->plane_y * cos (-1 * g->rot_speed);

}
