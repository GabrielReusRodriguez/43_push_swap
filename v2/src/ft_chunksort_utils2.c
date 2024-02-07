/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:19:59 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 21:24:44 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunksort.h"
#include "ft_primitives.h"

void	ft_stacka_min_to_top(t_stack **stack_a)
{
	int		min_position;

	min_position = ft_get_max_position(*stack_a);
    ft_stacka_node_to_top(stack_a, min_position);
}

void	ft_stacka_max_to_top(t_stack **stack_a)
{
	int		max_position;

	max_position = ft_get_max_position(*stack_a);
    ft_stacka_node_to_top(stack_a, max_position);
}

void	ft_stacka_node_to_top(t_stack **stack_a, int node_position)
{
    size_t  size;
    int     i;
    int     action;
    size_t  num_steps;
    
    size = ft_stack_size(*stack_a);
	i = 0;
	if ((size_t)node_position < size / 2)
    {
        num_steps = node_position;
		action = PRIMITIVE_RRA;
    }
	else
	{
		num_steps = size - node_position + 1;
		action = PRIMITIVE_RA;
	}
	while ((size_t)i < num_steps)
	{
		ft_execute_action(stack_a, NULL, action);
		i++;
	}
}

void	ft_stackb_node_to_top(t_stack **stack_b, int node_position)
{
    size_t  size;
    int     i;
    int     action;
    size_t  num_steps;
    
    size = ft_stack_size(*stack_b);
	i = 0;
	if ((size_t)node_position < size / 2)
    {
        num_steps = node_position;
		action = PRIMITIVE_RRB;
    }
	else
	{
		num_steps = size - node_position + 1;
		action = PRIMITIVE_RB;
	}
	while ((size_t)i < num_steps)
	{
		ft_execute_action(NULL, stack_b, action);
		i++;
	}
}
