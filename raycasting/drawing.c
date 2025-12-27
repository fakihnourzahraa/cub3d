/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:14:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/27 16:26:16 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
// were just finding offset and writing the 32 bit color to it

// scratch, just for testing!!!
void	draw_line(t_ray *ray, int x)
{
	t_game	*game;
	int		y;
	int		color;

	game = ray->game;
	if (ray->draw_start >= ray->draw_end)
		return ;
	y = 0;
	while (y < ray->draw_start)
	{
		put_pixel(game->img, x, y, game->textures->sky_color);
		y++;
	}
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		if (ray->side == 1)
			color = 0x808080;
		else
			color = 0xFFFFFF;
		put_pixel(game->img, x, y, color);
		y++;
	}
	y = ray->draw_end;
	while (y < game->screen_height)
	{
		put_pixel(game->img, x, y, game->textures->floor_color);
		y++;
	}
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
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
// we're drawing pixel by pixel into the buffer, then putting the buffer
// that way its smoother execution
// to do: put pixel function