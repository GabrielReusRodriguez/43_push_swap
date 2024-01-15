/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:01:26 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 20:41:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stack.h"

void	ft_stack_clear(t_stack **stack, void (*fr) (void *) )
{
	t_stack		*node;
	t_stack		*aux;

	node = *stack;
	while (node != NULL)
	{
		aux = node->next;
		(*fr)(node->content);
		free(node);
		node = aux;
	}
	*stack = NULL;
}

void	ft_stack_debug(const t_stack *stack)
{
	t_stack		*node;

	if (stack == NULL)
	{
		printf("STACK\n");
		printf("empty...\n");
	}
	else
	{
		node = (t_stack *)stack;
		printf("STACK\n");
		while (node != NULL)
		{
			printf("%d\n",*((int *)node->content));
			node = node->next;
		}
	}
	printf("----------------\n");
}
