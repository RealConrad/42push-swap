/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/07 13:57:34 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h> 
# include "../42c-library/libft_main.h"

// Indivdual nodes
typedef struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

// Entire stack
typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	int		size;
} t_stack;

// Initializing data into linked list
void	init_stack(t_stack *stack, int argc, char **argv);
void	handle_multiple_inputs(t_stack *stack, int argc, char **argv);
void	handle_one_input(t_stack *stack, char **argv);

// Sorting
void	start_sorting(t_stack *stack_a, t_stack *stack_b);

// Operations
void	swap(t_stack *stack);
void	pop_and_push(t_stack *stack_to_pop, t_stack *stack_to_push, char stack_name);
void 	ra(t_stack *stack);

// Error handling
void	display_error_and_exit();



void	print_list(t_node *node); // NOT NEEDED

#endif /* PUSH_SWAP_H */
