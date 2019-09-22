# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brpinto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 09:43:06 by brpinto           #+#    #+#              #
#    Updated: 2019/07/30 13:35:32 by brpinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

	# Flags

FLAGS = -Wall -Wextra -Werror
CC = gcc
MFLAGS = -framework OpenGL -framework Appkit

	# Paths

HEADER_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIB_PATH = ./libft/
SDL_PATH = ./libraries/SDL2-2.0.9/include/SDL2
H_SDL = ./libraries/includes/

# Files

SRC_FILES = $(shell ls $(SRC_PATH) | grep -E ".+\.c")

LIB_FILE = libft.a

LIBS = SDL2 SDL2_image SDL2_mixer SDL2_ttf
LIB_DIR = ./libraries/SDL2-2.0.9/lib

SDL_FILE = -L ./libraries/SDL2-2.0.9/lib -lSDL2
#SDL_IMAGE = -L ./libraries/SDL2-2.0.9/lib -lSDL2_image
#SDL_MIXER = -I $(SDL_PATH) $(SDL_FILE) -L ./libraries/SDL2-2.0.9/lib -lSDL2_mixer
#SDL_TTF = -L ./libraries/SDL2-2.0.9/lib -lSDL2_ttf
#FREETYPE = -L ./libraries/freetype-2.10.0/lib -lfreetype

ABSOLUTE_DIR = $(shell pwd)

LIB = $(addprefix $(LIB_PATH), $(LIB_FILE))

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

	# Rules

all: lib $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH)includes/ -I $(SDL_PATH) -I $(H_SDL)
	@echo "\033[1;34mCompilation of \033[36m$(notdir $<)\033[0m \033[32mdone\033[1;0m"

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
	@$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) -o $@ -I $(HEADER_PATH) $(SDL_FILE) $(MFLAGS)
	@echo "\033[1;32mwolf3d\t\t\033[0;32m[Compilation done]\033[1;0m"

#$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
#	@$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) -o $@ -I $(HEADER_PATH) $(SDL_FILE) $(SDL_IMAGE) $(SDL_MIXER) $(SDL_TTF) $(FREETYPE) $(MFLAGS)
#	@echo "\033[1;32mwolf3d\t\t\033[0;32m[Compilation done]\033[1;0m"

lib: sdl

sdl:
	@if [ ! -d "./libraries/SDL2-2.0.9/lib/" ]; then \
		mkdir -p libraries && \
		mkdir -p ./libraries/includes && \
		echo "\033[1;33mCompiling SDL \r" && \
		tar -xf ./tar/SDL2-2.0.9.tar.gz -C ./libraries && \
		cd ./libraries/SDL2-2.0.9 && \
		./configure --prefix=$(shell pwd)/libraries/SDL2-2.0.9 >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) install >> /tmp/wolf3d.log 2>&1 && \
		echo "\033[01;34mSDL\t\t\033[0;32m[Compilation done]"; \
	else \
		echo "sdl: nothing to be done"; \
	fi;

image: ttf
	@if [ ! -d "./libraries/SDL2_image-2.0.4" ]; then \
		mkdir -p libraries && \
		echo "\033[1;33mCompiling SDL_image \r" && \
		tar -xf ./tar/SDL2_image-2.0.4.tar.gz -C ./libraries && \
		cd ./libraries/SDL2-2.0.9/build && \
		$(ABSOLUTE_DIR)/libraries/SDL2_image-2.0.4/configure --prefix=$(shell pwd)/libraries/SDL2-2.0.9 >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) install >> /tmp/wolf3d.log 2>&1 && \
		echo "\033[01;34mSDL_image\t\033[0;32m[Compilation done]"; \
		cp $(ABSOLUTE_DIR)/libraries/SDL2_image-2.0.4/SDL_image.h $(ABSOLUTE_DIR)/libraries/includes/; \
	else \
		echo "sdl_image: nothing to be done"; \
	fi;

freetype: mixer
	@if [ ! -d "./libraries/freetype-2.10.0/lib/" ]; then \
		mkdir -p libraries && \
		echo "\033[1;33mCompiling Freetype \r" && \
		tar -xf ./tar/freetype-2.9.tar.gz -C ./libraries && \
		cd ./libraries/freetype-2.9 && \
		./configure --prefix=$(shell pwd)/libraries/freetype-2.10.0 >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) install >> /tmp/wolf3d.log 2>&1 && \
		echo "\033[01;34mFreetype\t\033[0;32m[Compilation done]"; \
	else \
		echo "freetype: nothing to be done"; \
	fi;

ttf: freetype
	@if [ ! -d "./libraries/SDL2_ttf-2.0.15" ]; then \
		mkdir -p libraries && \
		echo "\033[1;33mCompiling SDL_ttf \r" && \
		tar -xf ./tar/SDL2_ttf-2.0.15.tar.gz -C ./libraries && \
		cd ./libraries/SDL2-2.0.9/build && \
		FT2_CONFIG=$(shell pwd)/libraries/freetype-2.10.0/bin/freetype-config $(ABSOLUTE_DIR)/libraries/SDL2_ttf-2.0.15/configure --prefix=$(shell pwd)/libraries/SDL2-2.0.9 >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) install >> /tmp/wolf3d.log 2>&1 && \
		echo "\033[01;34mSDL_ttf\t\t\033[0;32m[Compilation done]"; \
		cp $(ABSOLUTE_DIR)/libraries/SDL2_ttf-2.0.15/SDL_ttf.h $(ABSOLUTE_DIR)/libraries/includes/; \
	else \
		echo "sdl_ttf: nothing to be done"; \
	fi;

mixer:
	@if [ ! -d "./libraries/SDL2_mixer-2.0.4" ]; then \
		mkdir -p libraries && \
		echo "\033[1;33mCompiling SDL_mixer \r" && \
		tar -xf ./tar/SDL2_mixer-2.0.4.tar.gz -C ./libraries && \
		cd ./libraries/SDL2-2.0.9/build && \
		$(ABSOLUTE_DIR)/libraries/SDL2_mixer-2.0.4/configure --prefix=$(shell pwd)/libraries/SDL2-2.0.9 >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) >> /tmp/wolf3d.log 2>&1 && \
		$(MAKE) install >> /tmp/wolf3d.log 2>&1 && \
		echo "\033[01;34mSDL_mixer\t\033[0;32m[Compilation done]"; \
		cp $(ABSOLUTE_DIR)/libraries/SDL2_mixer-2.0.4/SDL_mixer.h $(ABSOLUTE_DIR)/libraries/includes/; \
	else \
		echo "sdl_mixer: nothing to be done"; \
	fi;

clean:
	@make clean -C libft/
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[1;32mwolf3d\t\t\033[1;31m[.o removed]\033[1;0m"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo "\033[1;32mwolf3d\t\t\033[1;31m[Executable removed]\033[1;0m"

fcleansdl:
	@rm -rf libraries
	@echo "\033[1;32mSDL\t\t\033[1;31m[sources files removed]\033[1;0m"

re: fclean all

resdl: fcleansdl all

.PHONY: all clean fclean re sdl image fcleansdl resdl lib
