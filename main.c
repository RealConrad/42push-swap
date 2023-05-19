/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:19 by cwenz             #+#    #+#             */
/*   Updated: 2023/05/19 14:45:48 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char **argv)
{
	printf("Number of arguments: %d\n", argc);
	if (argc <= 1)
		return (0);
	init_stack(argc, argv);
	
	return (0);
}
