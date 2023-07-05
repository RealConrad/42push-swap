/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:12:02 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/05 12:46:19 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the position of a specific node within a stack.
 * @param stack A pointer to the stack to find the position of the node.
 * @param node A pointer to a node whose position is to be determined.
 * @return An int value representing the index of the node in the given stack.
 * 		   If the stack is empty or the node is not found, it returns -1.
 */
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

/**
 * @brief Finds the node with the smallest value.
 * @param stack A pointer to the stack within which the 
 * 				smallest node is to be determined.
 * @return A pointer to the node with the smallest value within the stack.
 * 		   If the stack is empty it returns NULL.
 */
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

/**
 * @brief Finds the node with the largest value.
 * @param stack A pointer to the stack within which the 
 * 				largest node is to be determined.
 * @return A pointer to the node with the largest value within the stack.
 * 		   If the stack is empty it returns NULL.
 */
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

/**
 * @brief Checks to see if the given stack 
 * 		  is sorted in ascending order.
 * @param stack A pointer to the stack we want to check
 * @return A boolean value, true if the stack is sorted in ascending order, otherwise false
 */
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
