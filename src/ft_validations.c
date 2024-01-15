/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:34:58 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 20:32:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_validations.h"
#include "../libft/libft.h"

int	ft_isvalid_arg(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int	ft_isvalid_stack(t_stack **stack)
{
	t_stack	*node_review;
	t_stack	*node_aux;
	size_t	num_occurs;

	if (*stack == NULL)
		return (0);
	node_review = *stack;
	while (node_review != NULL)
	{
		num_occurs = 0;
		node_aux = *stack;
		while (node_aux != NULL)
		{
			if (*((int *)node_aux->content) == *((int *)node_review->content))
				num_occurs++;
			if (num_occurs > 1)
				return (0);
			node_aux = node_aux->next;
		}
		node_review = node_review->next;
	}
	return (1);
}
