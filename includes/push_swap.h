/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/11 14:24:21 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h> 
# include "../42c-library/libft_main.h"

typedef enum {
	OPERATION_SA,
	OPERATION_SB,
	OPERATION_PA,
	OPERATION_PB,
	OPERATION_RA,
	OPERATION_RB,
	OPERATION_RRA,
} t_operation;

// Indivdual nodes
typedef struct s_node {
	int				value;
	int				original_pos;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

// Entire stack (used as a "wrapper" for the entire linked list)
typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	int		size;
} t_stack;

// Initializing data into linked list
void	init_stack(t_stack *stack, int argc, char **argv);
void	add_node_to_end(t_stack *stack, int node_value);
bool	is_number(char *str);
bool	is_duplicate(t_stack *stack, int value);

// Sorting
void	start_sorting(t_stack *stack_a, t_stack *stack_b);

// Operations
void	swap(t_stack *stack, t_operation operation);
void	pop_and_push(t_stack *stack_to_pop, t_stack *stack_to_push, t_operation operation);
void	rotate(t_stack *stack, t_operation operation);
void	rev_rotate(t_stack *stack, t_operation operation);

// Error handling
void	display_error_and_exit();

// Print operations
void	print_operation(t_operation operation);

void	print_list(t_node *node); // NOT NEEDED

#endif /* PUSH_SWAP_H */
