/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_size3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:50:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/04 17:50:37 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_stack_utils.h"
#include "ft_primitives.h"
#include "ft_sort.h"

int ft_sort3_next_mov(t_stack **stack, int order)
{
	int	content;
	int	content_next;

	content = ft_stack_content(*stack);
	content_next = ft_stack_content((*stack)->next);
	if (ft_stack_issorted(*stack, order) == 0)
	{
		if (ft_are_sorted_values(content, content_next, order) == 0)
			return (PRIMITIVE_SA);
		else
			return (PRIMITIVE_RRA);
	}
	return (PRIMITIVE_NO);	
}

void    ft_sort_size3(t_stack **stack_a, t_stack **stack_b, int order)
{
    int		stacka_action;

	while(ft_stack_isnsorted(*stack_a, 3, order) == 0 || ft_stack_isnsorted(*stack_b, 0, order) == 0)
	{
		stacka_action = ft_sort3_next_mov(stack_a, order);
		ft_execute_step(stacka_action, PRIMITIVE_NO, stack_a, NULL);    
	}
}