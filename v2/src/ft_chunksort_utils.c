/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:59:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 13:41:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_chunksort.h"
#include "ft_primitives.h"

int	ft_get_value_position(t_stack *stack, int value)
{
	size_t	i;
	t_stack	*node;

	node = stack;
	i = 0;
	while (node != NULL)
	{
		if (node->content == value)
		{
			return (i);
		}
		i++;
		node = node->next;
	}
	return (-1);
}
