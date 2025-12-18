/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:00:00 by nfakih            #+#    #+#             */
/*   Updated: 2025/12/18 16:30:32 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"
# include "Libft/libft.h"

// # define SCREEN_WIDTH 1920
// # define SCREEN_HEIGHT 1080
// # define MOVE_SPEED 0.05
// # define ROT_SPEED 0.03
// # define TEX_WIDTH 64
// # define TEX_HEIGHT 64

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;
//planes perpendiculat to direction vector
typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_texture;

typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	int			floor_color;
	int			ceiling_color;
}				t_textures;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	char		**ff_grid;
}				t_map;

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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_textures	textures;
	t_img		img;
	int			screen_width;
	int			screen_height;
}				t_game;

/* ================ PARSING FUNCTIONS ================ */
int				parse_file(t_game *game, char *filename);
int				read_file(char *filename, char ***file_content);
int				parse_texture_line(char *line, t_textures *tex);
int				parse_color_line(char *line, int *color);
int				parse_north_texture(char *line, t_textures *tex);
int				parse_south_texture(char *line, t_textures *tex);
int				parse_west_texture(char *line, t_textures *tex);
int				parse_east_texture(char *line, t_textures *tex);
int				parse_floor_color(char *line, t_textures *tex);
int				parse_ceiling_color(char *line, t_textures *tex);
int				parse_map(char **file, t_map *map, int start_line);
int				extract_map_section(char **file, t_map *map);
int				get_map_dimensions(char **map_lines, t_map *map);

/* ================ VALIDATION FUNCTIONS ================ */
int				validate_map(t_map *map);
int				validate_characters(t_map *map);
int				validate_walls(t_map *map);
int				validate_player(t_map *map, t_player *player);
int				check_closed_map(t_map *map);
void			flood_fill(t_map *map, int x, int y);
void			copy_grid(t_map *map);

/* ================ TEXTURE FUNCTIONS ================ */
int				load_textures(t_game *game);
int				load_texture(void *mlx, t_texture *texture, char *path);
void			get_texture_pixel(t_texture *tex, int x, int y, int *color);
int				create_rgb(int r, int g, int b);
int				parse_rgb(char *str, int *r, int *g, int *b);

/* ================ RAYCASTING FUNCTIONS ================ */
void			raycast(t_game *game);
void			init_ray(t_game *game, t_ray *ray, int x);
void			calculate_step_and_side_dist(t_player *player, t_ray *ray);
void			perform_dda(t_map *map, t_ray *ray);
void			calculate_wall_distance(t_ray *ray);
void			calculate_wall_height(t_ray *ray, int screen_height);

/* ================ RENDERING FUNCTIONS ================ */
void			render_frame(t_game *game);
void			draw_vertical_line(t_game *game, int x, t_ray *ray);
void			draw_ceiling_floor(t_game *game, int x, t_ray *ray);
void			draw_textured_wall(t_game *game, int x, t_ray *ray);
t_texture		*get_wall_texture(t_game *game, t_ray *ray);
void			calculate_texture_x(t_ray *ray, t_texture *tex, t_player *p);
void			put_pixel(t_img *img, int x, int y, int color);

/* ================ PLAYER MOVEMENT ================ */
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
int				check_collision(t_game *game, double new_x, double new_y);

/* ================ EVENT HANDLING ================ */
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				close_game(t_game *game);
int				handle_no_event(t_game *game);

/* ================ INITIALIZATION ================ */
void			init_game(t_game *game);
void			init_player(t_player *player, char direction, int x, int y);
void			init_mlx(t_game *game);
void			init_image(t_game *game);

/* ================ UTILITY FUNCTIONS ================ */
void			error_exit(t_game *game);
void			error_message(void);
void			free_game(t_game *game);
void			free_map(t_map *map);
void			free_textures(t_game *game);
void			free_twod(char **array);
int				is_whitespace(char c);
char			*skip_whitespace(char *str);
int				is_valid_map_char(char c);

#endif