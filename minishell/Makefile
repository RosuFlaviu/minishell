# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frosu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/19 11:32:00 by frosu             #+#    #+#              #
#    Updated: 2017/07/19 11:32:01 by frosu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = *.c get_next_line/get_next_line.c

OBJ = command_line.o get_next_line.o main_minishell.o find_exec_com.o \
	  trim.o envp_print.o setenv_func.o unset_punct_ce.o hand_echo.o \
	  ft_cd.o ft_strtttrim.o command_mod.o

INCL = -I minishell.h -I ./libft/libft.h

FLAGS = -Wno-error -Wall -Wextra

all: $(NAME)

$(NAME):
	@echo "Compiling -> -> ->"
	@make -C ./libft
	@gcc $(FLAGS) $(INCL) -c $(SRC)
	@gcc $(OBJ) ./libft/libft.a -o $(NAME)

clean:
	@echo "Clean process"
	@make -C ./libft clean
	@rm -rf $(OBJ)

fclean: clean
	@echo "Fclean process"
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
