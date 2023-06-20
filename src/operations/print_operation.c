/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:47:45 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/20 12:58:12 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1. sa (swap a): Swap the first 2 elements at the top of stack a. ------------- DONE -------------
2. sb (swap b): Swap the first 2 elements at the top of stack b. ------------- DONE -------------
3. ss : sa and sb at the same time.

4. pa (push a): Take the first element at the top of b and put it at the top of a. ------------- DONE -------------
5. pb (push b): Take the first element at the top of a and put it at the top of b. ------------- DONE -------------

6. ra (rotate a): Shift up all elements of stack a by 1. ------------- DONE -------------
7. rb (rotate b): Shift up all elements of stack b by 1. ------------- DONE -------------
8. rr : ra and rb at the same time.

9. rra (reverse rotate a): Shift down all elements of stack a by 1. ------------- DONE -------------
10. rrb (reverse rotate b): Shift down all elements of stack b by 1.
11. rrr : rra and rrb at the same time.
*/

void	print_operation(t_operation operation)
{
	counter++;
	if (operation == OPERATION_SA)
		ft_printf("sa\n");
	else if (operation == OPERATION_SB)
		ft_printf("sb\n");
	else if (operation == OPERATION_PA)
		ft_printf("pa\n");
	else if (operation == OPERATION_PB)
		ft_printf("pb\n");
	else if (operation == OPERATION_RA)
		ft_printf("ra\n");
	else if (operation == OPERATION_RB)
		ft_printf("rb\n");
	else if (operation == OPERATION_RRA)
		ft_printf("rra\n");
	else if (operation == OPERATION_RRB)
		ft_printf("rrb\n");
}
