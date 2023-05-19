/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:19 by cwenz             #+#    #+#             */
/*   Updated: 2023/05/19 17:31:55 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char **argv)
{
	int i = 1;
	printf("Number of arguments: %d\n", argc);
	while (i++ == 1)
		printf("%s", argv[0]);
	if (argc <= 1)
		return (0);
	// init_stack(argc, argv);
	
	return (0);
}
