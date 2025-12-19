/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:32:13 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/26 12:08:32 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			j;
	size_t			z;

	j = ft_strlen((char *)src);
	z = 0;
	if (size == 0)
		return (j);
	while (size - 1 > z && src[z] != '\0')
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = '\0';
	return (j);
}
