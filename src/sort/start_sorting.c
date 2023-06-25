/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:09:45 by cwenz             #+#    #+#             */
/*   Updated: 2023/06/25 12:20:38 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
	else if (stack_a->size > 5)
		sort_large(stack_a, stack_b, 3);
}
