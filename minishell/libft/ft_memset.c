/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 11:17:30 by frosu             #+#    #+#             */
/*   Updated: 2017/01/28 11:17:31 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*str;

	str = (char *)b;
	if (!str)
		return (NULL);
	if (len == 0)
		return (str);
	counter = 0;
	while (counter < len)
	{
		str[counter] = (char)c;
		counter++;
	}
	return (b);
}
