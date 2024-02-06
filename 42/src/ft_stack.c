/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:01:26 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 14:39:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stack.h"

t_stack	*ft_stack_newnode(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_bool	ft_stack_isempty(t_stack **stack)
{
	if (*stack == NULL)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_stack_push(t_stack **stack, t_stack *node)
{
	if (node != NULL)
	{
		if (ft_stack_isempty(stack) == TRUE)
		{
			node->next = NULL;
			*stack = node;
		}
		else
		{
			node->next = *stack;
			*stack = node;
		}
	}
}

t_stack	*ft_stack_pop(t_stack **stack)
{
	t_stack	*node;

	if (ft_stack_isempty(stack) == TRUE)
		return (NULL);
	else
	{
		node = *stack;
		*stack = (*stack)->next;
		return (node);
	}
}

size_t	ft_stack_size(const t_stack *stack)
{
	size_t	size;

	size = 0;
	if (stack == NULL)
		return (size);
	else
	{
		while (stack != NULL)
		{
			stack = stack->next;
			size++;
		}
	}
	return (size);
}
