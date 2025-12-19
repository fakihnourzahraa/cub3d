/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:26:38 by nfakih            #+#    #+#             */
/*   Updated: 2025/05/26 13:42:17 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhite(char s1, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	trimlen(char *s1, char *set)
{
	int	i;
	int	ans;

	i = 0;
	ans = ft_strlen(s1);
	while (ans >= 1 && iswhite(s1[ans - 1], set))
	{
		ans--;
	}
	while (ans && iswhite(s1[i], set))
	{
		i++;
		ans--;
	}
	return (ans);
}

static void	trimming(char *a, char *s1, char *set, int s)
{
	int	i;

	i = 0;
	while (iswhite(s1[i], set))
	{
		i++;
	}
	while (s)
	{
		*a = s1[i];
		a++;
		i++;
		s--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	char	*a;
	char	*t;

	s = trimlen((char *)s1, (char *)set);
	a = (char *)malloc(s + 1);
	if (!a)
		return (0);
	t = a;
	trimming (a, (char *)s1, (char *)set, s);
	a[s] = '\0';
	return (t);
}
