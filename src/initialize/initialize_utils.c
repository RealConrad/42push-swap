/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:24:09 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 17:09:25 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Adds a new node to the end of the stack.
 * 		  If the stack is not initialized yet, the new node becomes
 * 		  the head and tail, otherwise the node becomes the tail.
 * @param stack A pointer to the stack to which the node will be added.
 * @param node_value The int value to be stored in the new node.
 */
void	add_node_to_end(t_stack *stack, int node_value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node)); // Allocate memory for new node
	if (!new_node) // If allocaiton failed, cleanup and exit
		free_and_exit(stack, FAIL);
	// Initialize new node with given node_value and set next pointer to NULL
	new_node->value = node_value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	stack->size++; // Increase suze if stacj
	if (!stack->head) // If the stack is not initialized yet (first time funciton called)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		// If stack is already initialized, append new node to the end of the stack
		stack->tail->next = new_node; // Make the current tail point to the new node
		stack->tail = new_node; // New node is now last node (tail)
	}
}

/**
 * @brief Checks if the value is a valid input.
 * 		  Valid inputs are ints within the range INT_MAX/INT_MIN,
 * 		  non-duplicates within the given stack and are only numeric.
 * @param stack A pointer to the stack to check if there are any
 * 				duplicates.
 * @param value The long value to check if its valid input.
 * @param str The string representation of the value to be checked
 * 		  if its numeric.
 * @return If its a valid input, returns true, else returns false
 */
bool	is_valid_input(t_stack *stack, long value, char *str)
{
	if (value > INT_MAX || value < INT_MIN) // check for integer overflow
		return (false);
	// Checks if the value is a duplicate or if the string is not a numeric value
	if (is_duplicate(stack, (int) value) || !is_number(str)) // typecast back to int as we only want ints
		return (false);
	return (true); // If none of the above checks fail, its a valid input
}

/**
 * @brief Checks if the given string represents a numeric value,
 * 		   allowing for an optional leading '+' or '-' sign.
 * @param str The string to check
 * @return Returns true if the string exclusively contains 
 * 		   numeric characters, else returns false.
 */
bool	is_number(char *str)
{
	int	i;

	i = 0;
	// Skip minus or plus signs if there are any
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i]) // Iterate through the entire string
	{
		// If char is not a digit, return false
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true); // If we got this far, it's a number
}

/**
 * @brief Checks if the given value is already present in the given stack.
 * @param stack The stack to check if the value already exists
 * @param value The int value to check if it exists in the given stack
 * @return Returns true if the value is found in the stack,
 * 		   indicating there are duplicates, 
 * 		   otherwise returns false if no value found.
 */
bool	is_duplicate(t_stack *stack, int value)
{
	t_node	*node;

	node = stack->head; // Create a temp copy of stack as we dont want to modify stack itself
	while (node) // Loop through the entire stack/linked list
	{
		// If the value exists in the stack - duplicate found, return true
		if (node->value == value)
			return (true);
		node = node->next; // Go to the next node in the stack
	}
	return (false); // If we got this far, means there are no duplicates, return false
}

/**
 * @brief Assigns a unique ID to each node in the stack.
 * 		  This ID represents the position of each node if it
 * 		  the stack were sorted in ascending order.
 * @param stack A pointer to the stack for which the IDs are to be assigned.
 * 		  The Id of each node in the stack are updated in place.
 */
void assign_id(t_stack *stack)
{
	int		i;
	t_node	*node;
	t_node	*temp_node;

	node = stack->head;
	// Iterate through the entire stack
	while (node)
	{
		temp_node = stack->head;
		i = 0;
		while (temp_node)
		{
			// Compare the current node's value to all other node values
			if (node->value > temp_node->value)
				i++;
			temp_node = temp_node->next;
		}
		// Assign the ID to the current node. The ID represents the number of nodes with a lesser value
		node->id = i;
		node = node->next;
	}
}
