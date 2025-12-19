/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:41:07 by nfakih            #+#    #+#             */
/*   Updated: 2025/04/21 16:45:09 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	ans;

	i = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		j = 0;
		ans = i;
		while (str[i] == to_find[j] && to_find[j] != '\0' && str[i] != '\0')
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (&str[ans]);
		}
		i = ans + 1;
	}
	return (0);
}
