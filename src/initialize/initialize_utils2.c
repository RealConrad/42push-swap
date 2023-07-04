/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:04:59 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 17:16:04 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Converts a string to a long integer, processing
 * 		  optional leading whitespace and '+' or '-' signs.
 * @param str The string to be converted. This could represent 
 * 		  positive, negative, or zero values. Leading whitespace 
 * 		  and an optional sign ('+' or '-') are handled.
 * @return Returns the converted long integer value of the 
 * 		   input string. If a minus sign was present, the returned value 
 * 		   will be negative. If no valid numeric input is found,
 * 		   the function returns zero.
 */
long	atol(const char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	number = 0;
	sign = 1;
	// Skip leading white space
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((char)str[i] >= 48 && (char)str[i] <= 57)
	{
		number = 10 * number + ((char)str[i] - 48);
		i++;
	}
	// Return value, accounting for the sign
	return (number * sign);
}
