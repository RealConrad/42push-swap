/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:13:53 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/25 12:18:23 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	head;
	int	mid;
	int	tail;

	head = stack->head->value;
	mid = stack->head->next->value;
	tail = stack->tail->value;
	if (head > mid && mid < tail && head < tail)
		swap(stack, OPERATION_SA);
	else if (head > mid && mid < tail && tail < head)
		rotate(stack, OPERATION_RA);
	else if (head < mid && mid > tail && tail < head)
		rev_rotate(stack, OPERATION_RRA);
	else if (head > mid && mid > tail && tail < head)
	{
		swap(stack, OPERATION_SA);
		rev_rotate(stack, OPERATION_RRA);
	}
	else if (head < mid && mid > tail && tail > head)
	{
		swap(stack, OPERATION_SA);
		rotate(stack, OPERATION_RA);
	}
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min;
	int		pos;

	// Push 2 smallest values to stack b
	while(stack_a->size > 3)
	{
		min = smallest_node(stack_a);
		pos = get_position(stack_a, min);
		while(stack_a->head->value != min->value)
		{
			// Check which operation would be most efficient
			if (pos < stack_a->size / 2)
				rotate(stack_a, OPERATION_RA);
			else
				rev_rotate(stack_a, OPERATION_RRA);
		}
		pop_and_push(stack_a, stack_b, OPERATION_PB);
	}
	// Sort the remaining 3 numbers
	sort_3(stack_a);
	while(stack_b->size)
		pop_and_push(stack_b, stack_a, OPERATION_PA);
}
