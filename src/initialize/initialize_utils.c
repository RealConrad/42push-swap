/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:24:09 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/06 15:49:16 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	is_number(char *str);
static void	add_node_to_end(t_stack *stack, int node_value);
static bool	is_duplicate(t_stack *stack, int value);

void	handle_multiple_inputs(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	value;

	i = 0;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (!is_number(argv[i]) || is_duplicate(stack, value))
			display_error_and_exit();
		add_node_to_end(stack, value);
		i++;
	}
}

void	handle_one_input(t_stack *stack, char **argv)
{
	char	**split_strings;
	int		i;
	int		value;

	i = 0;
	// start at index 0 as we incremented back in the main to skip program name
	split_strings = ft_split(argv[0], ' ');
	if (!split_strings || split_strings[0] == NULL)
		display_error_and_exit();
	while (split_strings[i])
	{
		value = ft_atoi(split_strings[i]);
		if (!is_number(split_strings[i]) || is_duplicate(stack, value))
			display_error_and_exit();
		add_node_to_end(stack, value);
		free(split_strings[i]);
		i++;
	}
	free(split_strings);
}

static void	add_node_to_end(t_stack *stack, int node_value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		display_error_and_exit();
	new_node->value = node_value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
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

static bool	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
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
