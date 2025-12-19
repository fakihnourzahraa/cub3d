/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:17:12 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/10 12:33:12 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nb, char *base, int i);

int	test(char *base)
{
	int	i;
	int	a;

	i = 0;
	while (base[i])
	{
		a = i + 1;
		while (base[a])
		{
			if (base[a] == base[i])
			{
				return (0);
			}
			a++;
		}
		i++;
	}
	return (1);
}
//makes sure theyre all unique

int	checkbase(char *base)
{
	int	a;

	a = 0;
	while (base[a] != '\0' )
	{
		if (base[a] == '+' || base[a] == '-')
			return (0);
		a++;
	}
	if (a < 2)
	{
		return (0);
	}
	return (a);
}
//checks for base validity and returns length
//invalid if theres +/- or the length is < 2

int	ft_putnbr_base(int nb, char *base, int i)
{
	int	a;

	a = checkbase(base);
	if (a == 0 || test(base) == 0)
		return (0);
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		i = i + ft_putchar_fd('-', 1);
		nb = -nb;
		return (ft_putnbr_base(nb, base, i));
	}
	if (nb >= a)
	{
		i = ft_putnbr_base(nb / a, base, i);
	}
	i = i + ft_putchar_fd(base[nb % a], 1);
	return (i);
}

int	ft_putnbr_base_un(unsigned long nb, char *base, int i)
{
	unsigned long	a;

	a = checkbase(base);
	if (a == 0 || test(base) == 0)
		return (0);
	if (nb >= a)
	{
		i = ft_putnbr_base_un(nb / a, base, i);
	}
	i = i + ft_putchar_fd(base[nb % a], 1);
	return (i);
}
