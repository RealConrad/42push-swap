/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:12:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/03 15:56:00 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, t_node *node)
{
	int		distance;
	t_node	*temp;

	distance = 0;
	temp = stack->head;
	if (!temp)
		return (-1);
	while (temp != node)
	{
		distance++;
		temp = temp->next;
	}
	return (distance);
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

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current && current->next != NULL)
	{
		if (current->value > current->next->value)
			return (false); // list is not sorted -> larger value found before smaller value
		current = current->next;
	}
	return (true); // The list is sorted
}
