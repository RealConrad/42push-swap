/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:01:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/05 14:00:33 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks the node from a given direction to see if it falls within
 * 		  the chunk range.
 * @param node A pointer to the node which will be checked.
 * @param chunk_start The start index of the chunk.
 * @param chunk_end The end index of the chunk.
 * @param direction The direction from which the node will be checked from.
 * @return The number of steps it took to find the node within the chunk range,
 * 		   from the given direciton.
 */
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
/**
 * @brief Finds the optimal position in the stack for a given node,
 * 		  based on its value.
 * @param stack The stack in which the optimal position is to be found.
 * @param node The node for which the optimal position is to be found for.
 * @return The node in the stack after which the given node should be
 * 		    ideally placed.
 */
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

/**
 * @brief Checks if there are any nodes within the chunk range
 * 		  based on the nodes id.
 * @param stack The stack in which the nodes are to be checked.
 * @param chunk_start The starting index of the chunk.
 * @param chunk_end The end index of the chunk.
 * @return True if there are nodes within the chunk range, otherwise false.
 */
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

/**
 * @brief Rotates the given stack until the given node is at the top
 * @param stack The stack which needs to be rotated
 * @param node_to_move The node which needs to be moved to the top 
 * 		  of the given stack.
 * @param r The operaiton for forward rotation.
 * @param rr The operation for reverse rotation.
 */
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
