/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:59:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 12:21:49 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_chunksort.h"
#include "ft_primitives.h"
/*
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
	if(node == NULL)
		return (-1);
	while (node != NULL)
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
*/
/*
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
	while (node != NULL)
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
*/
/*
void	ft_stackb_min_to_top(t_stack **stack_b)
{
	int		min_position;
	min_position = ft_get_min_position(*stack_b);
	if(min_position == -1)
		return ;
	ft_stackb_node_to_top(stack_b, min_position);
}
*/


int	ft_get_value_position(t_stack *stack, int value)
{
	size_t	i;
	t_stack	*node;

	node = stack;
	i = 0;
	while (node != NULL)
	{
		if(node->content == value)
		{
			return (i);
		}
		i++;
		node = node->next;
	}
	return (-1);
}

/*
void	ft_stackb_max_to_top(t_stack **stack_b)
{
	int		max_position;

	max_position = ft_get_max_position(*stack_b);
	ft_stackb_node_to_top(stack_b, max_position);
}*/
/*
void	ft_stackb_max_to_top2(t_stack **stack_b, int value_max)
{
	int		max_position;

	max_position = ft_get_value_position(*stack_b, value_max);
	ft_stackb_node_to_top(stack_b, max_position);
}
*/