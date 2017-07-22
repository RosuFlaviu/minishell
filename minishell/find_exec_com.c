/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec_com.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:24 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:32:25 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*fuck(char *s, char *com, int from, int to)
{
	char	*str;
	char	*fin;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char*) * (to - from + 2));
	while (from < to && s[from] != ':')
	{
		str[i] = s[from];
		from++;
		i++;
	}
	str[i] = '\0';
	fin = ft_strjoin(str, "/");
	free(str);
	str = ft_strjoin(fin, com);
	return (str);
}

void	no_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			ft_strcpy(s + i, s + i + 1);
		else
			i++;
	}
}

int		try_exec(char **cunt, char **envp, char *str)
{
	int error;

	error = 0;
	no_space(str);
	execve(str, cunt, envp);
	error = errno;
	free(str);
	str = NULL;
	return (error);
}

void	execve_path(char **cunt, char **envp, char *com)
{
	int i;
	int j;
	int asd;

	asd = get_pos(envp, "PATH");
	i = 5;
	preliminary_tests(envp);
	while (envp[asd][i] && envp[asd][i] != '\n')
	{
		j = i;
		while (envp[asd][j] && envp[asd][j] != ':' && envp[asd][j] != '\n')
			j++;
		j++;
		if (try_exec(cunt, envp, fuck(envp[asd], com, i, j)) == 0)
			return ;
		i = j;
	}
	if (execve(com, cunt, envp))
	{
		ft_putstr("zhs: command not found: ");
		ft_putstr(com);
		ft_putchar('\n');
		return ;
	}
}

void	find_exec_com(char **envp, char *command)
{
	char **cunt;
	char *str;
	char *exec;

	cunt = ft_strsplit(command, ' ');
	str = ft_strjoin("/bin/", cunt[0]);
	if (!ft_strcmp(command, "env"))
		envp_print(envp);
	else if (!ft_strncmp("cd", command, 2))
		ft_cd(envp, command, cunt);
	else if (!ft_strncmp("setenv", command, 6))
		set_env(envp, command);
	else if (!ft_strncmp("unsetenv", command, 8))
		unset_env(envp, command);
	else if (!ft_strncmp("echo", command, 4))
		hand_echo(envp, command);
	else if (ft_strncmp("echo", command, 4))
	{
		exec = gimme_comish(command);
		execve_path(cunt, envp, exec);
		free(exec);
	}
}
