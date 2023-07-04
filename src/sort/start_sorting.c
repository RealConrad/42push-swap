/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:45 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 14:40:37 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) || stack_a->size <= 1)
		free_and_exit(stack_a, SUCCESS);
	if (stack_a->size == 2)
		rotate(stack_a, OPERATION_RA);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->size <= 7)
		sort_large(stack_a, stack_b, 3);
	else if (stack_a->size <= 200)
		sort_large(stack_a, stack_b, 8);
	else
		sort_large(stack_a, stack_b, 16);
}
