/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:27:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 18:04:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_index.h"
#include "libft.h"

static void	ft_bubble_sort(int	*values, size_t size)
{
	size_t	i;
	size_t	j;
	int		aux;

	if (values == NULL)
		return ;
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (values[j] > values[j + 1])
			{
				aux = values[j];
				values[j] = values[j + 1];
				values[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
}

static int	ft_index_of_node(int *indexs, size_t size, t_stack *node)
{
	size_t	i;

	if (indexs == NULL || node == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (node->content == indexs[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_set_index_2_node(t_stack *node, int *values, size_t size)
{
	int	index;

	index = ft_index_of_node(values, size, node);
	if (index == -1)
		return (-1);
	node->content = index;
	return (0);
}

t_stack	*ft_create_index_stack( t_stack	*stack)
{
	t_stack	*node;
	size_t	size;
	int		*values;
	size_t	i;
	int		index;

	if (stack == NULL)
		return (NULL);
	size = ft_stack_size(stack);
	values = ft_stack_to_array(&stack);
	if (values == NULL)
		return (NULL);
	ft_bubble_sort(values, size);
	i = 0;
	node = stack;
	while (i < size)
	{
		index = ft_set_index_2_node(node, values, size);
		if (index == -1)
			return (ft_ptr_free(values));
		node = node->next;
		i++;
	}
	free (values);
	return (stack);
}
