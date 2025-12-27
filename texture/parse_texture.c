/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:02:39 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/28 00:02:39 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
int     parse_textures(char **lines, t_game *game)
{}
int     parse_texture_line(char *line, char **texture_path){}
int     validate_texture_identifier(char *line, char *identifier){}
int     check_texture_file_exists(char *path){}
int     all_textures_found(t_textures *textures){} 
 
/*parse texture:hye l main fct lal parsing text laan ht3ml loop ala kl line bl texture
wtshuf shu no3e ize fi NO bt3mle parse wbthte bl north_path ...,wbt3ml
check enu 4 text are found(NO,SO,WE,EA)*/

/*parse_texture_line:hyde bteml extra lal path yane ize ana amle NO ./textures/north.xpm
btkhlye tser ./textures/north.xpm
bteml skip lal space,skip lal identifier,skip space after ident,extrat la b2e l path*/

/* validate_texture_path: bteml check ize opath valid,ize mnthe bi .xpm,if exist 
(path not null,not empty,end with.xpm,)*/

/* check_duplicate_texture:btmn3 l dup mtl enu ykun ende tnen NO*/

/*all_textures_found:bteml check ize 4 text mwjudin north south west east
yani btshuf ize shi wehde null bteml error*/