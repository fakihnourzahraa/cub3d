/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:00:00 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/22 16:44:02 by nour             ###   ########.fr       */
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
//x y are the exact positions in the map
//dir x and y are the directions
//planes perpendicular to direction vector and are the camera planes
//plane distance is used to avoid the fish eye/curved look and maintain the straight line look

typedef	struct s_calc
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x; //distance til next y line
	double		side_dist_y;
	double		delta_dist_x; //distance to travel one grid cell
	double		delta_dist_y;
	double		perp_wall_dist; //prep distance to wall
}	t_calc;

typedef struct s_ray
{
	int			map_x; // current square
	int			map_y;
	int			step_x; //step direction
	int			step_y;
	int			hit; //hit or not
	int			side; //0 = x side, 1 = y side
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x; //exact hit position on wall for textures
	int			tex_x; // x coordinates on texture
	t_game		*game;
	t_calc		*calc;
}				t_ray;
// everything needed to cast one ray and draw one vertical line

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

/* ================ PARSING FUNCTIONS ================ */
int				parse_file(t_game *game, char *filename);
int				read_file(char *filename, char ***file_content);
int				parse_color_line(char *line, int *color);
int				parse_floor_color(char *line, t_textures *tex);
int				parse_sky_color(char *line, t_textures *tex);
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
void			get_texture_pixel(t_img *tex, int x, int y, int *color);
int				create_rgb(int r, int g, int b);
int				parse_rgb(char *str, int *r, int *g, int *b);


/* ================ EVENT HANDLING ================ */
int				close_game(t_game *game);
int				handle_no_event(t_game *game);

/* ================ UTILITY FUNCTIONS ================ */
char			*skip_whitespace(char *str);
int				is_valid_map_char(char c);

t_game			*init_game_struct(void);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			move_up(t_game *game);
void			move_down(t_game *game);
void			free_game(t_game *game);
void			free_map(t_map *map);
double			dda(t_ray *ray, t_game *game);
void			start_player(t_game *game);
t_map			*init_map(void);
t_textures		*init_textures(void);
t_player		*init_player(void);
t_ray			*init_ray(t_game *game);
t_img			*init_image(t_game * game);
t_game			*create_test_game(int simple_map);
void			init_for_col(t_ray *ray, int i);
void			update(t_game *game);
void			calc_to_draw(t_ray *ray);
void			put_pixel(t_img *img, int x, int y, int color);
void			init_game(t_game *game);
t_game			*init_game_struct(void);
t_player		*init_player(void);
t_map			*init_map(void);
void			error_message(void);
void			free_game(t_game *game);
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
int				keys(int code, void *p);
int				escape_game_no_update(t_game *game);

int		key_loop(t_game *game);
int		keys(int code, void *p);
int		key_release(int code, void *p);
void	free_grid(char **grid);
void	free_texture_img(void *mlx, t_img *texture);
void	free_textures_struct(void *mlx, t_textures *tex);
void	free_map(t_map *map);
void	free_image(void *mlx, t_img *img);

/* ================ MIRA PARSING FUNCTIONS ================ */
char    *skip_whitespace(char *str);
int     is_empty_line(char *line);
int     count_lines(char **lines);
void    free_string_array(char **arr);
int     parse_cub_file(char *filename, t_game *game);
char    **read_entire_file(char *filename);
int     validate_file_extension(char *filename);
int     print_error(char *message);
int     validate_file_access(char *filepath);
int		count_file_lines(char *filename);
char 	**fill_lines(int fd, int lines_count);
int     is_whitespace(char c);
int		starts_with(char *str, char *prefix);
void    error_exit(char *message, t_game *game);  
void    cleanup_parsing(t_game *game);
void	identify_line_type(char *line, int line_num);
void	process_lines(char **lines);

int		parse_textures(char **lines, t_game *game);
int		parse_texture_line(char *line,char **dest, char *id);
int 	validate_texture_path(char *path);
int		check_duplicate_texture(char *existing, char *id);
char	*extract_texture_path(char *line);

char    *extract_rgb_string(char *line);
int     parse_rgb_values(char *rgb_str, int *r, int *g, int *b);
int     rgb_to_int(int r, int g, int b);
int     parse_one_color(char *line, int *dest, char *id);
int     parse_colors(char **lines, t_game *game);

int		find_map_start(char **lines);
int 	count_map_lines(char **lines, int start);
char	**extract_map_lines(char **lines, int start, int count);
int 	parse_maps(char **lines, t_game *game);
int		get_map_width(char **map);
int		is_map_char(char c);
int		validate_map_chars(char **map);
char	*copy_map_line(char *line, int width);
int		normalize_map(t_map *map);


void	draw_ceiling(t_game *game, int x, int draw_start);
void	draw_floor(t_game *game, int x, int draw_end);
int		calculate_tex_x(t_ray *ray, t_game *game, t_img *texture);
void	draw_textured_wall(t_ray *ray, t_game *game, t_img *texture, int x);
void	draw_solid_wall(t_ray *ray, t_game *game, int x);
int		get_texture_color(t_img *texture, int x, int y);
int		load_wall_textures(t_game *game);
#endif