/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:03:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 14:57:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_chunksort.h"
#include "ft_primitives.h"

/*
We use chunks of 20  (5chunks ) in stack of 100 and 
	chunks of 46 ( 11 chunks ) in stack of 500
*/
static size_t	ft_chunk_get_size(const t_stack *stack_a)
{
	size_t	stack_size;

	stack_size = ft_stack_size(stack_a);
	if (stack_size < 500)
		return (25);
	if (stack_size >= 500)
		return (60);
	return (30);
}

static t_chunk	ft_chunk_init(size_t chunk_size, size_t stack_size)
{
	t_chunk	chunk;

	chunk.min = 0;
	chunk.max = chunk_size;
	if (chunk.max > stack_size)
		chunk.max = stack_size;
	return (chunk);
}

static t_chunk	ft_chunk_get_next(t_chunk chunk, size_t chunk_size, \
					size_t stack_size)
{
	t_chunk	new_chunk;

	new_chunk.min = chunk.min + chunk_size;
	new_chunk.max = chunk.max + chunk_size;
	if (new_chunk.max > stack_size)
		new_chunk.max = stack_size;
	return (new_chunk);
}

static int	ft_max_value_back_2_stack_a(t_stack **stack_a, t_stack **stack_b, \
				int max_value)
{
	unsigned char	optimized_push;
	int				node_position;

	node_position = ft_get_value_position(*stack_b, max_value);
	optimized_push = ft_stackb_node_to_top(stack_a, stack_b, \
						node_position, max_value);
	ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
	return (optimized_push);
}

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t			chunk_size;
	t_chunk			chunk;
	size_t			stack_size;
	unsigned char	optimized_push;

	stack_size = ft_stack_size(*stack_a);
	chunk_size = ft_chunk_get_size(*stack_a);
	chunk = ft_chunk_init(chunk_size, stack_size);
	while (ft_stack_isempty(stack_a) == FALSE)
	{
		ft_chunk_iteration(stack_a, stack_b, chunk);
		chunk = ft_chunk_get_next(chunk, chunk_size, stack_size);
	}
	while (ft_stack_isempty(stack_b) == FALSE)
	{
		optimized_push = ft_max_value_back_2_stack_a(stack_a, stack_b, \
				stack_size - 1);
		if (optimized_push)
		{
			ft_execute_action(stack_a, stack_b, PRIMITIVE_SA);
			stack_size --;
		}
		stack_size --;
	}
}

/*
void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t			chunk_size;
	t_chunk			chunk;
	size_t			stack_size;
	unsigned char	flag_optimized;
	int				node_position;

	stack_size = ft_stack_size(*stack_a);
	chunk_size = ft_chunk_get_size(*stack_a);
	chunk = ft_chunk_init(chunk_size);
	while (ft_stack_isempty(stack_a) == FALSE)
	{
		ft_chunk_iteration(stack_a, stack_b, chunk);
		chunk = ft_chunk_get_next(chunk, chunk_size, stack_size);
	}
	while (ft_stack_isempty(stack_b) == FALSE)
	{
		node_position = ft_get_value_position(*stack_b, stack_size - 1);
		flag_optimized = ft_stackb_node_to_top2(stack_a, stack_b, \
							node_position, stack_size - 1);
		ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
		if (flag_optimized)
		{
			ft_execute_action(stack_a, stack_b, PRIMITIVE_SA);
			stack_size --;
		}
		stack_size --;
	}
}


*/