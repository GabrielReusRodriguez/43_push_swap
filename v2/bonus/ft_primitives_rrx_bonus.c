/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitives_rrx_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:50:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 19:05:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack_bonus.h"

void	ft_primitives_rrx(t_stack **stack)
{
	int		*contents;
	size_t	stack_size;
	t_stack	*node;
	size_t	i;

	if (ft_stack_isempty(stack) == 0)
	{
		stack_size = ft_stack_size(*stack);
		contents = ft_stack_to_array(stack);
		if (contents == NULL)
			return ;
		i = 0;
		node = *stack;
		node->content = contents[stack_size -1];
		node = node->next;
		while (node != NULL)
		{
			node->content = contents[i];
			i++;
			node = node->next;
		}
		free (contents);
	}
}

void	ft_primitives_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_primitives_rrx(stack_a);
	ft_primitives_rrx(stack_b);
}
