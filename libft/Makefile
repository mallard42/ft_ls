# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 12:22:19 by mallard           #+#    #+#              #
#    Updated: 2017/03/20 14:57:05 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CYAN = \x1b[36m
GREEN = \x1b[32m
DEFAULT = \x1b[0m

FLAGS = -Werror -Wall -Wextra

S = ./src/

SRC = $(S)ft_memset.c $(S)ft_bzero.c $(S)ft_memcpy.c $(S)ft_memccpy.c \
	  $(S)ft_memmove.c $(S)ft_memchr.c $(S)ft_memcmp.c $(S)ft_strlen.c \
	  $(S)ft_strdup.c $(S)ft_strcpy.c $(S)ft_strcat.c $(S)ft_strncat.c \
	  $(S)ft_strchr.c $(S)ft_strnstr.c $(S)ft_strcmp.c $(S)ft_strncmp.c \
	  $(S)ft_atoi.c $(S)ft_isalpha.c $(S)ft_isdigit.c $(S)ft_isalnum.c \
	  $(S)ft_isascii.c $(S)ft_isprint.c $(S)ft_toupper.c $(S)ft_tolower.c \
	  $(S)ft_strncpy.c $(S)ft_strrchr.c $(S)ft_strstr.c $(S)ft_strlcat.c \
	  $(S)ft_putchar.c $(S)ft_putstr.c $(S)ft_putchar_fd.c $(S)ft_putstr_fd.c \
	  $(S)ft_strclr.c $(S)ft_putendl.c $(S)ft_putendl_fd.c $(S)ft_strequ.c \
	  $(S)ft_strnequ.c $(S)ft_putnbr.c $(S)ft_putnbr_fd.c $(S)ft_memalloc.c \
	  $(S)ft_strnew.c $(S)ft_memdel.c $(S)ft_strdel.c $(S)ft_striter.c \
	  $(S)ft_striteri.c $(S)ft_strmap.c $(S)ft_strmapi.c $(S)ft_strsub.c \
	  $(S)ft_strjoin.c $(S)ft_strtrim.c $(S)ft_itoa.c $(S)ft_abs.c \
	  $(S)ft_intlen.c $(S)ft_strsplit.c $(S)ft_lstnew.c $(S)ft_lstdelone.c \
	  $(S)ft_lstadd.c $(S)ft_lstdel.c $(S)ft_lstiter.c $(S)ft_lstmap.c \
	  $(S)ft_lstaddend.c $(S)ft_swap.c $(S)ft_foreach.c $(S)ft_strcount.c \
	  $(S)ft_lstsize.c $(S)ft_strjoin_f.c

OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o \
	  ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o \
	  ft_strncat.o ft_strchr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
	  ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	  ft_toupper.o ft_tolower.o ft_strncpy.o ft_strrchr.o ft_strstr.o \
	  ft_strlcat.o ft_putchar.o ft_putstr.o ft_putchar_fd.o ft_putstr_fd.o \
	  ft_strclr.o ft_putendl.o ft_putendl_fd.o ft_strequ.o ft_strnequ.o \
	  ft_putnbr.o ft_putnbr_fd.o ft_memalloc.o ft_strnew.o ft_memdel.o \
	  ft_strdel.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o \
	  ft_strsub.o ft_strjoin.o ft_strtrim.o ft_itoa.o ft_abs.o ft_intlen.o \
	  ft_strsplit.o ft_lstnew.o ft_lstdelone.o ft_lstadd.o ft_lstdel.o \
	  ft_lstiter.o ft_lstmap.o ft_lstaddend.o ft_swap.o ft_foreach.o \
	  ft_strcount.o ft_lstsize.o ft_strjoin_f.o

.PHONY : all $(NAME) clean fclean re

all: $(NAME)

$(NAME):
	@echo "$(CYAN)build libft$(DEFAULT)"
	@gcc -c -I $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@echo "$(GREEN)clean libft's object$(DEFAULT)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(GREEN)clean $(NAME)$(DEFAULT)"
	@rm -f $(NAME)

re: fclean all
