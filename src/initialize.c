/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/05/28 19:06:37 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

static void add_node_to_end(t_stack *stack, int node_value);

void init_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**split_strings = NULL;

	if (argc == 2) // Handling input parsed as string
	{
		i = 0;
		split_strings = ft_split(argv[1], ' '); // start at index 1 -> skip program name
		if (!split_strings)
			return ; // error-message?
		while(split_strings[i])
		{
			add_node_to_end(stack, ft_atoi(split_strings[i]));
			free(split_strings[i]); // free each individual string after use
			i++;
		}
		free(split_strings); // free array
	}
	else // Handling input parsed as multiple inputs
	{
		i = 1; // Start at 1 -> skip program name (argv[0])
		while(i < argc)
			add_node_to_end(stack, ft_atoi(argv[i++]));
	}
}

static void add_node_to_end(t_stack *stack, int node_value)
{
	t_node *new_node = NULL;
	
	new_node = (t_node*)malloc(sizeof(t_node));
	if (!new_node)
		return ; // error-message?
	new_node->value = node_value;
	new_node->next = NULL;

	// If the stack is not initialized yet
	if (!stack->head)
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
