/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:32 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:32:33 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		go_until_equal(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

int		env_h(char **envp, char *com, int k, char *de_pus)
{
	int i;
	int j;
	int ok;

	ok = 0;
	j = 0;
	i = 0;
	while (envp[i])
	{
		j = go_until_equal(envp[i]);
		j = j + 1 - 1;
		if (ft_strncmp(envp[i], com + k, j) == 0)
		{
			ok = 1;
			ft_strcpy(&envp[i][j + 1], de_pus);
		}
		i++;
	}
	return (ok);
}

void	insert_in_envp(char *envp[], char *insert)
{
	int i;

	i = 0;
	while (envp[i])
		i++;
	envp[i] = ft_strdup(insert + 7);
	no_space(envp[i]);
	envp[i + 1] = 0;
}

void	set_env(char **envp, char *com)
{
	char	de_pus[100];
	int		insert;

	ft_strcpy(de_pus, com + go_until_equal(com) + 1);
	insert = env_h(envp, com, 7, de_pus);
	if (insert == 0)
		insert_in_envp(envp, com);
}
