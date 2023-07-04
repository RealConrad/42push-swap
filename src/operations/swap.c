/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:12:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 18:21:05 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first 2 elements in the stack.
 * 		  If the stack size is 1 or less, no swap is performed.
 * @param stack A pointer to the stack that is to be swapped.
 * @param operation The stack operation that is to be performed/printed out
 */
void swap(t_stack *stack, t_operation operation)
{
	t_node *old_head;

	// if stack size is 1 or less, no swap needed
	if (stack->size <= 1)
		return;
	old_head = stack->head; // Store the current head

	// Change the head of the stack to the second node
	stack->head = old_head->next;
	stack->head->prev = NULL; // The new head's 'prev' should be NULL

	// Now update the links in the old head
	old_head->next = stack->head->next;
	old_head->prev = stack->head;
	if (old_head->next)
		old_head->next->prev = old_head; // Update third node 'prev' to point to the old head

	// Update the link for the new head
	stack->head->next = old_head;

	print_operation(operation);
}
