/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:12:31 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 17:42:53 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Frees the allocated memory to each node in the stack.
 * @param stack A pointer to the stack whose nodes are to be freed.
 */
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->head; // start at the head of the stack
	while (current)
	{
		next_node = current->next; // store the next node before freeing
		free(current); // free current node
		current = next_node; // move onto the next node
	}
}
