/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:03:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 21:25:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunksort.h"
#include "ft_primitives.h"

/*
We use chunks of 20  (5chunks ) in stack of 100 and 
    chunks of 46 ( 11 chunks ) in stack of 500
*/
static size_t ft_chunk_get_size(const t_stack *stack_a)
{
    size_t  stack_size;

    stack_size = ft_stack_size(stack_a);
    if (stack_size <=  100)
        return (20);
    if (stack_size  >= 500)
        return (46);
    return (30);
}

static t_chunk  ft_chunk_init(size_t chunk_size)
{
    t_chunk chunk;

    chunk.min = 0;
    chunk.max = chunk_size;
    return (chunk);

}

static t_chunk  ft_chunk_get_next(t_chunk chunk, size_t chunk_size, \
                    size_t stack_size, size_t i)
{
    t_chunk new_chunk;

    new_chunk.min = chunk.min + chunk_size * i;
    new_chunk.max = chunk.max + chunk_size * i;
    if (new_chunk.max > stack_size)
        new_chunk.max = stack_size;
    return (new_chunk);
}

void    ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
    size_t  chunk_size;
    size_t  i;
    t_chunk chunk;
    size_t  stack_size;
    int     max_position;

    stack_size = ft_stack_size(*stack_a);
    chunk_size = ft_chunk_get_size(*stack_a);
    chunk = ft_chunk_init(chunk_size);
    i = 0;
    while (chunk.min < stack_size)
    {
        ft_chunk_iteration(stack_a, stack_b, chunk);
        i++;
        ft_chunk_get_next(chunk, chunk_size, stack_size, i);
    }
    while (ft_stack_isempty(stack_b) == FALSE)
    {
        max_position = ft_get_max_position(*stack_b);
        ft_stackb_node_to_top(stack_b,max_position);
        ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
    }
}
