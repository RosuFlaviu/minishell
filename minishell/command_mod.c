/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:33:00 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:33:01 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	preliminary_tests(char **envp)
{
	if (get_pos(envp, "HOME") == -1 || get_pos(envp, "PWD") == -1
			|| get_pos(envp, "PATH") == -1)
	{
		ft_putstr("ENV IS NOT SET YOU CUNT!\n");
		exit(-1);
	}
}

char	*gimme_comish(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i] != ' ')
		i++;
	while (s[i])
		ft_strcpy(s + i, s + i + 1);
	return (s);
}

char	*gimme_com(char *s)
{
	int		i;
	int		j;
	char	*str;

	str = (char*)malloc(sizeof(char*) * 100);
	i = 0;
	j = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i])
	{
		if (s[i] == '-')
		{
			while (s[i] && s[i] != ' ')
				i++;
			while (s[i] && (s[i] == ' ' || s[i] == '\t'))
				i++;
		}
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	command_mod(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i] != ' ')
		i++;
	while (s[i])
		ft_strcpy(s + i, s + i + 1);
}
