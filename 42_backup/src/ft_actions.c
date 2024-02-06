/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:00:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/04 17:12:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitives.h"
#include <stdio.h>

static void	ft_print_action(int action)
{
	if (action == PRIMITIVE_PA)
		printf("pa\n");
	if (action == PRIMITIVE_PB)
		printf("pb\n");
	if (action == PRIMITIVE_RA)
		printf("ra\n");
	if (action == PRIMITIVE_RB)
		printf("rb\n");
	if (action == PRIMITIVE_RR)
		printf("rr\n");
	if (action == PRIMITIVE_RRA)
		printf("rra\n");
	if (action == PRIMITIVE_RRB)
		printf("rrb\n");
	if (action == PRIMITIVE_RRR)
		printf("rrr\n");
	if (action == PRIMITIVE_SA)
		printf("sa\n");
	if (action == PRIMITIVE_SB)
		printf("sb\n");
	if (action == PRIMITIVE_SS)
		printf("ss\n");
}

void	ft_execute_action(t_stack **stack_a, t_stack **stack_b, int action)
{
	if (action == PRIMITIVE_NO)
		return ;
	if (action == PRIMITIVE_PA)
		ft_primitives_px(stack_b, stack_a);
	if (action == PRIMITIVE_PB)
		ft_primitives_px(stack_a, stack_b);
	if (action == PRIMITIVE_RA)
		ft_primitives_rx(stack_a);
	if (action == PRIMITIVE_RB)
		ft_primitives_rx(stack_b);
	if (action == PRIMITIVE_RR)
		ft_primitives_rr(stack_a, stack_b);
	if (action == PRIMITIVE_RRA)
		ft_primitives_rrx(stack_a);
	if (action == PRIMITIVE_RRB)
		ft_primitives_rrx(stack_b);
	if (action == PRIMITIVE_RRR)
		ft_primitives_rrr(stack_a, stack_b);
	if (action == PRIMITIVE_SA)
		ft_primitives_sx(stack_a);
	if (action == PRIMITIVE_SB)
		ft_primitives_sx(stack_b);
	if (action == PRIMITIVE_SS)
		ft_primitives_ss(stack_a, stack_b);
	ft_print_action(action);
}

void	ft_execute_step(int stacka_action, int stackb_action, t_stack **stack_a, t_stack **stack_b)
{
	if (stacka_action == PRIMITIVE_RA && stackb_action == PRIMITIVE_RB)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RR);
		return ;
	}
	if (stacka_action == PRIMITIVE_SA && stackb_action == PRIMITIVE_SB)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_SS);
		return ;
	}
	if (stacka_action == PRIMITIVE_RRA && stackb_action == PRIMITIVE_RRB)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RRR);
		return ;
	}
	ft_execute_action(stack_a, NULL, stacka_action);
	ft_execute_action(NULL, stack_b, stackb_action);

}