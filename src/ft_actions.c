/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:00:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/21 02:47:31 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_primitives.h"

static void	ft_print_action(int action)
{
	if (action == PRIMITIVE_PA)
		printf("\tpa\n");
	if (action == PRIMITIVE_PB)
		printf("\tpb\n");
	if (action == PRIMITIVE_RA)
		printf("\tra\n");
	if (action == PRIMITIVE_RB)
		printf("\trb\n");
	if (action == PRIMITIVE_RR)
		printf("\trr\n");
	if (action == PRIMITIVE_RRA)
		printf("\trra\n");
	if (action == PRIMITIVE_RRB)
		printf("\trrb\n");
	if (action == PRIMITIVE_RRR)
		printf("\trrr\n");
	if (action == PRIMITIVE_SA)
		printf("\tsa\n");
	if (action == PRIMITIVE_SB)
		printf("\tsb\n");
	if (action == PRIMITIVE_SS)
		printf("\tss\n");
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
