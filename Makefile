# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:26:30 by cwenz             #+#    #+#              #
#    Updated: 2023/05/24 13:04:42 by cwenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of library
NAME				:= push_swap
LIBFT				:= libft.a

# Compiler and flags
CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra
AFLAGS				:= ar -rcs
RM					:= rm -f
C_LIBRARY			:= 42c-library/libft.a 

# C Library commands
C_LIBRARY_MAKE		:= make -C 42c-library
C_LIBRARY_CLEAN		:= make clean -C 42c-library
C_LIBRARY_FCLEAN	:= make fclean -C 42c-library

# Source files (.c files)
SRC					:= main.c

# Object files
OBJ					:= $(SRC:.c=.o)

# Starting point
all: $(NAME)

# Create library and add all object files
$(NAME): $(OBJ)
	@$(C_LIBRARY_MAKE)
	@cp $(C_LIBRARY) .
	@$(AFLAGS) $< $(LIBFT) -o $@
	
# Compile src files
$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) $<

# Remove all object files
clean:
	@$(C_LIBRARY_CLEAN)
	@$(RM) (OBJ)
	
# Remove library and clean
fclean: clean
	@$(C_LIBRARY_FCLEAN)
	@$(RM) $(NAME)

# Recreates the entire library and removes object files
#--------------------------------------------------------------------------#
# Better practice to write $(MAKE) all as if --jobs option enabled		   #
# it could build fclean and all at the same time and could cause undefined #
# behaviour (e.g. all depends on fclean finishing first,                   #
# as parallel execution doesn't guarantee any order)					   #
#--------------------------------------------------------------------------#
re: fclean
	$(MAKE) all

# Tells make that these are commands and not file names
.PHONY: all clean fclean re
