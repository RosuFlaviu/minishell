/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:33:12 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:33:13 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	pid_t	pid;

	(void)ac;
	(void)av;
	while (1)
	{
		pid = fork();
		if (pid == 0)
			command_line(envp, pid);
		if (pid > 0)
			wait(0);
	}
	return (0);
}
