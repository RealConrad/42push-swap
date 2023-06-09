/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:47:45 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 17:53:46 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints the specific stack operation to standard output.
 * @param operation The stack operation to print. It should be one of the enumeration 
 * 					values: OPERATION_SA, OPERATION_SB, OPERATION_PA, OPERATION_PB,
 * 					OPERATION_RA, OPERATION_RB, OPERATION_RRA, OPERATION_RRB.
 */
void	print_operation(t_operation operation)
{
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
