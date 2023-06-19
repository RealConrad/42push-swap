/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:59:05 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/19 19:36:21 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node_to_top(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	t_node	*smallest;
	t_node	*largest;
	rotate_until_on_top_stack(stack_a, node);
	if (stack_b->size >= 2)
	{
		smallest = smallest_node(stack_b);
		largest = largest_node(stack_b);
		if (node->value < smallest->value)
			rotate_until_on_top_stack(stack_b, smallest);
		else if (node->value > largest->value)
			rotate_until_on_top_stack(stack_b, largest);
	}
	pop_and_push(stack_a, stack_b, OPERATION_PB);
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
