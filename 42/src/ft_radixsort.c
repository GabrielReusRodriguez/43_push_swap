/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:38:26 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 14:39:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_primitives.h"

static unsigned char	ft_bits_get_n_bit(int value, int n)
{
	int				shifted_value;

	shifted_value = value >> n;
	shifted_value = shifted_value % 2;
	return ((unsigned char)shifted_value);
}

static void ft_radixsort_iteration(t_stack **stack_a, t_stack **stack_b, size_t n)
{
	size_t	size;
	size_t	i;
	int		value;

	size = ft_stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		value = (*stack_a)->content;
		if (ft_bits_get_n_bit(value, n) == 1) 
			ft_execute_action(stack_a, stack_b, PRIMITIVE_RA);
		else
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PB);
		i++;
	}
	while(ft_stack_isempty(stack_b) == FALSE)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
}

/*
static void ft_radixsort_iteration(t_stack **stack_a, t_stack **stack_b, size_t n)
{
	//t_stack	*node;
	size_t	size;
	size_t	i;
	int		value;

	node = *stack_a;
	while (node != NULL)
	{
		value = node->content;
		node = node->next;
		if (ft_bits_get_n_bit(value, n) == 0)
		{
			
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PB);
		}
	}
		printf("\t\tValor primero iteracion\n");
		ft_stack_debug(*stack_a);
		ft_stack_debug(*stack_b);
		printf("\t\tFIN Valor primero iteracion\n");
	while(ft_stack_isempty(stack_b) == FALSE)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
}
*/
static size_t	ft_get_number_of_digits(t_stack *stack)
{
	size_t	num_digits;
	t_stack	*node;
	int		value;

	node = stack;
	value = INT_MIN;
	while (node != NULL)
	{
		if(node->content > value)
			value = node->content;
		node = node->next;
	}
	num_digits = 1;
	while (value / 2 != 0)
	{
		value = value / 2;
		num_digits++;
	}
	return (num_digits);
}

void	ft_radixsort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	num_digits;
	size_t	i;

	num_digits = ft_get_number_of_digits(*stack_a);
	i = 0;
	while (i < num_digits)
	{
		if (ft_stack_issorted(*stack_a) == TRUE)
			return ;
		ft_radixsort_iteration(stack_a, stack_b, i);
		i++;
	}
}
