/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:45 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/07 13:56:34 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_small(t_stack *stack_a, t_stack *stack_b);

void	start_sorting(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 0)
		sort_small(stack_a, stack_b);
	while (stack_b->size > 0)
		pop_and_push(stack_b, stack_a, 'a');
}

static void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;
	t_node	*temp;

	temp = stack_a->head;
	smallest = stack_a->head;

	while(temp)
	{
		if (temp->value < smallest->value)
			smallest = temp;
		temp = temp->next;
	}
	while (stack_a->head != smallest)
		ra(stack_a);

	pop_and_push(stack_a, stack_b, 'b');
}
