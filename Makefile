# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 19:29:24 by jgoldste          #+#    #+#              #
#    Updated: 2023/08/29 16:04:09 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
LIBRARIES 		=	$(MINILIBX_FLAGS) -L$(LIBFT_DIR) -L$(MINILIBX_DIR) 
INCLUDES		=	-I$(HEADERS_DIR) -I$(LIBFT_HEADER) -I$(MINILIBX_HEADER)

LIBFT_DIR		=	./libft/
LIBFT			=	$(LIBFT_DIR)libft.a
LIBFT_HEADER	=	$(LIBFT_DIR)

MINILIBX_DIR	=	./mini_libx/
MINILIBX		=	$(MINILIBX_DIR)libmlx.a
MINILIBX_HEADER	=	$(MINILIBX_DIR)
MINILIBX_FLAGS	=	-lmlx -lm -lft -framework OpenGL -framework AppKit -framework Cocoa

HEADERS_DIR		=	./include/
HEADERS_LIST	=	cub3d.h	get_next_line.h	constants.h	messages.h	structs.h
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

GNL_DIR			=	gnl/
GNL_LIST		=	get_next_line.c	get_next_line_utils.c
GNL				=	$(addprefix $(GNL_DIR), $(GNL_LIST))

PARSER_DIR		=	parser/
PARSER_LIST		=	parse.c		init.c		read_map.c		parse_map_file.c\
					define_texture.c	define_color.c		define_map.c\
					utils.c		free_utils.c	free_utils_struct.c		error.c
PARSER			=	$(addprefix $(PARSER_DIR), $(PARSER_LIST))

GAME_DIR		=	game/
GAME_LIST		=	game.c
GAME			=	$(addprefix $(GAME_DIR), $(GAME_LIST))

SOURCES_DIR		=	./src/
SOURCES_LIST	=	cub3d.c\
					$(GNL)	$(PARSER)	$(GAME)
SOURCES			=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR		=	./object/
OBJECTS_LIST	=	$(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS			=	$(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

MKDIR			=	mkdir -p

YELLOW			=	"\033[1;33m"
GREEN			=	"\033[1;32m"
END				=	"\033[0m"

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo $(GREEN) "\n\tCub3d is compiled\n" ${END}

$(OBJECTS_DIR):
	$(MKDIR) $(OBJECTS_DIR)
	$(MKDIR) $(OBJECTS_DIR)$(GNL_DIR)
	$(MKDIR) $(OBJECTS_DIR)$(PARSER_DIR)
	$(MKDIR) $(OBJECTS_DIR)$(GAME_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -g -c -o $@ $< -MD

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -sC $(MINILIBX_DIR)

clean:
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MINILIBX_DIR) clean
	rm -rf $(OBJECTS_DIR)
	@echo $(YELLOW) "\n\tCub3d 'clean' status: DONE\n" ${END}


fclean: clean
	rm -rf $(MINILIBX)
	rm -rf $(LIBFT)
	rm -rf $(NAME)
	@echo $(YELLOW) "\n\tCub3d 'fclean' status: DONE\n" ${END}

re: fclean all
