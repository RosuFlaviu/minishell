/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:28 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:32:29 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * 100);
	while (s[i] && s[i] != ' ' && s[i] != '$')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putstr_and_free(char *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	free(s);
}

char	*find_var(char *envp[], char *s)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	str = NULL;
	n = ft_strlen(s);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], s, n) == 0)
			str = ft_strdup(&envp[i][n + 1]);
		i++;
	}
	return (str);
}

void	verify_string(char *com)
{
	int i;
	int ok;

	ok = 0;
	i = 0;
	while (com[i])
	{
		if (com[i] == 34 || com[i] == 39)
		{
			ft_strcpy(com + i, com + i + 1);
			ok = 1;
		}
		else
			i++;
	}
	if (ok == 0)
		ft_trim(com);
}

void	hand_echo(char *envp[], char *command)
{
	int		i;
	char	*s;

	i = -1;
	if (ft_strlen(command) >= 5)
		i = 4;
	else
	{
		ft_putchar('\n');
		return ;
	}
	verify_string(command);
	while (command[++i])
	{
		if (command[i] == '$')
		{
			s = get_var(command + i + 1);
			ft_putstr_and_free(find_var(envp, s));
			i = i + ft_strlen(s);
		}
		else
			write(1, &command[i], 1);
	}
	write(1, "\n", 1);
}
