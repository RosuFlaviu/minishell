/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_punct_ce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:33:15 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:33:16 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_line(char **s)
{
	int i;

	i = 0;
	if (!s[i + 1])
		s[i] = 0;
	while (s[i + 1])
	{
		ft_strcpy(s[i], s[i + 1]);
		i++;
	}
	s[i + 1] = 0;
}

int		unset_env(char *envp[], char *name)
{
	int i;

	i = 0;
	ft_strcpy(name, name + 9);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, go_until_equal(envp[i])) == 0)
			delete_line(&envp[i]);
		i++;
	}
	return (1);
}
