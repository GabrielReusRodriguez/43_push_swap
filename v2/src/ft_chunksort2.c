/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:03:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 12:15:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunksort.h"
#include "ft_primitives.h"
#include <limits.h>

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

	num_steps_hold_2 = size_a - hold_2;
	if (num_steps_hold_2 < hold_1)
	{
		ft_stacka_node_to_top(stack_a, hold_2);
	}
	else
	{
		ft_stacka_node_to_top(stack_a, hold_1);
	}
}

static void ft_busca_punto_push(t_stack **stack_a, t_stack **stack_b, t_chunk chunk)
{

	size_t	chunk_size;
	int		value;

	chunk_size = chunk.max - chunk.min;
	value = (*stack_a)->content;
	
	ft_execute_action(stack_a, stack_b, PRIMITIVE_PB);
	if ((size_t)value < chunk.min + chunk_size / 2 )
	{	
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RB);
		return;
	}
}
/*
	if ((*stack_b)->next != NULL && (*stack_b)->content < (*stack_b)->next->content)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_SB);
		return;
	}
*/


void	ft_chunk_iteration(t_stack **stack_a, t_stack **stack_b, \
			t_chunk chunk)
{
	size_t	numbers_found;
	size_t	stacka_size;
	int		hold_1;
	int		hold_2;

	numbers_found = 0;
	while (numbers_found < chunk.max - chunk.min)
	{
		stacka_size = ft_stack_size(*stack_a);
		hold_1 = ft_chunk_get_hold_first(stack_a, chunk);
		hold_2 = ft_chunk_get_hold_second(stack_a, chunk);
		ft_best_hold_2_top(stack_a, stacka_size, hold_1, hold_2);
		ft_busca_punto_push(stack_a, stack_b, chunk);
		numbers_found++;
	}	
}