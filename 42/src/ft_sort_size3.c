/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_size3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:50:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/05 23:14:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_primitives.h"
#include "ft_sort.h"
#include <stdio.h>

int	ft_sort3_next_mov(t_stack **stack)
{
	int	content;
	int	content_next;

	content = (*stack)->content;
	content_next = (*stack)->next->content;
	if (ft_stack_issorted(*stack) == FALSE)
	{
		if (content > content_next)
			return (PRIMITIVE_SA);
		else
			return (PRIMITIVE_RRA);
	}
	return (PRIMITIVE_NO);
}

void	ft_sort_size3(t_stack **stack_a)
{
	int	stacka_action;

	while (ft_stack_issorted(*stack_a) == FALSE)
	{
		stacka_action = ft_sort3_next_mov(stack_a);
		ft_execute_step(stacka_action, PRIMITIVE_NO, stack_a, NULL);
	}
}
