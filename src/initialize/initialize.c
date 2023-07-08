/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/08 17:48:22 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes the stack with unique int values obtained from the 
 * 		  command line.
 * 		  Each argument may contain multiple space-separated values.
 * 		  Each value is validated before adding to the stack.
 * 		  In the case of any failure, the functions cleans up and exits.
 * @param stack A pointer to the stack to be initialized
 * @param argc The number of command line arguments
 * @param argv The command line arguments
 */
void	init_stack(t_stack *stack, int argc, char **argv)
{
	char	**split_strings;
	int		i;
	int		j;
	long	value;

	i = 0;
	while (i < argc) // iterate over all command-line arguments
	{
		j = 0;
		split_strings = ft_split(argv[i], ' '); // split the current argument into set of strings
		if (!split_strings) // if splitting fails, cleanup memory and exit
			free_and_exit(stack, FAIL);
		while (split_strings[j]) // iterate over all the split strings
		{
			value = atol(split_strings[j]); // convert current string to long type
			if (!is_valid_input(stack, value, split_strings[j])) // check if its valid input
				free_and_exit(stack, FAIL);
			add_node_to_end(stack, (int) value); // typecast back to int as we only want ints
			free(split_strings[j]); // free the current string as we dont need it anymore
			j++;
		}
		free(split_strings);
		i++;
	}
	// After all nodes have been added to the stack, assign a unique ID to each node (presort)
	assign_id(stack);
}
