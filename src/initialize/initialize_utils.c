/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:24:09 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/19 12:30:01 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_to_end(t_stack *stack, int node_value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		display_error_and_exit();
	new_node->value = node_value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	new_node->original_pos_in_stack = stack->size;
	stack->size++;
	if (!stack->head) // If the stack is not initialized yet
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node; // Add the new node to the end of the list
		stack->tail = new_node; // New node added above becomes the last node
	}
}

bool	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i]) // Check if all characters are digits
	{
		if (!ft_isdigit(str[i]))
			return (false); // return false if not a digit
		i++;
	}
	return (true); // if we got this far, its a number
}

bool	is_duplicate(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (node->value == value)
			return (true);
		node = node->next;
	}
	return (false);
}

void assign_id_values(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*temp_node;

	node = stack->head;
	while (node)
	{
		temp_node = stack->head;
		i = 0;
		while (temp_node)
		{
			if (node->value > temp_node->value)
				i++;
			temp_node = temp_node->next;
		}
		node->id = i;
		node = node->next;
	}
}