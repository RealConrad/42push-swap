# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:26:30 by cwenz             #+#    #+#              #
#    Updated: 2023/06/16 16:04:08 by cwenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the binary executable
NAME				:= push_swap

# Name of the library to be included
LIBFT				:= libft.a

# Compiler and flags
CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra

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
SRC_DIR				:= ./src/

# Source files (.c files)
SRC_FILES			:= main.c
ERROR_FILES			:= error.c
SORT_FILES			:= start_sorting.c sort_small.c sort_medium.c sort_utils.c
OP_SRC_FILES		:= push_pop.c rotate.c swap.c print_operation.c
INIT_SRC_FILES		:= initialize.c initialize_utils.c 

SRC					+= $(addprefix $(OP_DIR), $(OP_SRC_FILES))
SRC					+= $(addprefix $(INIT_DIR), $(INIT_SRC_FILES))
SRC					+= $(addprefix $(ERROR_DIR), $(ERROR_FILES))
SRC					+= $(addprefix $(SORT_DIR), $(SORT_FILES))
SRC					+= $(addprefix $(SRC_DIR), $(SRC_FILES))

# Object files (.o files) generated from the source files
OBJ					:= $(SRC:.c=.o)

# Default target
all: $(NAME)

# Create library and add all object files
$(NAME): $(OBJ)
	@$(C_LIBRARY_MAKE)
	@cp $(C_LIBRARY) .
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	
# Compile src files
$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

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
