# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:26:30 by cwenz             #+#    #+#              #
#    Updated: 2023/05/24 14:26:25 by cwenz            ###   ########.fr        #
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
C_LIBRARY_CLEAN		:= make clean -C 42c-library
C_LIBRARY_FCLEAN	:= make fclean -C 42c-library

# Source files (.c files) 
SRC					:= main.c

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
	$(CC) $(CFLAGS) -c $< -o $@

# Remove all object files
clean:
	@$(C_LIBRARY_CLEAN)
	@$(RM) $(OBJ)
	
# Remove all generated files
fclean: clean
	@$(C_LIBRARY_FCLEAN)
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

# Rule for rebuilding everything
# Important to use $(MAKE) instead of 'make' to pass command line arguments
re: fclean
	$(MAKE) all

# Declare the targets as phony (not representing files)
.PHONY: all clean fclean re
