/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:55:10 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/26 12:08:58 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	z;

	i = ft_strlen((char *)dest);
	j = ft_strlen((char *)src);
	z = 0;
	if (i >= size)
	{
		return (size + j);
	}
	while (size - i - 1 > z && src[z] != '\0')
	{
		dest[i + z] = src[z];
		z++;
	}
	if (i + z < size)
	{
		dest[i + z] = '\0';
	}
	return (i + j);
}
