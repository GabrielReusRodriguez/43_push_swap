/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:03:24 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 14:41:34 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	stack_size;

	*stack_b = NULL;
	if (ft_stack_isempty(stack_a) == TRUE)
		return ;
	else
	{
		stack_size = ft_stack_size(*stack_a);
		if (stack_size <= 3)
		{
			ft_sort_size3(stack_a);
			return ;
		}
		if (stack_size <= 5)
		{
			ft_sort_size5(stack_a, stack_b);
			return ;
		}
		if (stack_size > 5)
		{
			ft_sort_big_size(stack_a, stack_b);
			return ;
		}
	}
}
