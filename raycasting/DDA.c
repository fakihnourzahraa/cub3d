/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:40:17 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/27 15:34:10 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double wall_hit(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->calc->perp_wall_dist = ((ray->map_x - game->player->x + (1 - ray->step_x) / 2) / ray->calc->ray_dir_x);
	else
		ray->calc->perp_wall_dist = ((ray->map_y - game->player->y + (1 - ray->step_y) / 2) / ray->calc->ray_dir_y);
	return (ray->calc->perp_wall_dist);
}
// map_x - pos_x how far the wall is
// 1-step_x /2 offset correction
// ray dir x makes it perpendicular
// to do: calculate step x step side dist x and side dist y before loop

double dda(t_ray *ray, t_game *game)
{
	int hit;

	hit = 0;
	while (!hit)
	{
		//		x is closer so jump to x
		if (ray->calc->side_dist_x < ray->calc->side_dist_y)
		{
			ray->calc->side_dist_x += ray->calc->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; // NS
		}
		else
		{
			ray->calc->side_dist_y += ray->calc->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; // EW
		}
		if (game->map->grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	return (wall_hit(ray, game));
}
// here we hit a wall therefore we calculate perp (plane) distance
// return distination from wall
