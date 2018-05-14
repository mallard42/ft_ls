# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 12:39:07 by mallard           #+#    #+#              #
#    Updated: 2017/06/21 15:31:04 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE = \033[38;5;105m

GREEN = \033[38;5;82m

RED = \033[38;5;208m

DEFAULT = \x1b[0m

TOOLS = \xU+1F6E0

TRASH = \xU+1F5D1

NAME = ft_ls

P = ./src/

LIBFT = ./libft/libft.a

SRC = $(P)main.c $(P)option.c $(P)dir.c $(P)error.c $(P)option_add.c $(P)tab.c \
	  $(P)path.c $(P)default.c $(P)option_print.c $(P)option_sort.c \
	  $(P)check.c $(P)free.c $(P)opt_l.c $(P)size.c $(P)print.c

OBJ = main.o option.o dir.o error.o option_add.o tab.o path.o default.o \
	  option_print.o option_sort.o check.o free.o opt_l.o size.o print.o

FLAGS = -Werror -Wextra -Wall -g

all : $(NAME) norme

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
	@echo "$(GREEN)clean libft.a $(DEFAULT)"
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re : fclean all

.PHONY : re all norme $(NAME) clean fclean $(LIBFT)
