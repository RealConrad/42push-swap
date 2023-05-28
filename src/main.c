/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:19 by cwenz             #+#    #+#             */
/*   Updated: 2023/05/28 18:56:28 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack list = { NULL, NULL}; // Initialize stack with null head and tail
	
	if (argc <= 1)
		return (0);
	init_stack(&list, argc, argv);
	print_list(list.head); // Print from head
	// system("leaks a.out");
	return (0);
}

// Function to print the linked list
void print_list(t_node *node) 
{
	ft_printf("Linked List: ");
	while (node != NULL)
    {
    	ft_printf("%d ", node->value);
    	node = node->next;
	}
	ft_printf("\n");
}

