/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:22:53 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 17:33:22 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Cleans up memory and exits the program.
 * 		  Depending on the 'exit_type' it either exits
 * 		  the program with a failure message or a successful termination.
 * @param stack A pointer to the stack to clean up
 * @param exit_type Enum type to determine which exit type to use
 */
void	free_and_exit(t_stack *stack, t_exit exit_type)
{
	free_stack(stack); // Free up the stack
	// Handle exit depending on 'exit_type'
	if (exit_type == FAIL)
	{
		write(2, "Error\n", 6); // Display error message
		exit(1); // Exit with errors, exit code 1
	}
	else if (exit_type == SUCCESS)
		exit(0); // Exit without any errors, exit code 0
}
