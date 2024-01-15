/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:03:24 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/16 00:55:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_primitives.h"
# include "ft_stack_utils.h"
#include <stdio.h>

// 5 2 1 => Si a > b sa 2 5 1 => Si a < b rda  1 2 5
static void	ft_sort_3(t_stack **stack)
{
	while (ft_stack_issorted(*stack) == 0)
	{
		if (ft_stack_content(*stack) > ft_stack_content((*stack)->next))
		{
			printf("sa\n");
			ft_primitives_sx(stack);
			ft_stack_debug(*stack);
		}
		else
		{
			printf("rra\n");
			ft_primitives_rrx(stack);
			ft_stack_debug(*stack);
		}
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	stack_size;
	
	*stack_b = NULL;
	if (ft_stack_isempty(stack_a) == 1)
		return ;
	else
	{
		stack_size = ft_stack_size(*stack_a);
		if (stack_size == 3)
		{
			ft_sort_3(stack_a);
			return ;
		}
	}
}