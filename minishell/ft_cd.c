/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:47 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:32:49 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_perm(char *crd, char *com, char *envp, char *home)
{
	if (com[0] != '/')
	{
		ft_strcpy(crd, envp);
		ft_strcat(crd, "/");
		ft_strcat(crd, com);
	}
	else
		ft_strcpy(crd, com);
	if (com[0] == '~')
	{
		ft_strcpy(crd, home);
		ft_strcat(crd, com + 1);
	}
	if (access(crd, F_OK) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(com);
		ft_putchar('\n');
	}
	else	if (access(crd, R_OK) == -1)
	{
		ft_putstr("cd: permission denied: ");
		ft_putstr(com);
		ft_putchar('\n');
	}
}

void	chdir_param(char *envp, char *crd, char *com, char *home)
{
	int i;
	int n;

	i = 0;
	if (ft_strcmp(com, "/") == 0)
	{
		chdir(com);
		return ;
	}
	if (ft_strcmp(com, "..") == 0)
	{
		ft_strcpy(crd, envp);
		n = ft_strlen(crd) - 1;
		while (n > 0 && crd[n] != '/')
		{
			ft_strcpy(crd + n, crd + n + 1);
			n--;
		}
	}
	else
		check_perm(crd, com, envp, home);
	chdir(crd);
}

void	tilda_relative_path(char **envp, char *com)
{
	char *s;

	s = ft_strjoin(&envp[get_pos(envp, "HOME")][5], com);
	chdir(&envp[get_pos(envp, "HOME")][5]);
	no_space(s);
	chdir(s);
	free(s);
}

void	absolute_path(char *com)
{
	no_space(com);
	chdir("/");
	chdir(com);
}

void	ft_cd(char **envp, char *com, char **cunt)
{
	char crd[1024];

	cunt = cunt + 1 - 1;
	ft_trim(com);
	preliminary_tests(envp);
	if (ft_strcmp((com + 3), "-") == 0)
		chdir(&envp[get_pos(envp, "OLDPWD")][7]);
	else
	{
		if (com[3] == '/')
			absolute_path(com + 3);
		if (com[3] == '~')
			tilda_relative_path(envp, com + 4);
		if (ft_strlen(com) == 2)
			chdir(&envp[get_pos(envp, "HOME")][5]);
		else
			chdir_param(&envp[get_pos(envp, "PWD")][4], crd, com + 3,
				&envp[get_pos(envp, "HOME")][5]);
	}
	getcwd(crd, 1023);
	env_h(envp, "OLDPWD", 0, &envp[get_pos(envp, "PWD")][4]);
	env_h(envp, "PWD", 0, crd);
}
