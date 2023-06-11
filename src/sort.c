/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:45 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/11 16:27:52 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack);

void	start_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_3(stack_a);
	// else if (stack_a->size == 5)
	// 	sort_5();
	// else if (stack_a->size <= 100)
	// 	sort_medium();
	// else
	// 	sort_large();
	
	(void)stack_b;
	// while (stack_a->size > 0)
	// 	sort_small(stack_a, stack_b);
	// while (stack_b->size > 0)
	// 	pop_and_push(stack_b, stack_a, 'a');
}

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

// static void	sort_small(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*smallest;
// 	t_node	*temp;

// 	temp = stack_a->head;
// 	smallest = stack_a->head;

// 	while(temp)
// 	{
// 		if (temp->value < smallest->value)
// 			smallest = temp;
// 		temp = temp->next;
// 	}
// 	while (stack_a->head != smallest)
// 		ra(stack_a);

// 	pop_and_push(stack_a, stack_b, 'b');
// }
