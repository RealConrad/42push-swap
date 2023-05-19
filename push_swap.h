/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:03 by cwenz             #+#    #+#             */
/*   Updated: 2023/05/19 17:21:47 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // Remove
# include <stdlib.h>
# include "42c-library/libft_main.h"

typedef struct stack {
	int				value;
	struct stack	*next;
} t_stack;

int *init_stack(int stack_count, char **stack_values); // change to void type

void print_list(t_stack *node); // NOT NEEDED

#endif /* PUSH_SWAP_H */