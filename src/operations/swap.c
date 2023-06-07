/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:12:24 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/03 14:26:14 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*old_head;
	
	if (stack->size <= 1)
		return ;

	old_head = stack->head;
	stack->head = old_head->next;
	
	old_head->next = stack->head->next;
	old_head->prev = stack->head;

	stack->head->prev = NULL;
	stack->head->next = old_head;
}
