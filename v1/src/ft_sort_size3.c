/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_size3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:50:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 17:38:47 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitives.h"
#include "ft_sort.h"

int	ft_sort3_next_mov(t_stack **stack)
{
	int	content;
	int	content_next;

	content = (*stack)->content;
	content_next = (*stack)->next->content;
	if (content > content_next)
		return (PRIMITIVE_SA);
	else
		return (PRIMITIVE_RRA);
	return (PRIMITIVE_NO);
}

void	ft_sort_size3(t_stack **stack_a)
{
	int	stacka_action;

	while (ft_stack_issorted(*stack_a) == FALSE)
	{
		stacka_action = ft_sort3_next_mov(stack_a);
		ft_execute_action(stack_a, NULL, stacka_action);
	}
}
