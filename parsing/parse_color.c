/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:56:04 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/29 11:56:04 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ***********.*************************************************************** */

#include "../cub3D.h"

char	*extract_rgb_string(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	return (ft_strtrim(line + i, "\t\n\r"));
}

int	parse_rgb_values(char *rgb_str, int *r, int *g, int *b)
{
	char	**parts;

	parts = ft_split(rgb_str, ',');
	if (!parts || count_lines(parts) != 3)
	{
		print_error("invalid it should be only 3 values");
		free_string_array(parts);
		return (0);
	}
	if (!ft_atoi_safe(parts[0], r)
		|| !ft_atoi_safe(parts[1], g)
		|| !ft_atoi_safe(parts[2], b))
	{
		free_string_array(parts);
		return (0);
	}
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
	{
		free_string_array(parts);
		return (0);
	}
	free_string_array(parts);
	return (1);
}

int	parse_one_color(char *line, int *dest, char *id)
{
	char	*rgb_str;
	int		r;
	int		g;
	int		b;

	(void)id;
	if (*dest != -1)
		return (print_error("Duplicate color definition"));
	rgb_str = extract_rgb_string(line);
	if (!rgb_str)
		return (0);
	if (!parse_rgb_values(rgb_str, &r, &g, &b))
	{
		free(rgb_str);
		//return(0);
		return (print_error("Invalid RGB values (must be 0-255)"));
	}
	*dest = rgb_to_int(r, g, b);
	free(rgb_str);
	return (1);
}

static int	process_color_line(char *line, t_game *game)
{
	char	*trimmed;
	(void)line;
	trimmed = skip_whitespace(line);
	if (starts_with(trimmed, "F "))
		return (parse_one_color(trimmed,
				&game->textures->floor_color, "F"));
	if (starts_with(trimmed, "C "))
		return (parse_one_color(trimmed,
				&game->textures->sky_color, "C"));
	return (1);
}

int	parse_colors(char **lines, t_game *game)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (!process_color_line(lines[i], game))
			return (0);
		i++;
	}
	if (game->textures->floor_color == -1
		|| game->textures->sky_color == -1)
		return (print_error("Missing color configuration (F/C)"));
	return (1);
}

/*char	*extract_rgb_string(char *line):hon bas am 
nmshe la baad F wn2t3 space
wbtrdle yehe mn dun newline*/

/*int	parse_rgb_values(char *rgb_str, int *r, int *g, int *b):hon ana 
bde eml validate enu hne ben 0 wl 255 ,wbde et2kd enu hne anjd 3 integer
r,g ,b la kel wehd wbst3ml split wbhet seperator huwe , laan 255,120,20 
fa ha efsle bl , {255,120,20,NULL},,,,count_line bt3dle ede fi bl array*/

/*int	parse_one_color(char *line, int *dest, char *id):btkhud
line bteml rgb,validate the nbr,
convert to int,check dupli*/

/*int	parse_colors(char **lines, t_game *game):finds F and C lines, parses 
their RGB values, stores them safely, prevents duplicates,
 and errors if anything is missing or invalid.*/
