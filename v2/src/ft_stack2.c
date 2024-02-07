/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:01:26 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 19:50:31 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stack.h"
#include "libft.h"

void	ft_stack_clear(t_stack **stack)
{
	t_stack		*node;
	t_stack		*aux;

	node = *stack;
	while (node != NULL)
	{
		aux = node->next;
		free(node);
		node = aux;
	}
	stack = NULL;
}

/*
void	ft_stack_debug(const t_stack *stack)
{
	t_stack		*node;

	ft_putendl("STACK\n");
	if (stack == NULL)
		printf("empty...\n");
	else
	{
		node = (t_stack *)stack;
		while (node != NULL)
		{
			printf("%d\n", node->content);
			node = node->next;
		}
	}
	printf("----------------\n");
}
*/
int	*ft_stack_to_array(t_stack **stack)
{
	int		*contents;
	int		stack_size;
	t_stack	*node;
	size_t	i;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	stack_size = ft_stack_size(*stack);
	if (stack_size == 0)
		return (NULL);
	contents = (int *)malloc(stack_size * sizeof(int));
	if (contents == NULL)
		return (NULL);
	i = 0;
	node = *stack;
	while (node != NULL)
	{
		contents[i] = node->content;
		node = node->next;
		i++;
	}
	return (contents);
}

t_stack	*ft_stack_get_node(t_stack *stack, size_t n)
{
	t_stack	*node;
	size_t	size;
	size_t	i;

	size = ft_stack_size(stack);
	if (n == 0)
		return (stack);
	i = 0;
	node = stack;
	while (i < size)
	{
		if (i == n)
			return (node);
		i++;
		node = node->next;
	}
	return (NULL);
}
