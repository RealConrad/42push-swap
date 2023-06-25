/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_sort_medium_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:01:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/20 16:44:56 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ORIGINAL FUNCTION:
// void	move_node_to_top(t_stack *stack_a, t_stack *stack_b, t_node *node)
// {
// 	t_node	*smallest;
// 	t_node	*largest;
// 	rotate_until_on_top_stack(stack_a, node);
// 	if (stack_b->size >= 2)
// 	{
// 		smallest = smallest_node(stack_b);
// 		largest = largest_node(stack_b);
// 		if (node->value < smallest->value)
// 			rotate_until_on_top_stack(stack_b, smallest);
// 		else if (node->value > largest->value)
// 			rotate_until_on_top_stack(stack_b, largest);
// 	}
// 	pop_and_push(stack_a, stack_b, OPERATION_PB);
// }

void move_node_to_top(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
    t_node *smallest;
    t_node *largest;
    t_node *optimal_spot;
    t_node *top_node_a = NULL;

    // Rotate until chosen node is on top
    rotate_until_on_top_stack(stack_a, node, OPERATION_RA, OPERATION_RRA);

    // Peek at the next node in stack A, which will become the head of stack A after the pop operation
    if (stack_a->head != NULL && stack_a->head->next != NULL) {
        top_node_a = stack_a->head->next;
    }

    // Move chosen node to stack B
    pop_and_push(stack_a, stack_b, OPERATION_PB);

    // If the stack_a is not empty and has more than one node
    if (top_node_a)
	{
        optimal_spot = find_optimal_pos(stack_b, top_node_a);
        if (optimal_spot) // Check if optimal_spot is not NULL
            rotate_until_on_top_stack(stack_b, optimal_spot, OPERATION_RB, OPERATION_RRB);
    }

    // After the rotation, check if stack_b needs any further adjustments
    if (stack_b->size >= 1) {
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

int	check_from_direction(t_node **node, int chunk_start, int chunk_end, t_direction direction)
{
	int	i;

	i = 0;
	while(*node)
	{
		if ((*node)->id >= chunk_start && (*node)->id <= chunk_end)
			break ;
		if (direction == TOP)
			*node = (*node)->next;
		else if (direction == BOTTOM)
			*node = (*node)->prev;
		i++;
	}
	return (i);
}
t_node	*find_optimal_pos(t_stack *stack, t_node *node)
{
	t_node	*temp;
	
	temp = stack->head;
	while (temp)
	{
		if (temp->next && temp->value < node->value && temp->next->value > node->value)
			return (temp);
		temp = temp->next;
	}
	if (node->value < smallest_node(stack)->value)
		return smallest_node(stack);
	return (largest_node(stack));
}

bool	nodes_in_chunk(t_stack *stack, int chunk_start, int chunk_end)
{
	t_node	*temp_node;
	
	temp_node = stack->head;
	while (temp_node)
	{
		if (temp_node->id >= chunk_start && temp_node->id <= chunk_end)
			return (true);
		temp_node = temp_node->next;
	}
	return (false);
}

void	rotate_until_on_top_stack(t_stack *stack, t_node *node_to_move, t_operation r, t_operation rr)
{
	t_node	*current;
	int		position;
	
	position = 0;
	current = stack->head;
	// calculate the current position of the node in the stack
	while (current != node_to_move && current)
	{
		current = current->next;
		position++;
	}
	while (stack->head != node_to_move)
	{
		if (position <= stack->size / 2)
			rotate(stack, r);
		else
			rev_rotate(stack, rr);
	}
}
