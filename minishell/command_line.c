/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:39 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:38:07 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_matrix(char **to, char **src)
{
	int i;

	i = 0;
	while (src[i][0])
		i++;
	to = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		to[i] = ft_strdup(src[i]);
		i++;
	}
	to[i][0] = '\0';
}

int		commas(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
			return (1);
		i++;
	}
	return (0);
}

void	special_case_for_echo(char *com)
{
	int i;

	i = 0;
	if ((ft_strstr(com, "echo") && !commas(com)))
	{
		com = ft_strtrim(com);
		return ;
	}
	i = i + 1 - 1;
	while (com[i] == '\t')
	{
		if (com[i] == '\t')
			ft_strcpy(com + i, com + i + 1);
		else
			i++;
	}
}

void	command_line(char **envp, pid_t pid)
{
	char *com_line;

	ft_putstr("$>: ");
	ft_putchar(' ');
	get_next_line(0, &com_line);
	special_case_for_echo(com_line);
	if (ft_strcmp("exit", com_line) == 0)
		kill(pid, SIGTERM);
	else
		find_exec_com(envp, com_line);
}
