/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:19 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/07 14:10:46 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a.
 
To do so you have the following operations at your disposal:
1. sa (swap a): Swap the first 2 elements at the top of stack a.
	> Do nothing if there is only one or no elements.
2. sb (swap b): Swap the first 2 elements at the top of stack b.
	> Do nothing if there is only one or no elements.
3. ss : sa and sb at the same time.
4. pa (push a): Take the first element at the top of b and put it at the top of a.
	> Do nothing if b is empty.
5. pb (push b): Take the first element at the top of a and put it at the top of b.
	> Do nothing if a is empty.
6. ra (rotate a): Shift up all elements of stack a by 1.
	> The first element becomes the last one.
7. rb (rotate b): Shift up all elements of stack b by 1.
	> The first element becomes the last one.
8. rr : ra and rb at the same time.
9. rra (reverse rotate a): Shift down all elements of stack a by 1
	> The last element becomes the first one.
10. rrb (reverse rotate b): Shift down all elements of stack b by 1.
	> The last element becomes the first one.
11. rrr : rra and rrb at the same time.
*/

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
	
	// ft_printf("Linked List A: ");
	// print_list(stack_a.head);
	return (0);
}

// Function to print the linked list
void	print_list(t_node *node)
{
	while (node != NULL)
	{
		ft_printf("%d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}
