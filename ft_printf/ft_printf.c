/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:12:08 by nfakih            #+#    #+#             */
/*   Updated: 2025/06/10 12:36:18 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isspecifier(char *str)
{
	if (str && (str[1] == 'c' || str[1] == 's' || str[1] == 'p'
			|| str[1] == 'd' || str[1] == 'i' || str[1] == 'u'
			|| str[1] == 'x' || str[1] == 'X' || str[1] == '%'))
	{
		return (1);
	}
	return (0);
}

int	getcount(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && isspecifier(&str[i]))
		{
			count++;
			i++;
		}
		else if (str[i] == '%')
			return (-1);
		i++;
	}
	return (count);
}

int	putnums(va_list list, char **str)
{
	unsigned int	a;
	char			*pt;

	if (**str == 'u' || **str == 'x' || **str == 'X')
	{
		a = va_arg(list, unsigned int);
		if (**str == 'u')
			return (ft_putnbr_base_un(a, "0123456789", 0));
		if (**str == 'x')
			return (ft_putnbr_base_un(a, "0123456789abcdef", 0));
		if (**str == 'X')
			return (ft_putnbr_base_un(a, "0123456789ABCDEF", 0));
	}
	if (**str == 's')
	{
		pt = va_arg(list, char *);
		return (ft_putstr_fd(pt, 1));
	}
	if (**str == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	putspec(va_list list, char **str)
{
	void	*ptr;
	int		a;

	(*str)++;
	if (**str == 'u' || **str == 'x' || **str == 'X' || **str == 's'
		|| **str == '%')
		return (putnums(list, str));
	if (**str == 'p')
	{
		ptr = va_arg(list, void *);
		if (!ptr)
			return (write(1, "(nil)", 5));
		ft_putstr_fd("0x", 1);
		return (2 + ft_putnbr_base_un((unsigned long)ptr,
				"0123456789abcdef", 0));
	}
	a = va_arg(list, int);
	if (**str == 'd' || **str == 'i' )
	{
		return (ft_putnbr_base(a, "0123456789", 0));
	}
	if (**str == 'c')
		return (ft_putchar_fd((char)a, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	char	*st;
	int		a;

	a = 0;
	st = (char *)str;
	if (getcount((char *)str) < 0)
		return (-1);
	va_start(list, str);
	while (*st)
	{
		if (*st == '%' && isspecifier(st))
		{
			a += putspec(list, &st);
		}
		else
		{
			a += ft_putchar_fd(*st, 1);
		}
		st++;
	}
	va_end(list);
	return (a);
}
//get count is is the number of specifier, returns -1 if theres an invalid %