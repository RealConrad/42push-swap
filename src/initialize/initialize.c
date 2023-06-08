/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/06 14:01:20 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/push_swap.h"

void init_stack(t_stack *stack, int argc, char **argv)
{
	if (argc == 1) // Handling input parsed as 1 string
		handle_one_input(stack, argv);
	else // Handling input parsed as multiple inputs
		handle_multiple_inputs(stack, argc, argv);
}
