/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/25 12:20:07 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h> 
# include <limits.h>
# include "../42c-library/libft_main.h"


int counter; // delete me

typedef enum e_operation {
	OPERATION_SA,
	OPERATION_SB,
	OPERATION_PA,
	OPERATION_PB,
	OPERATION_RA,
	OPERATION_RB,
	OPERATION_RRA,
	OPERATION_RRB,
} t_operation;

typedef enum e_direction {
	TOP, 
	BOTTOM
} t_direction;

// Indivdual nodes
typedef struct s_node {
	int				value;
	int				id;
	int				binary;
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
void	assign_id_and_binary(t_stack *stack);
void	assign_binary_value(t_stack *stack);

// Sorting
void	start_sorting(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b, int num_chunks);

t_node	*smallest_node(t_stack *stack);
t_node	*largest_node(t_stack *stack);
int		get_position(t_stack *stack, t_node *node);

// int		calc_distance_from_top(t_stack *stack, t_node *node);
// int		find_pos(t_stack *stack, int value);
// int		calc_ops(t_stack *stack_a, t_stack *stack_b, t_node *node);
// void	largest_on_top(t_stack *stack);

// OLD:
bool	nodes_in_chunk(t_stack *stack, int chunk_start, int chunk_end);
void	rotate_until_on_top_stack(t_stack *stack, t_node *node_to_move, t_operation r, t_operation rr);
int		check_from_direction(t_node **node, int chunk_start, int chunk_end, t_direction direction);
void	move_node_to_top(t_stack *stack_a, t_stack *stack_b, t_node *node);
t_node	*find_optimal_pos(t_stack *stack, t_node *node);


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
