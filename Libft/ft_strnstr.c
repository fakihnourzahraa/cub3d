/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:41:07 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/21 12:02:30 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*helper(const char *big, const char *little, int ans, size_t len)
{
	int		i;
	int		j;
	size_t	r;

	i = 0;
	r = 0;
	while (big[i] != '\0' && r < len)
	{
		j = 0;
		ans = i;
		r = i;
		while (r < len && big[i] == little[j] && little[j] != '\0')
		{
			i++;
			j++;
			r++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[ans]);
		}
		i = ans + 1;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	return (helper(big, little, 0, len));
}
