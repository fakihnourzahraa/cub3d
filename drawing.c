/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:08:19 by nour              #+#    #+#             */
/*   Updated: 2025/12/24 14:51:49 by nfakih           ###   ########.fr       */
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
		update(g);
	}
}
void	move_right(t_game *g)
{
	char	t;

	if (g->map->p_y + 1 >= g->map->width)
		return ;
	t = g->map->grid[g->map->p_x][g->map->p_y + 1];
	if (t == '0')
	{
		g->map->grid[g->map->p_x][g->map->p_y] = '0';
		g->map->grid[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y++;
		update(g);
	}
	
}
void	move_up(t_game *g)
{
		char	t;

	if (g->map->p_x - 1 < 0)
		return ;
	t = g->map->grid[g->map->p_x - 1][g->map->p_y];
	if (t == '0')
	{
		g->map->grid[g->map->p_x][g->map->p_y] = '0';
		g->map->grid[g->map->p_x - 1][g->map->p_y] = 'P';
		g->map->p_x--;
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

//figure out how the player will be tracked
void	update(t_game *game)
{
	draw_map(game);
}
void	get_image(t_game *game)
{

}
void	draw_line(t_game *game, int i)
{
	//to do
}
void	draw_map(t_game *game)
{
	int		i;
	t_ray	*ray;

	i = 0;
	while (i < game->screen_width)
	{
		ray = init_ray();
		//to do: init ray for column
		//to do: calculate camera x and ray direction
		dda(ray, game);
		//to do: calculate wall height
		//to do: calculate draw limits (start end end), for draw line
		// draw_line(game, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
//we're drawing pixel by pixel into the buffer, then putting the buffer
//that way its smoother execution
//to do: put pixel function