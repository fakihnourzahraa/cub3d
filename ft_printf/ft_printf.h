/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:13:28 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/15 17:41:58 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../get_next_line/get_next_line_bonus.h"

int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_base(int nb, char *base, int i);
int		ft_putnbr_base_un(unsigned long nb, char *base, int i);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif