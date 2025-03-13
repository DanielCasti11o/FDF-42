# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 19:24:02 by dacastil          #+#    #+#              #
#    Updated: 2025/03/13 19:23:20 by dacastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./minilibx-linux #-fsanitize=address
LDFLAGS =  -L./minilibx-linux -lmlx -lX11 -lXext -lm
EXEC = fdf
RM = rm -f
SRS_DIR = ./Srcs
INCLUDE_DIR = ./Include

SRS = $(wildcard $(SRS_DIR)/*.c)
OBJ = $(SRS:.c=.o)
INCLUDE = $(wildcard $(INCLUDE_DIR)*.h) ./minilibx-linux/mlx.h

GREEN = \033[0;32m
RED = \033[0;31m
WHITE=\033[0;97m

all: $(EXEC)

$(EXEC): $(OBJ)
	@ echo "$(GREEN) Generating objects..."
	@ $(CC) $(OBJ) -o $(EXEC) $(LDFLAGS) > /dev/null 2>&1
		@echo ""
	@echo "$(RED)        ^"
	@echo "$(RED)       / \\"
	@echo "$(RED)      /   \\"
	@echo "$(RED)     /     \\"
	@echo "$(RED)    /       \\"
	@echo "$(RED)   /         \\"
	@echo "$(RED)  /           \\"
	@echo "$(RED) /_____________\\           ✦         "
	@echo "$(WHITE) |[]---------[]|               "
	@echo "$(WHITE) |[]---------[]|        ✦✦✦✦✦✦✦     "
	@echo "$(WHITE) |[]---------[]|       ---------    "
	@echo "$(WHITE) |[]---------[]|       | F D F |    "
	@echo "$(WHITE) |[]---------[]|       ---------    "
	@echo "$(WHITE) |[]---------[]|       ✦ ✦ ✦ ✦ ✦    "
	@echo "$(WHITE) |[]---------[]|          "
	@echo "$(WHITE) |[]---------[]|         ✦ ✦ ✦      "
	@echo "$(WHITE) |[]---------[]|               "
	@echo "$(WHITE) |[]---------[]|               "
	@echo "$(WHITE) |[]---------[]|       ✦ ✦ ✦ ✦ ✦    "
	@echo "$(WHITE) |[]---------[]|          "
	@echo "$(WHITE) |[]---------[]|           ✦        "
	@echo "$(WHITE) |[]---------[]|       ✦ ✦ ✦ ✦ ✦    "
	@echo "$(WHITE) |[]---------[]|         "
	@echo "$(WHITE) |[]---------[]|         ✦ ✦ ✦      "
	@echo "$(WHITE) |[]---------[]|       ✦ ✦ ✦ ✦ ✦    "
	@echo "$(WHITE) |[]---------[]|                    "
	@echo "$(WHITE)  \]---------[]/       ✦ ✦ ✦ ✦ ✦    "
	@echo "$(WHITE)   \\_________/"
	@echo "$(RED)     | | | |         ✦  𝓓𝓐𝓒𝓐𝓢𝓣𝓘𝓛  ✦"
	@echo "$(RED)     | | | |        ✦  <-------->  ✦"


%.o: %.c $(INCLUDE)
	@ echo "$(GREEN) Compiling files..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@ echo "$(RED) Cleaning objects..."
	@ $(RM) $(OBJ) > /dev/null 2>&1

fclean:
	@ echo "$(RED) Cleaning all..."
	@ $(RM) $(OBJ) $(EXEC) > /dev/null 2>&1

re: fclean $(EXEC)

.PHONY: all clean fclean re
