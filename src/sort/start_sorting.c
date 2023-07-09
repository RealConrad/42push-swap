/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:45 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/09 15:28:43 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Determines which sorting algorithm to use based
 * 		  on the size of the stack_a. 
 * 		  If stack_a is already sorted or is less than or
 * 		  equal to 1, the function cleans up and exits.
 * @param stack_a A pointer to the first stack to be sorted. The
 * 				  selected sorting algorithm depends on the size of
 * 				  this stack.
 * @param stack_b A pointer to the second stack which may be used by 
 * 				  the sorting algorithm for an additional stack
 */
void	start_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) || stack_a->size <= 1)
		free_and_exit(stack_a, SUCCESS);
	if (stack_a->size == 2)
		swap(stack_a, OPERATION_SA);
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
