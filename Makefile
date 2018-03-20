# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvinogra <vvinogra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 16:41:32 by vvinogra          #+#    #+#              #
#    Updated: 2018/03/20 16:19:31 by vvinogra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = gcc

SRC = main.c parsemap.c solution.c image.c hook.c move.c init.c \
	tools.c music.c floor.c shot_gun.c

LIB_SRC = $(shell find libft | fgrep ".c")

OBJ = $(SRC:.c=.o)

INCLUDES = -I Frameworks/SDL2_mixer.framework/Versions/A/Headers \
			-I Frameworks/SDL2.framework/Versions/A/Headers \
			-F Frameworks/

FRAMEWORK = -framework SDL2_mixer \
			-framework SDL2 \
			-F Frameworks/ \

HEADER = libft/includes -I minilibx_macos

HEADER_RELATION = wolf.h libft/includes/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB_SRC) $(OBJ)
	@make -C minilibx_macos
	@make -C libft
	@$(CC) -o $(NAME) $(FRAMEWORK) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit $(OBJ) -L libft -lft
	@echo "Compilation finished: ./$(NAME) maps/map_example1.txt"
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 Frameworks/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)

%.o: %.c $(HEADER_RELATION)
	@$(CC) -c $(FLAGS) -o $@ $< -I $(HEADER) $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "Object files deleted: $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@echo "Executable file deleted: libft/libft.a"
	@echo "Executable file deleted: $(NAME)"

re: fclean all
