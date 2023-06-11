/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:49:36 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/11 16:23:02 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate(t_stack *stack, t_operation operation)
{
	t_node *old_head;

	// If the stack size is 1 or less, no rotation is needed
	if (stack->size <= 1)
		return ;
	old_head = stack->head; // Store current head temporarily
	stack->head = old_head->next; // Make the next node the new head
	stack->head->prev = NULL; // Since this is head, its 'prev' is set to NULL

	old_head->next = NULL; // Detach old head node from list
	stack->tail->next = old_head; // Attach old head node to the end of the list
	old_head->prev = stack->tail;  // Now the last node, its 'prev' point to the previous tail
	stack->tail = old_head; // Update the tail of the stack to be the old head

	print_operation(operation);
}

void rev_rotate(t_stack *stack, t_operation operation)
{
	t_node	*old_tail;

	if (stack->size <= 1) // if true, no rotation needed
		return ;
	old_tail = stack->tail;

	stack->tail = old_tail->prev;
	stack->tail->next = NULL;

	old_tail->prev = NULL;
	old_tail->next = stack->head;
	stack->head->prev = old_tail;
	stack->head = old_tail;

	print_operation(operation);
}
