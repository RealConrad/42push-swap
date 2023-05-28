/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/05/28 18:23:21 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // Remove
# include <stdlib.h>
# include "../42c-library/libft_main.h"

// Indivdual nodes
typedef struct s_node {
	int				value;
	struct s_node	*next;
} t_node;

// Entire stack
typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
} t_stack;

// Initializing data into linked list
void init_stack(t_stack *stack, int argc, char **argv);

// Error handling
void error_message();

void print_list(t_node *node); // NOT NEEDED

#endif /* PUSH_SWAP_H */
