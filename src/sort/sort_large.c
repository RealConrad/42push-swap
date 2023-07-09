/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwenz <cwenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:12:59 by cwenz             #+#    #+#             */
/*   Updated: 2023/07/09 15:26:58 by cwenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_back_to_stack_a(t_stack *stack_a, t_stack *stack_b);
static void	process_stack_a(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end);

/**
 * @brief Sorts a large stack by dividing it into smaller chunks and
 * 		  processing them separately.
 * @param stack_a A pointer to the stack holding a large number of nodes
 * 		  to be sorted.
 * @param stack_b A pointer to an empty stack utilized for the sorting algorithm.
 * @param num_chunks The number of chunks to divide stack_a into for sorting.
 */
void	sort_large(t_stack *stack_a, t_stack *stack_b, int num_chunks)
{
	int		i;
	int		chunk_size;
	int		chunk_end;
	int		chunk_start;

	i = 0;
	chunk_size = stack_a->size / num_chunks;
	// Divide the stack into chunks and process separately
	while(i <= num_chunks)
	{
		chunk_start = i * chunk_size;
		chunk_end = (i + 1) * chunk_size;
		process_stack_a(stack_a, stack_b, chunk_start, chunk_end);
		i++;
	}
	// After processing all chunks, move everything back to stack A
	move_back_to_stack_a(stack_a, stack_b);
}

/**
 * @brief Processes a specific chunk from stack_a and moves relevant nodes
 * 		  to stack_b.
 * @param stack_a A pointer to the original stack to be sorted.
 * @param stack_b An empty stack utilized for the sorting algorithm.
 * @param chunk_start The starting index of the chunk in the original stack.
 * @param chunk_end The ending index of the chunk in the original stack.
 */
static void	process_stack_a(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end)
{
	t_node	*top_node;
	t_node	*bottom_node;
	int		top_node_moves;
	int		bottom_node_moves;

	// Process each node in stack A
	while (stack_a->size)
	{
		top_node_moves = 0;
		bottom_node_moves = 0;
		top_node = stack_a->head;
		bottom_node = stack_a->tail;

		// Check from top and bottom to determine number of moves
		top_node_moves = check_from_direction(&top_node, chunk_start, chunk_end, TOP);
		bottom_node_moves = check_from_direction(&bottom_node, chunk_start, chunk_end, BOTTOM);

		// Move the node that requires fewer moves to the top
		if (top_node_moves <= bottom_node_moves)
			move_node_to_top(stack_a, stack_b, top_node);
		else
			move_node_to_top(stack_a, stack_b, bottom_node);
		// Check to see if there are nodes from current chunk in stack_a
		if (!nodes_in_chunk(stack_a, chunk_start, chunk_end))
			break ; // Entire chunk is finished -> break out and move onto next chunk
	}
}

/**
 * @brief Moves all nodes from stack_b to stack_a in a sorted order.
 * @param stack_a A pointer to the original stack to which the 
 * 				  sorted nodes are moved.
 * @param stack_b A pointer to the stack holding nodes to be moved back to
 * 				  stack_a.
 */
static void	move_back_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*largest;
	int		pos;

	// While there are nodes in stack B, move each node back to stack A
	while (stack_b->size)
	{
		largest = largest_node(stack_b);
		pos = get_position(stack_b, largest);
		// Rotate stack B until the largest is on top
		while (stack_b->head != largest)
		{
			// Determine which is more efficient
			if (pos < stack_b->size / 2)
				rotate(stack_b, OPERATION_RB);
			else
				rev_rotate(stack_b, OPERATION_RRB);
		}
		pop_and_push(stack_b, stack_a, OPERATION_PA);
	}
}

