/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:40:17 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/21 17:34:33 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start(t_game *game)
{
	t_map *map = game->map;

	game->ray->map_x = (int)game->player->dir_x;
	game->ray->map_y = (int)game->player->dir_y;
}


double	dda(t_ray *ray, t_game *game)
{
	int	hit;
	hit = 0;
	while (!hit)
	{
		//x is closer so jump to x
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;//vertical wall (NS)
		}
		else{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;//horizontal wall (EW)
		}
		if (game->map->grid[ray->map_y][ray->map_x] == '1')
        	hit = 1;
		calculate_hit(ray, game);
	}
	//here we hit a wall therefore we calculate perp (plane) distance
// 	if (ray->side == 0)  // Hit vertical wall
//     ray->perp_wall_dist = (ray->map_x - player->x + 
//                            (1 - ray->step_x) / 2) / ray->ray_dir_x;
// else                 // Hit horizontal wall
//     ray->perp_wall_dist = (ray->map_y - player->y + 
//                            (1 - ray->step_y) / 2) / ray->ray_dir_y;
	//return distination from wall
}