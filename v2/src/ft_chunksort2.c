/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:03:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/08 01:36:18 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunksort.h"
#include "ft_primitives.h"
#include <limits.h>
#include <stdio.h>

static int	ft_chunk_get_hold_first(t_stack **stack, t_chunk chunk)
{
	t_stack	*node;
	int	i;

	i = 0;
	node = *stack;
	while (node != NULL)
	{
		if ((size_t)node->content >= chunk.min && (size_t)node->content < chunk.max)
			return (i);
		i++;
		node = node->next;
	}
	return (-1);
}

static int	ft_chunk_get_hold_second(t_stack **stack, t_chunk chunk)
{
	t_stack	*node;
	size_t	size;
	int	i;

	size = ft_stack_size(*stack);
	i = size - 1;
	while (i >= 0)
	{
		node = ft_stack_get_node(*stack, i );
		if (node == NULL)
			return (-1);
		if ((size_t)node->content >= chunk.min && (size_t)node->content < chunk.max)
			return (i);
		i--;
	}
	return (-1);
}

/*
num_steps_hold_2 is + 1 for the last rra to put the node from bottom to top.
*/
static void	ft_best_hold_2_top(t_stack **stack_a, size_t size_a, int hold_1, \
				int hold_2)
{
	int num_steps_hold_2;

	num_steps_hold_2 = size_a - hold_2 + 1;
	if (num_steps_hold_2 < hold_1)
		ft_stacka_node_to_top(stack_a, hold_2);
	else
		ft_stacka_node_to_top(stack_a, hold_1);
}

void	ft_chunk_iteration(t_stack **stack_a, t_stack **stack_b, \
			t_chunk chunk)
{
	size_t	numbers_found;
	size_t	stacka_size;
	size_t	total_size;
	int		hold_1;
	int		hold_2;

	numbers_found = 0;
	//printf("PRE-iteration bucle \n");
	total_size = ft_stack_size(*stack_a);
	while (numbers_found < chunk.max - chunk.min && numbers_found < total_size)
	{
		stacka_size = ft_stack_size(*stack_a);
		hold_1 = ft_chunk_get_hold_first(stack_a, chunk);
		hold_2 = ft_chunk_get_hold_second(stack_a, chunk);
		//printf("HOLD 1 _%d_ HOLD 2 _%d_ min _%lu_ max _%lu_ num_found %lu\n",hold_1, hold_2,chunk.min, chunk.max, numbers_found);
		ft_best_hold_2_top(stack_a, stacka_size, hold_1, hold_2);
		//ft_stackb_min_to_top(stack_b);
		ft_stackb_max_to_top(stack_b);
		ft_execute_action(stack_a, stack_b, PRIMITIVE_PB);
		//ft_stack_debug(*stack_b);
		numbers_found++;
	}
	//printf("\t\tFINAL\n");
	//ft_stack_debug(*stack_a);
	//ft_stack_debug(*stack_b);
}
