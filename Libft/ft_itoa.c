/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:45:03 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 15:45:03 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	helper(long n, int len, char *a)
{
	a[len] = '\0';
	if (n < 0)
	{
		n = -n;
		a[0] = '-';
	}
	while (n)
	{
		len--;
		a[len] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*a;
	long	nb;

	nb = (long)n;
	len = getlen(nb);
	a = (char *)malloc(len + 1);
	if (!a)
	{
		return (0);
	}
	if (n == 0)
	{
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	helper(nb, len, a);
	return (a);
}
