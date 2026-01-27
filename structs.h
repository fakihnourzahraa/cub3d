/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:20:37 by nour              #+#    #+#             */
/*   Updated: 2026/01/27 12:26:25 by nour             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_player		t_player;
typedef struct s_calc		t_calc;
typedef struct s_ray		t_ray;
typedef struct s_img		t_img;
typedef struct s_textures	t_textures;
typedef struct s_map		t_map;
typedef struct s_game		t_game;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

/*
x & y
x y are the exact positions in the map (centered)
changing with moves
*/

/*dir x & dir y:
the directions
-1, 0, 1
changing with rotations
center of vision
*/

/* plane x & plane y
from -0.66 to + 0.66
peripheral vision
helps us decide how to normalize the view
perpendicular to direction vector and are the camera planes
plane distance is used to avoid the fish eye/curved look and maintain
the straight line look
*/
//to do: how the length and angle stay the same rotation matrix math

typedef struct s_calc
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
}	t_calc;
/* ray dirx x & ray dir y
-1.66 to 1.66
the direction the ray is pointing
*/
/* side dist x and & y
distance from ray to next x or y line!
*/
/* delta dist x & y
distance the need to travel to cross one x or y(one grid cell)
based on ray dir x
pythagorean theorm
*/
/* per wall dist
perpendicular distance from player to wall, for fish eye
set when wall is hit
*/
//delta dist x is the distance to travel one grid cell
//perp wall dist is the perpendiculat distance to the wall

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	t_game		*game;
	t_calc		*calc;
}				t_ray;
// everything needed to cast one ray and draw one vertical line
//map x is the grid position
//step x is the step direction, either adding or subtracting 1
//hit is a bool for the wall, stop casting
/* side
0 means vertical wall(ns), 1 horiztonal(ew)
determines which texture
*/
/* line height
wall height, based on screen height and perp wall dist
*/
//wall x is the exact hit position on wall for textures, between 0 and 1
//tex_x is the x coordinate on texture, same as wall x just horizontally

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;
//addr is the fixed data address, gives us direct access
//bits per pixel color depth
//line length bytes per line, needs to be filled by mlx bc of padding
//endian byte order
//width and heigh in pixels

typedef struct s_textures
{
	t_img		*north;
	t_img		*south;
	t_img		*west;
	t_img		*east;
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	int			floor_color;
	int			sky_color;
}				t_textures;
//they could all be the same texture saraha we can decide later

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	char		p;
	int			p_x;
	int			p_y;
	char		**ff_grid;
}				t_map;
// p is player(N/S/W/E), p_x and p_y are those positions
//ff_grid is flood fill grid

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	t_textures	*textures;
	t_img		*img;
	int			screen_width;
	int			screen_height;
	int			keys[256];
	double		move_speed;
	double		rot_speed;
}				t_game;
//includes player, map, textures (includes details), img

#endif