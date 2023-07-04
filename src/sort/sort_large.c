/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:12:59 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/04 13:36:33 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_back_to_stack_a(t_stack *stack_a, t_stack *stack_b);
static void	process_stack_a(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end);

void	sort_large(t_stack *stack_a, t_stack *stack_b, int num_chunks)
{
	int		i;
	int		chunk_size;
	int		chunk_end;
	int		chunk_start;

	i = 0;
	chunk_size = stack_a->size / num_chunks;
	while(i <= num_chunks)
	{
		chunk_start = i * chunk_size;
		chunk_end = (i + 1) * chunk_size;
		process_stack_a(stack_a, stack_b, chunk_start, chunk_end);
		i++;
	}
	move_back_to_stack_a(stack_a, stack_b);
}

static void	process_stack_a(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end)
{
	t_node	*top_node;
	t_node	*bottom_node;
	int		top_node_moves;
	int		bottom_node_moves;

	while (stack_a->size)
	{
		top_node_moves = 0;
		bottom_node_moves = 0;
		top_node = stack_a->head;
		bottom_node = stack_a->tail;

		// Check from top and bottom
		top_node_moves = check_from_direction(&top_node, chunk_start, chunk_end, TOP);
		bottom_node_moves = check_from_direction(&bottom_node, chunk_start, chunk_end, BOTTOM);

		if (top_node_moves <= bottom_node_moves)
			move_node_to_top(stack_a, stack_b, top_node);
		else
			move_node_to_top(stack_a, stack_b, bottom_node);
		// Check to see if there are nodes from current chunk in stack_a
		if (!nodes_in_chunk(stack_a, chunk_start, chunk_end))
			break ; // Entire chunk is finished -> break out and move onto next chunk
	}
}

static void	move_back_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*largest;
	int		pos;

	while (stack_b->size)
	{
		largest = largest_node(stack_b);
		pos = get_position(stack_b, largest);
		while (stack_b->head != largest)
		{
			if (pos < stack_b->size / 2)
				rotate(stack_b, OPERATION_RB);
			else
				rev_rotate(stack_b, OPERATION_RRB);
		}
		pop_and_push(stack_b, stack_a, OPERATION_PA);
	}
}

