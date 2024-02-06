/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_size5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:49:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/04 23:48:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_stack_utils.h"
#include "ft_primitives.h"
#include "ft_sort.h"

#include <stdio.h>

/*
void    ft_sort_size5(t_stack **stack_a, t_stack **stack_b, int order)
{
	int     stacka_action;
	int     stackb_action;
	size_t  i;

	ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
	ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
	while(ft_stack_isnsorted(*stack_a, 3, order) == 0)
	{
		stacka_action = ft_sort3_next_mov(stack_a, order);
		stackb_action= PRIMITIVE_NO;
		if (ft_stack_issorted(*stack_b, ft_get_inverse_order(order)) == 0 &&\
				stacka_action == PRIMITIVE_RRA)
			stackb_action = PRIMITIVE_RRB;
		ft_execute_step(stacka_action, stackb_action, stack_a, stack_b);
	}
	if (ft_stack_issorted(*stack_b, ft_get_inverse_order(order)) == 0)
		ft_execute_step(PRIMITIVE_NO, PRIMITIVE_RB, stack_a, stack_b);
	//Sorted stack a and stack b
	ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
	ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
	i = 0;
	while(ft_stack_issorted(*stack_a, order) == 0)
	{
		if (ft_stack_isnsorted(*stack_a, 2, order) == 0 && i < 5  - 1)
			ft_execute_action(stack_a,NULL, PRIMITIVE_SA);
		ft_execute_action(stack_a,NULL, PRIMITIVE_RA);
		ft_stack_debug(*stack_a);
		i++;
	}
}
*/

static void	ft_sort5_transfer_all(t_stack **stack_a, t_stack **stack_b, int order)
{
	int 	content_a;
	int		content_b;
	size_t	i;

	i = 0;
	/*
	printf("\tStack 1a\n");
	ft_stack_debug(*stack_a);
	printf("\tStack 1b\n");
	ft_stack_debug(*stack_b);
	*/
	//Mientras b no este vacio y no hayamos recorrido los 3 valores de stack a...
	while (ft_stack_isempty(stack_b) == 0 && i < 3)
	{
		content_a = ft_stack_content(*stack_a);
		content_b = ft_stack_content(*stack_b);
		//Comprobamos si el top de stack a y stack b estan ordenados, en caso que NO , 
		//movemos el top de ba al stack_a. 9es decir, si top b tiene que estar antes que top de stack b
		//Ademas hago rotacion para comprobar con el siuiente de stak b
		//En otras palabras, chequeamos si el valor de b iria debajo del top de a.
		//En caso que NO fuese debajo, lo colocamos encima.
		if (ft_are_sorted_values(content_a, content_b, order) == 1)
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
		else
			i++;
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RA);
		
			printf("\tStack a\n");
			ft_stack_debug(*stack_a);
			printf("\tStack b\n");
			ft_stack_debug(*stack_b);
		
	}

	printf("\tStack a\n");
	ft_stack_debug(*stack_a);
	printf("\tStack b\n");
	ft_stack_debug(*stack_b);

	//Si queda algo en b, hacemos un push a a
	if (i == 3)
	{
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RRB);
		while(ft_stack_isempty(stack_b) == 0)
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
	}
	//Rotamos la  pila a hasta que este ordenada.
	while (ft_stack_issorted(*stack_a, order) == 0)
		ft_execute_action(stack_a,stack_b, PRIMITIVE_RA);
}

void    ft_sort_size5(t_stack **stack_a, t_stack **stack_b, int order)
{
	int     stacka_action;
	int     stackb_action;

	ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
	ft_execute_action(stack_a,stack_b, PRIMITIVE_PB);
	while (ft_stack_issorted(*stack_a, order) == 0)
	{
		stacka_action = ft_sort3_next_mov(stack_a, order);
		stackb_action= PRIMITIVE_NO;
		if (ft_stack_issorted(*stack_b, order) == 0 &&\
				stacka_action == PRIMITIVE_RRA)
			stackb_action = PRIMITIVE_RRB;
		ft_execute_step(stacka_action, stackb_action, stack_a, stack_b);
	}
	if (ft_stack_issorted(*stack_b, ft_get_inverse_order(order)) == 0)
	//if (ft_stack_issorted(*stack_b, order) == 0)
		ft_execute_step(PRIMITIVE_NO, PRIMITIVE_RRB, stack_a, stack_b);
	
	printf("stack a\n");
	ft_stack_debug(*stack_a);
	printf("stack b\n");
	ft_stack_debug(*stack_b);
	
	//Sorted stack a and stack b
	ft_sort5_transfer_all(stack_a, stack_b, order);
	//ft_stack_debug(*stack_a);
	/*
	ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
	ft_execute_action(stack_a,stack_b, PRIMITIVE_PA);
	i = 0;
	while(ft_stack_issorted(*stack_a, order) == 0)
	{
		if (ft_stack_isnsorted(*stack_a, 2, order) == 0 && i < 5  - 1)
			ft_execute_action(stack_a,NULL, PRIMITIVE_SA);
		ft_execute_action(stack_a,NULL, PRIMITIVE_RA);
		ft_stack_debug(*stack_a);
		i++;
	}
	*/
}
