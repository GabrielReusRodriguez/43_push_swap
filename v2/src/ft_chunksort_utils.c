/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:59:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 21:23:14 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_chunksort.h"
#include "ft_primitives.h"

int	ft_get_min_position(t_stack *stack)
{
	size_t	i;
	int		min_value;
	int		min_position;
	t_stack	*node;

	min_value = INT_MAX;
	node = stack;
	i = 0;
	min_position = -1;
	while (node->next != NULL)
	{
		if(node->content < min_value)
		{
			min_value = node->content;
			min_position = i;
		}
		i++;
		node = node->next;
	}
	return (min_position);
}

int	ft_get_max_position(t_stack *stack)
{
	size_t	i;
	int		max_value;
	int		max_position;
	t_stack	*node;

	max_value = INT_MIN;
	node = stack;
	i = 0;
	max_position = -1;
	while (node->next != NULL)
	{
		if(node->content > max_value)
		{
			max_value = node->content;
			max_position = i;
		}
		i++;
		node = node->next;
	}
	return (max_position);
}

void	ft_stackb_min_to_top(t_stack **stack_b)
{
	int		min_position;
	size_t	size;
	int		i;
	int		action;

	size = ft_stack_size(*stack_b);
	i = 0;
	min_position = ft_get_min_position(*stack_b);
	if ((size_t)min_position < size / 2)
		action = PRIMITIVE_RRB;
	else
	{
		min_position = size - min_position + 1;
		action = PRIMITIVE_RB;
	}
	while (i < min_position)
	{
		ft_execute_action(NULL, stack_b, action);
		i++;
	}
}

void	ft_stackb_max_to_top(t_stack **stack_b)
{
	int		max_position;
	size_t	size;
	int		i;
	int		action;

	size = ft_stack_size(*stack_b);
	i = 0;
	max_position = ft_get_max_position(*stack_b);
	if ((size_t)max_position < size / 2)
		action = PRIMITIVE_RRB;
	else
	{
		max_position = size - max_position + 1;
		action = PRIMITIVE_RB;
	}
	while (i < max_position)
	{
		ft_execute_action(NULL, stack_b, action);
		i++;
	}
}

