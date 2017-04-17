# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 12:39:07 by mallard           #+#    #+#              #
#    Updated: 2017/04/07 16:52:11 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE = \x1b[35m

GREEN = \x1b[32m

RED = \x1b[33m

DEFAULT = \x1b[0m

TOOLS = \xU+1F6E0

TRASH = \xU+1F5D1

NAME = ft_ls

P = ./src/

LIBFT = ./libft/libft.a

SRC = $(P)main.c $(P)option.c $(P)dir.c $(P)error.c $(P)option_add.c $(P)tab.c \
	  $(P)path.c $(P)default.c $(P)option_print.c $(P)option_sort.c \
	  $(P)check.c

OBJ = main.o option.o dir.o error.o option_add.o tab.o path.o default.o \
	  option_print.o option_sort.o check.o

FLAGS = -Werror -Wextra -Wall -g

all : $(NAME)

norme : 
	@echo "$(RED)norme sources et includes$(DEFAULT)"
	@norminette ./include libft/include
	@norminette $(SRC) libft/src

$(LIBFT) :
	@$(MAKE) -C ./libft

$(NAME) : $(LIBFT)
	@echo "$(PURPLE)build $(NAME)$(DEFAULT)"
	@gcc -c $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean :
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ)
	@echo "$(GREEN)clean $(NAME)'s object$(DEFAULT)"

fclean : clean
	@echo "$(GREEN)clean $(NAME)$(DEFAULT)"
	@rm -f $(NAME)

re : fclean all

.PHONY : all $(LIBFT) $(NAME) clean fclean re norme
