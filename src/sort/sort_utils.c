/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:12:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/19 19:37:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_until_on_top_stack(t_stack *stack, t_node *node_to_move)
{
	while (stack->head != node_to_move)
	{
		if (node_to_move->original_pos_in_stack <= stack->size / 2)
			rotate(stack, OPERATION_RA);
		else
			rev_rotate(stack, OPERATION_RRA);
	}
}

t_node	*smallest_node(t_stack *stack)
{
	t_node	*node;
	t_node	*smallest;

	node = stack->head;
	smallest = node;
	while(node)
	{
		if (node->value < smallest->value)
			smallest = node;
		node = node->next;
	}
	return (smallest);
}

t_node	*largest_node(t_stack *stack)
{
	t_node	*node;
	t_node	*largest;

	node = stack->head;
	largest = node;
	while(node)
	{
		if (node->value > largest->value)
			largest = node;
		node = node->next;
	}
	return (largest);
}
