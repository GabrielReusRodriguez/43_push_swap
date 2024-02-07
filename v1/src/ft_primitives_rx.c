/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitives_rx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:50:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 19:30:13 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack.h"

void	ft_primitives_rx(t_stack **stack)
{
	int		*contents;
	size_t	stack_size;
	t_stack	*node;
	size_t	i;

	if (ft_stack_isempty(stack) == FALSE)
	{
		stack_size = ft_stack_size(*stack);
		contents = ft_stack_to_array(stack);
		if (contents == NULL)
			return ;
		i = 0;
		node = *stack;
		while (i < stack_size - 1)
		{
			node->content = contents[i + 1];
			i++;
			node = node->next;
		}
		node->content = contents[0];
		free (contents);
	}
}

void	ft_primitives_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_primitives_rx(stack_a);
	ft_primitives_rx(stack_b);
}
