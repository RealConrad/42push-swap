/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:06:26 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/03 14:48:09 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void pop_and_push(t_stack *stack_to_pop, t_stack *stack_to_push)
{
	t_node	*node;

	node = pop(stack_to_pop);
	if (node)
		push(stack_to_push, node);
}

t_node *pop(t_stack *stack)
{
	t_node	*node_to_pop;

	if (!stack || !stack->head) // check for empty stack
		return (NULL);

	node_to_pop = stack->head; // Want to remove or "pop" top value
	stack->head = node_to_pop->next; // Replace head with new node in list
	node_to_pop->next = NULL; // Set 'next' to NULL to isolate node and prevent full list copying.
	if (stack->head)
		stack->head->prev = NULL; // Update new heads prev position
	else
		stack->tail = NULL; // Stack is empty
	stack->size--;
	return (node_to_pop);	
}

void push(t_stack *stack, t_node *node)
{
	node->next = stack->head; // New node becomes current head
	node->prev = NULL; // New nodes previous pointer is set to NULL
	if (stack->head)
		stack->head->prev = node; // The old head's prev becomes new node
	else
		stack->tail = node; // If stack is empty, the new node is both head and tail
	stack->head = node; // The new node becomes the head
	stack->size++;
}

/*
In stacks we would typically add and remove elements from the head of the list, as
this allows for both push and pop operations to occur in constant time
We want our push() and pop() to be LIFO:
1. LIFO (Last in, first out):
	> Principle --> stack
	> Last element you insert (push) is first element you remove (pop), so add new elements to head, not tail
2. FIFO (First in, first out):
	> Principle --> queue
	> First element you insert is the first one you remove
	> Makes it ideal if you want to keep original order (for queues)
*/