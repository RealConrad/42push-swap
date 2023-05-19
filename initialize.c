/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:25:15 by cwenz             #+#    #+#             */
/*   Updated: 2023/05/19 17:21:37 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *init_stack(int stack_count, char **stack_values)
{
	printf("%d %s", stack_count, stack_values[0]);
	return (0);
}



// t_stack *create_node(int data)
// {
// 	t_stack	*node;
	
// 	node = (t_stack*)malloc(sizeof(t_stack));
// }

// Function to print the linked list
void printList(t_stack *node) 
{
	while (node != NULL)
    {
    	printf("%d ", node->value);
    	node = node->next;
	}
}
