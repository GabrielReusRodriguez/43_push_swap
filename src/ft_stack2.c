/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:01:26 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 22:39:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stack.h"
#include "ft_stack_utils.h"

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

int	*ft_stack_to_array(t_stack **stack)
{
		int		*contents;
		int		stack_size;
		t_stack	*node;
		size_t	i;

		stack_size = ft_stack_size(*stack);
		if (stack_size == 0)
			return (NULL);
		contents = (int *)malloc(sizeof(int));
		if (contents == NULL)
			return NULL;
		i = 0;
		node = *stack;
		while (node != NULL)
		{
			contents[i] = *((int *)node->content);
			node = node->next;
			i++;
		}
		return (contents);	
}

