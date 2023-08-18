# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 20:19:15 by jgoldste          #+#    #+#              #
#    Updated: 2023/08/18 20:31:01 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
			ft_isascii.c	ft_isprint.c	ft_strlen.c\
			ft_memset.c		ft_bzero.c		ft_memcpy.c\
			ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
			ft_toupper.c	ft_tolower.c	ft_strchr.c\
			ft_strrchr.c	ft_strncmp.c	ft_memchr.c\
			ft_memcmp.c		ft_strnstr.c	ft_atoi.c\
			ft_calloc.c		ft_strdup.c		ft_substr.c\
			ft_strjoin.c	ft_strtrim.c	ft_split.c\
			ft_itoa.c		ft_strmapi.c	ft_striteri.c\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
			ft_putnbr_fd.c\

HEADER	=	libft.h

OBJ_DIR	=	./object/
OBJS 	=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

MKDIR	=	mkdir -p

YELLOW			=	"\033[1;33m"
GREEN			=	"\033[1;32m"
END				=	"\033[0m"

.PHONY: all clean fclean re

all: $(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	ar rcs $(NAME) $?
	@echo $(GREEN) "\n\tLibft is compiled\n" ${END}

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@ -MD

clean:
	rm -rf $(OBJ_DIR)
	@echo $(YELLOW) "\n\tLibft 'clean' status: DONE\n" ${END}

fclean: clean
	rm -rf $(NAME)
	@echo $(YELLOW) "\n\tLibft 'fclean' status: DONE\n" ${END}

re: fclean all
