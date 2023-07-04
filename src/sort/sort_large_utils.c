/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:01:28 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/03 18:31:08 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
