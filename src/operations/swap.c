/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:12:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/11 17:07:02 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap(t_stack *stack, t_operation operation)
{
    t_node *old_head;

    if (stack->size <= 1)
        return;

    old_head = stack->head;

    // Change the head of the stack to the second node
    stack->head = old_head->next;
    stack->head->prev = NULL; // The new head's 'prev' should be NULL

    // Now update the links in the old head
    old_head->next = stack->head->next;
    old_head->prev = stack->head;
    old_head->next->prev = old_head; // Update third node 'prev' to point to the old head

    // Update the link in the new head
    stack->head->next = old_head;

    print_operation(operation);
}
