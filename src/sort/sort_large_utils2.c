/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:31:17 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 18:24:55 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	perform_node_move(t_stack *stack_a, t_stack *stack_b, t_node *top_stack_a_node);
static void	adjust_stack_b(t_stack *stack_a, t_stack *stack_b);

void move_node_to_top(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	t_node	*top_node_stack_a;
	
	top_node_stack_a = NULL;
	rotate_until_on_top_stack(stack_a, node, OPERATION_RA, OPERATION_RRA);
	// Peek at the next node in stack A, which will become the head of stack A after the pop operation
	if (stack_a->head != NULL && stack_a->head->next != NULL)
		top_node_stack_a = stack_a->head->next;
	perform_node_move(stack_a, stack_b, top_node_stack_a);
	adjust_stack_b(stack_a, stack_b);
}

static void	perform_node_move(t_stack *stack_a, t_stack *stack_b, t_node *top_stack_a_node)
{
	t_node	*optimal_spot;

	// Move chosen node to stack b
	pop_and_push(stack_a, stack_b, OPERATION_PB);
	if (top_stack_a_node)
	{
		optimal_spot = find_optimal_pos(stack_b, top_stack_a_node);
		if (optimal_spot)
			rotate_until_on_top_stack(stack_b, optimal_spot, OPERATION_RB, OPERATION_RRB);
	}
}

static void	adjust_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;
	t_node	*largest;

	// After rotation, check if stack_b needs any adjustments
	if (stack_b->size)
	{
		smallest = smallest_node(stack_b);
		largest = largest_node(stack_b);
		// If the top node of stack_a is smaller than the smallest node or larger than the largest node in stack_b
		// then rotate stack_b until the appropriate node (smallest or largest) is on top
		if (stack_a->head != NULL && (stack_a->head->value < smallest->value || stack_a->head->value > largest->value)) {
			if (stack_a->head->value < smallest->value) {
				rotate_until_on_top_stack(stack_b, smallest, OPERATION_RB, OPERATION_RRB);
			} else if (stack_a->head->value > largest->value) {
				rotate_until_on_top_stack(stack_b, largest, OPERATION_RB, OPERATION_RRB);
			}
		}
	}
}
