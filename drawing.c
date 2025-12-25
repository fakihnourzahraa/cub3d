/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:14:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/25 16:29:29 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;
    
    // Make sure we're within bounds
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return;
    
    // Calculate offset in the image buffer
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    
    // Write the color (assuming 32-bit color)
    *(unsigned int *)dst = color;
}
void	draw_line(t_ray *ray, int x)
{
	t_game	*game;

	game = ray->game;
    int y;
    
    // Draw ceiling (from top to wall start)
    y = 0;
    while (y < ray->draw_start)
    {
        put_pixel(game->img, x, y, game->textures->sky_color);
        y++;
    }
    
    // Draw wall (from draw_start to draw_end)
    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        // For now, just use a solid color
        // Later you'll add textures here
        int color;
        if (ray->side == 1)  // Make one side darker
            color = 0x808080;  // Gray
        else
            color = 0xFFFFFF;  // White
        
        put_pixel(game->img, x, y, color);
        y++;
    }
    
    // Draw floor (from wall end to bottom)
    y = ray->draw_end;
    while (y < game->screen_height)
    {
        put_pixel(game->img, x, y, game->textures->floor_color);
        y++;
    }	
}
void	draw_map(t_game *game)
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
		free(ray);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
//we're drawing pixel by pixel into the buffer, then putting the buffer
//that way its smoother execution
//to do: put pixel function