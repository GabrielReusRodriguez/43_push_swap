/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_size5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:49:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/06 14:42:11 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitives.h"
#include "ft_sort.h"

static void ft_push_less_values_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_b) < 2)
	{
		if ((*stack_a)->content == 0 || (*stack_a)->content == 1)
			ft_execute_action(stack_a, stack_b, PRIMITIVE_PB);
		else
			ft_execute_action(stack_a, NULL, PRIMITIVE_RRA);
	}	
}

/*
* Primero busco los dos indices 0 y 1 ( los valores mas pequeños ) y los 
coloco al final de la pila b . Me aseguro que sea el 1 el top para que
al volver con push queden ordenados

* Luego me encargo del ultimo. Si el Ultimo de lo que me qued aen la pila A
	es el último paso al siguiente paso si no...-.
	En caso que el primero sea el ultimo indice , lo traslado hacia arriba para
	que quede el ultimo
	En caso que no , solo nos queda que sea el sgeundo por lo que lo muevo 
	hacia abajo.

* Ya solo nos quedan ordenar los 2 valores intermedios de A ( que NO son el
ultimo xq ya lo hemos colocado antes...)

* Por ultimo hacemos los opush de b-> a
*/
void	ft_sort_size5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_node_a;
	int		last_index;
	int		last_position;
	
	last_index = ft_stack_size(*stack_a) - 1;
	ft_push_less_values_to_b(stack_a, stack_b);
	if ((*stack_b)->content == 0)
		ft_execute_action(NULL, stack_b, PRIMITIVE_SB);
	//node = ft_stack_get_node(*stack_a, 2);
	last_position = ft_stack_size(*stack_a) - 1;
	last_node_a = ft_stack_get_node(*stack_a, last_position);
	if (last_node_a == NULL)
		return ;
	//if (node->content != 4)
	if (last_node_a->content != last_index)
	{
		//if ((*stack_a)->content == 4)
		if ((*stack_a)->content == last_index)
			ft_execute_action(stack_a, NULL, PRIMITIVE_RA);
		else
			ft_execute_action(stack_a, NULL, PRIMITIVE_RRA);
	}
	if ( (*stack_a)->content  > (*stack_a)->next->content )
		ft_execute_action(stack_a, NULL, PRIMITIVE_SA);
	ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
	ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
}

/*

void	sort_four_to_five_elements(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push("pb", s);
		else
			rotate(s->a, s->a_size, "up", "a");
	}
	if (s->b[0] == 0)
		swap("sb", s->b, s->b_size);
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			rotate(s->a, s->a_size, "up", "a");
		else
			rotate(s->a, s->a_size, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	push("pa", s);
	push("pa", s);
}

*/