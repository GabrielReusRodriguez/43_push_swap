/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:34:58 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 19:05:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_validations_bonus.h"
#include "libft.h"

t_bool	ft_isvalid_arg(const char *str)
{
	size_t				i;
	char unsigned		has_digit;

	has_digit = FALSE;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) == TRUE)
	{
		has_digit = TRUE;
		i++;
	}
	if (str[i] == '\0' && has_digit == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

t_bool	ft_isvalid_stack(t_stack **stack)
{
	t_stack	*node_review;
	t_stack	*node_aux;
	size_t	num_occurs;

	if (*stack == NULL)
		return (FALSE);
	node_review = *stack;
	while (node_review != NULL)
	{
		num_occurs = 0;
		node_aux = *stack;
		while (node_aux != NULL)
		{
			if (node_aux->content == node_review->content)
				num_occurs++;
			if (num_occurs > 1)
				return (FALSE);
			node_aux = node_aux->next;
		}
		node_review = node_review->next;
	}
	return (TRUE);
}

t_bool	ft_stack_issorted(const t_stack *stack)
{
	t_stack	*node;
	int		content;
	int		content_next;

	if (stack == NULL)
		return (TRUE);
	node = (t_stack *)stack;
	while (node->next != NULL)
	{
		content = node->content;
		content_next = node->next->content;
		if (content > content_next)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

t_bool	ft_stack_isnsorted(const t_stack *stack, size_t n)
{
	t_stack	*node;
	int		content;
	int		content_next;
	size_t	i;

	if (stack == NULL)
		return (TRUE);
	i = 0;
	node = (t_stack *)stack;
	while (node->next != NULL && i < n)
	{
		content = node->content;
		content_next = node->next->content;
		if (content > content_next)
			return (FALSE);
		node = node->next;
		i = i + 2;
	}
	return (TRUE);
}
