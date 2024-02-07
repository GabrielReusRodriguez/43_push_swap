/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:00:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 17:14:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitives.h"
#include "libft.h"

static void	ft_print_action(int action)
{
	if (action == PRIMITIVE_PA)
		ft_putendl_fd("pa", 1);
	if (action == PRIMITIVE_PB)
		ft_putendl_fd("pb", 1);
	if (action == PRIMITIVE_RA)
		ft_putendl_fd("ra", 1);
	if (action == PRIMITIVE_RB)
		ft_putendl_fd("rb", 1);
	if (action == PRIMITIVE_RR)
		ft_putendl_fd("rr", 1);
	if (action == PRIMITIVE_RRA)
		ft_putendl_fd("rra", 1);
	if (action == PRIMITIVE_RRB)
		ft_putendl_fd("rrb", 1);
	if (action == PRIMITIVE_RRR)
		ft_putendl_fd("rrr", 1);
	if (action == PRIMITIVE_SA)
		ft_putendl_fd("sa", 1);
	if (action == PRIMITIVE_SB)
		ft_putendl_fd("sb", 1);
	if (action == PRIMITIVE_SS)
		ft_putendl_fd("ss", 1);
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
