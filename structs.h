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
*/

/* plane x & plane y
waiperpendicular to direction vector and are the camera planes
plane distance is used to avoid the fish eye/curved look and maintain
the straight line look
*/

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
//side dist x is the distance till the next y line
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
//map x is the current swuare
//step x is the step direction
//hit is a bool
//side = 0 for x
//wall x is the exact hit position on wall for textures
//tex_x is the x coordinate on texture

typedef struct s_img
{
	void		*img;
	char		*addr; //pixed data address
	int			bits_per_pixel; //color depth
	int			line_length; //bytes per line
	int			endian; //byte order
	int			width;
	int			height;
}				t_img;

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
	int			p_x; //starting positions
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