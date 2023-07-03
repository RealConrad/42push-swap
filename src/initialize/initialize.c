/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/03 17:26:49 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void init_stack(t_stack *stack, int argc, char **argv)
{
	char	**split_strings;
	int		i;
	int		j;
	long	value;

	i = 0;
	while (i < argc)
	{
		j = 0;
		split_strings = ft_split(argv[i], ' ');
		if (!split_strings)
			free_and_exit(stack, FAIL);
		while (split_strings[j])
		{
			value = atol(split_strings[j]);
			if (!is_valid_input(stack, value, split_strings[j]))
				free_and_exit(stack, FAIL);
			add_node_to_end(stack, (int) value); // typecast back to int as we only want ints
			free(split_strings[j]);
			j++;
		}
		free(split_strings);
		i++;
	}
	assign_id(stack);
}
