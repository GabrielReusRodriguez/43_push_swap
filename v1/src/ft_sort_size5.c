/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_size5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:49:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 18:06:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitives.h"
#include "ft_sort.h"

static void	ft_push_less_values_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_b) < 2)
	{
		if ((*stack_a)->content == 0 || (*stack_a)->content == 1)
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PB);
		else
			ft_execute_action(stack_a, NULL, PRIMITIVE_RRA);
	}
}

void	ft_sort_size5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_node_a;
	int		last_index;
	int		last_position;

	last_index = ft_stack_size(*stack_a) - 1;
	ft_push_less_values_to_b(stack_a, stack_b);
	if ((*stack_b)->content == 0)
		ft_execute_action(NULL, stack_b, PRIMITIVE_SB);
	last_position = ft_stack_size(*stack_a) - 1;
	last_node_a = ft_stack_get_node(*stack_a, last_position);
	if (last_node_a == NULL)
		return ;
	if (last_node_a->content != last_index)
	{
		if ((*stack_a)->content == last_index)
			ft_execute_action(stack_a, NULL, PRIMITIVE_RA);
		else
			ft_execute_action(stack_a, NULL, PRIMITIVE_RRA);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_execute_action(stack_a, NULL, PRIMITIVE_SA);
	ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
	ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
}
