/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:49:36 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/07 13:54:21 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ra(t_stack *stack)
{
	t_node *old_head = NULL;

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

	ft_printf("ra\n");
}
