/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nour <nour@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:00:00 by nfakih            #+#    #+#             */
/*   Updated: 2026/01/27 11:23:50 by nour             ###   ########.fr       */
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
# include "structs.h"

char		*skip_whitespace(char *str);
t_game		*init_game_struct(void);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		free_game(t_game *game);
void		free_map(t_map *map);
double		dda(t_ray *ray, t_game *game);
void		start_player(t_game *game);
t_map		*init_map(void);
t_textures	*init_textures(void);
t_player	*init_player(void);
t_ray		*init_ray(t_game *game);
t_img		*init_image(t_game *game);
void		init_for_col(t_ray *ray, int i);
void		update(t_game *game);
void		calc_to_draw(t_ray *ray);
void		put_pixel(t_img *img, int x, int y, int color);
void		init_game(t_game *game);
t_game		*init_game_struct(void);
t_player	*init_player(void);
t_map		*init_map(void);
void		error_message(void);
void		free_game(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		rotate_left(t_game *game);
void		rotate_right(t_game *game);
int			keys(int code, void *p);
int			escape_game_no_update(t_game *game);

int			key_loop(t_game *game);
int			keys(int code, void *p);
int			key_release(int code, void *p);
void		free_grid(char **grid);
void		free_texture_img(void *mlx, t_img *texture);
void		free_textures_struct(void *mlx, t_textures *tex);
void		free_map(t_map *map);
void		free_image(void *mlx, t_img *img);

char		*skip_whitespace(char *str);
int			is_empty_line(char *line);
int			count_lines(char **lines);
void		free_string_array(char **arr);
int			parse_cub_file(char *filename, t_game *game);
char		**read_entire_file(char *filename);
int			validate_file_extension(char *filename);
int			print_error(char *message);
int			validate_file_access(char *filepath);
int			count_file_lines(char *filename);
char		**fill_lines(int fd, int lines_count);
int			is_whitespace(char c);
int			starts_with(char *str, char *prefix);
void		error_exit(char *message, t_game *game);
void		cleanup_parsing(t_game *game);
void		identify_line_type(char *line, int line_num);
void		process_lines(char **lines);

int			parse_textures(char **lines, t_game *game);
int			parse_texture_line(char *line, char **dest, char *id);
int			validate_texture_path(char *path);
int			check_duplicate_texture(char *existing, char *id);
char		*extract_texture_path(char *line);

char		*extract_rgb_string(char *line);
int			parse_rgb_values(char *rgb_str, int *r, int *g, int *b);
int			rgb_to_int(int r, int g, int b);
int			parse_one_color(char *line, int *dest, char *id);
int			parse_colors(char **lines, t_game *game);

int			find_map_start(char **lines);
int			count_map_lines(char **lines, int start);
char		**extract_map_lines(char **lines, int start, int count);
int			parse_maps(char **lines, t_game *game);
int			get_map_width(char **map);
int			is_map_char(char c);
int			validate_map_chars(char **map);
char		*copy_map_line(char *line, int width);
int			normalize_map(t_map *map);
void		copy_grid_for_flood_fill(t_map *map);
void		flood_fill(t_map *map, int x, int y, int *error);
void		free_ff_grid(t_map *map);
int			validate_map_closed(t_map *map);
void		draw_ceiling(t_game *game, int x, int draw_start);
void		draw_floor(t_game *game, int x, int draw_end);
int			calculate_tex_x(t_ray *ray, t_game *game, t_img *texture);
void		draw_textured_wall(t_ray *ray, t_game *game, t_img *texture, int x);
void		draw_solid_wall(t_ray *ray, t_game *game, int x);
int			get_texture_color(t_img *texture, int x, int y);
int			load_wall_textures(t_game *game);
int			find_player(t_map *map, int *count);
int			validate_player_count(int count);
int			parse_cub_file(char *filename, t_game *game);
int			validate_player(t_map *map);
int			complete_parse(char *filename, t_game *game);
int			validate_file(char *filename);
char		**load_file_lines(char *filename);

#endif