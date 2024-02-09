/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:19:59 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 13:42:08 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunksort.h"
#include "ft_primitives.h"

void	ft_stacka_node_to_top(t_stack **stack_a, int node_position)
{
	size_t	size;
	int		i;
	int		action;
	size_t	num_steps;

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

static void	ft_determine_way_2_push(int node_position, size_t size, \
			int *action, size_t *num_steps)
{
	if ((size_t)node_position <= size / 2)
	{
		*num_steps = node_position;
		*action = PRIMITIVE_RB;
	}
	else
	{
		*num_steps = size - node_position;
		*action = PRIMITIVE_RRB;
	}
}

int	ft_stackb_node_to_top(t_stack **stack_a, t_stack **stack_b, \
		int node_position, int value)
{
	size_t			size;
	int				i;
	int				action;
	size_t			num_steps;
	unsigned char	optimized_flag;

	size = ft_stack_size(*stack_b);
	i = 0;
	optimized_flag = 0;
	ft_determine_way_2_push(node_position, size, &action, &num_steps);
	while ((size_t)i < num_steps)
	{
		if (value > 0 && (*stack_b)->content == value -1)
		{
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
			optimized_flag = 1;
			if (action == PRIMITIVE_RRB)
				i--;
		}
		else
			ft_execute_action(NULL, stack_b, action);
		i++;
	}
	return (optimized_flag);
}
