/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:12:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/20 15:01:42 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
