/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:14:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/24 18:15:43 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		// draw_line(game, i);
		i++;
		free(ray);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
//we're drawing pixel by pixel into the buffer, then putting the buffer
//that way its smoother execution
//to do: put pixel function