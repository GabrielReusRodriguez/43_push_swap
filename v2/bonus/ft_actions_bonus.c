/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:00:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 19:40:46 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitives_bonus.h"
#include "libft.h"

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
}

void	ft_execute_step(int stacka_action, int stackb_action, \
			t_stack **stack_a, t_stack **stack_b)
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
