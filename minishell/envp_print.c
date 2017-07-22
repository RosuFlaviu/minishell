/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:04 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:32:05 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envp_print(char *envp[])
{
	int i;

	i = 0;
	while (envp[i])
	{
		ft_putstr(envp[i++]);
		ft_putchar('\n');
	}
}

int		get_pos(char **envp, char *to_find)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (envp[i])
	{
		j = go_until_equal(envp[i]);
		j = j + 1 - 1;
		if (ft_strncmp(envp[i], to_find, j) == 0)
			return (i);
		i++;
	}
	return (-1);
}
