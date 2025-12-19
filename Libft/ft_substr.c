/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:18:17 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/30 15:24:42 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getalloc(unsigned int start, char const *s, int *b, size_t len)
{
	size_t	alloc;

	if (start >= ft_strlen(s))
	{
		alloc = 0;
		*b = 0;
	}
	else if (ft_strlen(s) >= (len + start))
		alloc = len;
	else
		alloc = ft_strlen(s) - start;
	return (alloc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*a;
	size_t		n;
	char		*r;
	size_t		alloc;
	int			b;

	b = 1;
	alloc = getalloc(start, s, &b, len);
	r = (char *)s;
	n = 0;
	a = (char *)malloc(alloc + 1);
	if (!a)
	{
		return (0);
	}
	while (b && r[start + n] && n < len)
	{
		a[n] = r[start + n];
		n++;
	}
	a[n] = '\0';
	return (a);
}
