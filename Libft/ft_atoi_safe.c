/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 00:40:02 by miwehbe           #+#    #+#             */
/*   Updated: 2025/12/31 00:40:02 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	validate_and_convert(char *str, int i, long *num)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		*num = *num * 10 + (str[i] - '0');
		if (*num > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_safe(char *str, int *result)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!validate_and_convert(str, i, &num))
		return (0);
	*result = (int)(num * sign);
	return (1);
}
