/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:32:10 by frosu             #+#    #+#             */
/*   Updated: 2017/07/19 11:32:11 by frosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

int		get_pos(char **envp, char *to_find);
char	*gimme_com(char *s);
void	command_mod(char *s);
char	*gimme_comish(char *s);
void	preliminary_tests(char **envp);
void	no_space(char *s);
void	ft_trim(char *s);
void	hand_echo(char *envp[], char *command);
void	ft_cd(char **envp, char *com, char **cunt);
void	envp_print(char *envp[]);
void	set_env(char **envp, char *com);
int		env_h(char **envp, char *com, int k, char *de_pus);
char	*ft_strtttrim(char *s);
int		get_next_line(const int fd, char **line);
void	command_line(char **envp, pid_t pid);
void	find_exec_com(char **envp, char *command);
int		unset_env(char *envp[], char *name);
void	unset(char **envp, char *command);
int		go_until_equal(char *s);

#endif
