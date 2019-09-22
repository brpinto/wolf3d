# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:04:50 by qbenaroc          #+#    #+#              #
#    Updated: 2019/01/17 18:23:07 by qbenaroc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

HEADER_PATH = ./includes/
SRC_PATH = ./src/
OBJ_PATH = ./obj/

SRC_FILES = ft_strlen.c				\
			ft_strdup.c				\
			ft_strcpy.c				\
			ft_strncpy.c			\
			ft_strcat.c				\
			ft_strncat.c			\
			ft_strlcat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strstr.c				\
			ft_strnstr.c			\
			ft_strcmp.c				\
			ft_strncmp.c			\
			ft_strrev.c				\
			ft_atoi.c				\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_memset.c				\
			ft_bzero.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_memalloc.c			\
			ft_memdel.c				\
			ft_strnew.c				\
			ft_strdel.c				\
			ft_strclr.c				\
			ft_striter.c			\
			ft_striteri.c			\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_strequ.c				\
			ft_strnequ.c			\
			ft_strsub.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_strsplit.c			\
			ft_itoa.c				\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putendl.c			\
			ft_putnbr.c				\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_lstnew.c				\
			ft_lstdelone.c			\
			ft_lstdel.c				\
			ft_lstadd.c				\
			ft_lstiter.c			\
			ft_lstmap.c				\
			ft_islower.c			\
			ft_isupper.c			\
			ft_countcwords.c		\
			ft_strsplit_to_str.c	\
			ft_lstprint.c			\
			ft_lstadd_end.c			\
			ft_lst_size.c			\
			ft_strchar_swap.c		\
			ft_abs.c				\
			ft_ispunct.c			\
			ft_swap.c				\
			ft_strjoin_free.c		\
			ft_tab_new_int.c		\
			get_next_line.c

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@printf "\033[1;33mCompiling $(NAME) \r"

$(NAME): $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
	@ar rc $(NAME) $(OBJ_EXEC)
	@ranlib $(NAME)
	@echo "\n\033[01;34mLibft\t\t\033[0;32m[Compilation done]"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[01;34mLibft\t\t\033[1;31m[.o removed]"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[01;34mLibft\t\t\033[1;31m[Lib removed]"

re: fclean all
