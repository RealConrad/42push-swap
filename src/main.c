/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:19 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 14:02:32 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (0);
}
