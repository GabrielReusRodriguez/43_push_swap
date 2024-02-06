/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_size5 copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:49:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/04 18:13:26 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_stack_utils.h"
#include "ft_primitives.h"
#include "ft_sort.h"


static void ft_sort_transfer_to_a(t_stack **stack_a, t_stack **stack_b,\
                int order)
{
    size_t i;
    
    i = 0;
	while(ft_stack_isempty(stack_b) == 0)
	{
		if (ft_are_sorted_values(ft_stack_content(*stack_a), \
                ft_stack_content(*stack_b), order) == 1)
		{
			if(i == 3 - 1)
				ft_execute_action(stack_a,stack_b, PRIMITIVE_RR);
			else
				ft_execute_action(stack_a,stack_b, PRIMITIVE_RA);
			i++;
		}
		else
		{
			ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
			i--;
		}
		if( i == 3 )
		{					
			if (ft_are_sorted_values(ft_stack_content(*stack_a), \
                    ft_stack_content(*stack_b), order) == 0)
				ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
			else
				while (ft_stack_isempty(stack_b) == 0)
					ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
		}
	}
}

void    ft_sort_size5(t_stack **stack_a, t_stack **stack_b, int order)
{
    int     stacka_action;
    int     stackb_action;
    size_t  i;

	ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
	ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
	while(ft_stack_isnsorted(*stack_a, 3, order) == 0)
	{
		stacka_action = ft_sort3_next_mov(stack_a, order);
		stackb_action= PRIMITIVE_NO;
		if (ft_stack_issorted(*stack_b, ft_get_inverse_order(order)) == 0 &&\
                stacka_action == PRIMITIVE_RRA)
			stackb_action = PRIMITIVE_RRB;
		ft_execute_step(stacka_action, stackb_action, stack_a, stack_b);
	}
    if (ft_stack_issorted(*stack_b, ft_get_inverse_order(order)) == 0)
		ft_execute_step(PRIMITIVE_NO, PRIMITIVE_RB, stack_a, stack_b);
	ft_execute_step(PRIMITIVE_NO, PRIMITIVE_PA, stack_a, stack_b);
	ft_execute_step(PRIMITIVE_NO, PRIMITIVE_PA, stack_a, stack_b);
	while(ft_stack_issorted(*stack_a, order) == 0)
	{
		if (ft_stack_isnsorted(*stack_a, 2, order) == 0)
			ft_execute_step(PRIMITIVE_SA, PRIMITIVE_NO, stack_a, stack_b);
		ft_execute_step(PRIMITIVE_RRA, PRIMITIVE_NO, stack_a, stack_b);
	}
}