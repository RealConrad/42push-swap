# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:26:30 by cwenz             #+#    #+#              #
#    Updated: 2023/07/09 15:33:15 by cwenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the binary executable
NAME				:= push_swap

# Name of the library to be included
LIBFT				:= libft.a

# Repo URL
REPO				:= https://github.com/RealConrad/42c-library.git

# Compiler and flags
CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra -I./includes

# Archiver flags
AFLAGS				:= ar -rcs

# Command to remove files
RM					:= rm -f

# Path to the C library to be used
C_LIBRARY			:= 42c-library/libft.a

# Commands for building and cleaning the C library
# Make is run in the directory of the library
C_LIBRARY_MAKE		:= make -C 42c-library
C_LIBRARY_FCLEAN	:= make fclean -C 42c-library

# Directories to source files
OP_DIR				:= ./src/operations/
INIT_DIR			:= ./src/initialize/
ERROR_DIR			:= ./src/error/
SORT_DIR			:= ./src/sort/
FREE_DIR			:= ./src/free_memory/
SRC_DIR				:= ./src/

# Source files (.c files)
SRC_FILES			:= main.c
FREE_FILES			:= free_memory.c
ERROR_FILES			:= error.c
SORT_FILES			:= start_sorting.c sort_small.c sort_large.c sort_utils.c sort_large_utils.c sort_large_utils2.c
OP_SRC_FILES		:= push_pop.c rotate.c swap.c print_operation.c
INIT_SRC_FILES		:= initialize.c initialize_utils.c initialize_utils2.c 

SRC					+= $(addprefix $(OP_DIR), $(OP_SRC_FILES))
SRC					+= $(addprefix $(INIT_DIR), $(INIT_SRC_FILES))
SRC					+= $(addprefix $(ERROR_DIR), $(ERROR_FILES))
SRC					+= $(addprefix $(SORT_DIR), $(SORT_FILES))
SRC					+= $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC					+= $(addprefix $(FREE_DIR), $(FREE_FILES))

# Object files (.o files) generated from the source files
OBJ					:= $(SRC:.c=.o)

# Default target
all: clone $(NAME)

# Create library and add all object files
$(NAME): $(SRC)
	@$(C_LIBRARY_MAKE)
	@cp $(C_LIBRARY) .
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

# Clones repo
clone:
	@if [ ! -d "42c-library" ]; then \
		git clone $(REPO); \
	fi

# Remove all object files
clean:
	@$(RM) $(OBJ)

# Remove all generated files
fclean: clean
	@$(C_LIBRARY_FCLEAN)
	@$(RM) $(NAME)

# Rule for rebuilding everything
re: fclean all

# Declare the targets as phony (not representing files)
.PHONY: all clean fclean re
