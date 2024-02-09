/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:19:59 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 12:22:11 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunksort.h"
#include "ft_primitives.h"
/*
void	ft_stacka_min_to_top(t_stack **stack_a)
{
	int		min_position;

	min_position = ft_get_min_position(*stack_a);
    ft_stacka_node_to_top(stack_a, min_position);
}
*/
/*
void	ft_stacka_max_to_top(t_stack **stack_a)
{
	int		max_position;

	max_position = ft_get_max_position(*stack_a);
    ft_stacka_node_to_top(stack_a, max_position);
}
*/

void	ft_stacka_node_to_top(t_stack **stack_a, int node_position)
{
    size_t  size;
    int     i;
    int     action;
    size_t  num_steps;
    
    size = ft_stack_size(*stack_a);
	i = 0;
	if ((size_t)node_position <= size / 2)
    {
        num_steps = node_position ;
		action = PRIMITIVE_RA;
    }
	else
	{
		num_steps = size - node_position;
		action = PRIMITIVE_RRA;
	}
	while ((size_t)i < num_steps)
	{
		ft_execute_action(stack_a, NULL, action);
		i++;
	}
	
}

/*
void	ft_stackb_node_to_top(t_stack **stack_b, int node_position)
{
    size_t  size;
    int     i;
    int     action;
    size_t  num_steps;
    
    size = ft_stack_size(*stack_b);
	i = 0;
	if ((size_t)node_position <= size / 2)
    {
        num_steps = node_position;
		action = PRIMITIVE_RB;
    }
	else
	{
		num_steps = size - node_position;
		action = PRIMITIVE_RRB;
	}
	while ((size_t)i < num_steps)
	{
		ft_execute_action(NULL, stack_b, action);
		i++;
	}
}
*/

int	ft_stackb_node_to_top2(t_stack **stack_a, t_stack **stack_b, int node_position, int value)
{
    size_t			size;
    int				i;
    int				action;
    size_t			num_steps;
	unsigned char	optimized_flag;
    
	stack_a = stack_a;
	value = value;

    size = ft_stack_size(*stack_b);
	i = 0;
	optimized_flag = 0;
	if ((size_t)node_position <= size / 2)
    {
        num_steps = node_position;
		action = PRIMITIVE_RB;
    }
	else
	{
		num_steps = size - node_position;
		action = PRIMITIVE_RRB;
	}
	while ((size_t)i < num_steps)
	{		
		if (value > 0 && (*stack_b)->content == value -1)
		{
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
			optimized_flag = 1;
			if(action == PRIMITIVE_RRB)
				i--;
		}
		else
			ft_execute_action(NULL, stack_b, action);
		i++;
	}
	return (optimized_flag);
}
