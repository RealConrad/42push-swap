/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:13:53 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/05 12:54:11 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack with exactly 3 nodes 
 * @param stack A pointer to the stack that holds exactly 3 nodes
 */
void	sort_3(t_stack *stack)
{
	int	head;
	int	mid;
	int	tail;

	head = stack->head->value; // first element in the stack
	mid = stack->head->next->value; // second element in the stack
	tail = stack->tail->value; // third element in the stack
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

/**
 * @brief Sorts a stack with exactly 4 nodes leveraging an additonal stack
 * @param stack_a A pointer to the stack that initially
 * 				  holds all 4 nodes.
 * @param stack_b A pointer to an empty stack utilized for the sorting
 * 				  algorithm
 */
void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min;
	int		pos;

	min = smallest_node(stack_a);
	pos = get_position(stack_a, min);
	while (stack_a->head != min)
	{
		if (pos < stack_a->size / 2)
			rotate(stack_a, OPERATION_PA);
		else
			rev_rotate(stack_a, OPERATION_RRA);
	}
	pop_and_push(stack_a, stack_b, OPERATION_PB);
	sort_3(stack_a);
	pop_and_push(stack_b, stack_a, OPERATION_PA);
}

/**
 * @brief Sorts a stack with exactly 5 nodes leveraging an additional stack.
 * @param stack_a A pointer to the stack holding all 5 nodes.
 * @param stack_b A pointer to an empty stack utilized for the sorting algorithm.
 */
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
