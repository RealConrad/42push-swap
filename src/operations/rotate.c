/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:49:36 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 18:16:24 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the given stack to the left by 1.
 * 		  First element becomes the last element.
 * @param stack A pointer to the stack that is to be rotated.
 * @param operation The stack operation that is to be printed out.
 * 		  It should be one of the enumeration values from t_operation
 */
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

	print_operation(operation); // Print operation
}

/**
 * @brief Reverse rotates the given stack to the right by 1.
 * 		  The last element becomes the first element.
 * @param stack A pointer to the stack that is to be reverse rotated.
 * @param operation The stack operation that is to be printed out.
 * 		  It should be one of the enumeration values from t_operation
 */
void rev_rotate(t_stack *stack, t_operation operation)
{
	t_node	*old_tail;

	if (stack->size <= 1) // If true, no rotation needed
		return ;
	old_tail = stack->tail; // Store the current tail

	// Set new tail of the stack and disconnect old tail
	stack->tail = old_tail->prev; // Previous node becomes new tail
	stack->tail->next = NULL; // Cut off link to old tail

	// Relocate old tail to the head of the stack
	old_tail->prev = NULL; // Old tail is now the new head so prev pointer = NULL
	old_tail->next = stack->head; // Link to the old head
	stack->head->prev = old_tail; // Back link from old head to the new head
	stack->head = old_tail; // Update the head of the stack 

	print_operation(operation); // Print operation
}
