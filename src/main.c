/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:19 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/03 17:02:14 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO:
// 1. Account for int overflow
// 3. Check edge cases

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	// Initialize stack with null head and tail
	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_b.head = NULL;
	stack_b.tail = NULL;
	if (argc <= 1)
		return (0);
	init_stack(&stack_a, --argc, ++argv); // Skip program name
	start_sorting(&stack_a, &stack_b);
	
	free_stack(&stack_a);

	// print_list(stack_a.head);
	// ft_printf("Total OPS: %d\n", counter);
	return (0);
}

// Function to print the linked list
void	print_list(t_node *node)
{
	ft_printf("\nStack: \n");
	while (node != NULL)
	{
		ft_printf("%d ", node->value);
		// ft_printf("ID: %d :: N: %d\n", node->id, node->value);
		node = node->next;
	}
	ft_printf("\n");
}
