/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/18 15:23:19 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/push_swap.h"

void init_stack(t_stack *stack, int argc, char **argv)
{
	char	**split_strings;
	int		i;
	int		j;
	int		value;

	i = 0;
	while (i < argc)
	{
		j = 0;
		split_strings = ft_split(argv[i], ' ');
		if (!split_strings)
			display_error_and_exit();
		while (split_strings[j])
		{
			value = ft_atoi(split_strings[j]);
			if (!is_number(split_strings[j]) || is_duplicate(stack, value))
				display_error_and_exit();
			add_node_to_end(stack, value);
			free(split_strings[j]);
			j++;
		}
		free (split_strings);
		i++;
	}
	assign_id_values(stack);
}
