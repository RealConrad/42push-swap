/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:22:53 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/03 17:29:03 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_and_exit(t_stack *stack, t_exit exit_type)
{
	if (exit_type == FAIL)
	{
		write(2, "Error\n", 6);
		free_stack(stack);
		exit(1);
	}
	else if (exit_type == SUCCESS)
	{
		free_stack(stack);
		exit(0);
	}
}
