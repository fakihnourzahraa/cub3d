/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:08:19 by nour              #+#    #+#             */
/*   Updated: 2025/12/25 16:37:46 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//figure out how the player will be tracked
void	update(t_game *game)
{
	draw_map(game);
}
void	get_image(t_game *game)
{

}
void	calc_steps(t_ray *ray)
{
	if (ray->calc->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->calc->side_dist_x = (ray->game->player->x - ray->map_x)
		* ray->calc->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->calc->side_dist_x = (ray->map_x - ray->game->player->x + 1) * ray->calc->delta_dist_x;
	}
	if (ray->calc->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->calc->side_dist_y = (ray->game->player->y - ray->map_y)
		* ray->calc->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->calc->side_dist_y = (ray->map_y - ray->game->player->y + 1)
		* ray->calc->delta_dist_y;
	}
}
//negative x pointing left, positive pointing right
//then we're calculating the distance to the grid line (to left..to right)
//we need to multiply it by delta as its distance per unit
//so tis y units to ray units
void	init_for_col(t_ray *ray, int i)
{
	t_game 	*game;
	double	camera_x;

	game = ray->game;
	camera_x = ((2 * i) / (double)game->screen_width) - 1;
	ray->calc->ray_dir_x = (game->player->dir_x + game->player->plane_x) * camera_x;
	ray->calc->ray_dir_y = (game->player->dir_y + game->player->plane_y) * camera_x;
	ray->calc->delta_dist_x = fabs(1 / ray->calc->ray_dir_x);
	ray->calc->delta_dist_y = fabs(1 / ray->calc->ray_dir_y);
	calc_steps(ray);
}
//camera x: for ray direction
//if i is 0, itll be -1 (far left)
//if is is middle, i*2 is screen width,.. -1 = 0
//if screen width -1, itll almost be 1 (far right)
//we're basically normalizing i
//delta dist: fabs -> positive double
//how much i have to travel to cross one x/y unit
//this is what we'll use later for drawing and optimization

void	calc_to_draw(t_ray *ray)
{
	t_game *game;
	
	game = ray->game;
	ray->line_height = (int)(game->screen_height / ray->calc->perp_wall_dist);
	ray->draw_start = (ray->line_height * -1) / 2 + (game->screen_height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + game->screen_height / 2;
	if (ray->draw_end >=game->screen_height)
		ray->draw_end = game->screen_height - 1;
}
//line height: the lower the distance the higher the wall (perspective)
//draw start: the center of the screen - the offset 
// = 0 so it wont start off screen
