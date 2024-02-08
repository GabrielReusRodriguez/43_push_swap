/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:03:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/08 13:44:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
        return (10);
        //return (20);
    if (stack_size  >= 500)
        return (50);
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
                    size_t stack_size)
{
    t_chunk new_chunk;
    new_chunk.min = chunk.min + chunk_size;
    new_chunk.max = chunk.max + chunk_size;
    if (new_chunk.max > stack_size)
        new_chunk.max = stack_size;
    return (new_chunk);
}

void    ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
    size_t  chunk_size;
    t_chunk chunk;
    size_t  stack_size;
    //size_t  num_chunks;
    //size_t  i;
   // int     max_position;

    stack_size = ft_stack_size(*stack_a);
    //printf("Chunk size\n");
    chunk_size = ft_chunk_get_size(*stack_a);
    //printf("Chunk size %lu\n",chunk_size);
    chunk = ft_chunk_init(chunk_size);
    //printf("Pre-bucle\n");
    //printf("DEBUG INIT %lu size %lu min %lu max\n", stack_size, chunk.min, chunk.max);
    //ft_stack_debug(*stack_a);
    //ft_stack_debug(*stack_b);
    //num_chunks = stack_size / chunk_size;
    //i = 0;
    //while (i < num_chunks -1)
    while (chunk.min < stack_size)
    {   
        ft_chunk_iteration(stack_a, stack_b, chunk);
       //ft_stack_debug(*stack_b);
        chunk = ft_chunk_get_next(chunk, chunk_size, stack_size);    
        //printf("nex_chunk min %lu max %lu\n",chunk.min, chunk.max);
      //  i++;
    }
    /*
    while(ft_stack_isempty(stack_b))
    {
        ft_execute_action(NULL, stack_b, PRIMITIVE_PB);
    }
    */
    /*
    printf("DEBUG %lu size %lu min\n", stack_size, chunk.min);
    //ft_stack_debug(*stack_a);
    ft_stack_debug(*stack_b);
    
    printf("Post-bucle\n");
    */
    while (ft_stack_isempty(stack_b) == FALSE)
    {
        ft_stackb_max_to_top(stack_b);
        /*max_position = ft_get_max_position(*stack_b);
   //     printf("\tMAX_POSITION: %d\n",max_position);
        //ft_stack_debug(*stack_b);
        ft_stackb_node_to_top(stack_b,max_position);
     //   ft_stack_debug(*stack_b);
     */
        ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
        //ft_stack_debug(*stack_b);
    }
}
