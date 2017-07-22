/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 11:28:51 by frosu             #+#    #+#             */
/*   Updated: 2017/01/28 11:28:51 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	ok;

	i = 0;
	if (little == 0 || *little == 0)
		return ((char*)big);
	while (big[i] != '\0' && big != 0 && *big != 0)
	{
		ok = 1;
		j = 0;
		while (little[j] != '\0' && ok && big[i + j] != '\0')
		{
			if (big[i + j] != little[j])
				ok = 0;
			j++;
		}
		if (big[i + j] == '\0' && little[j] != '\0')
			ok = 0;
		if (ok)
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
