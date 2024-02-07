/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:41:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 18:50:10 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_radixsort.h"

void	ft_sort_big_size(t_stack **stack_a, t_stack **stack_b)
{
	ft_radixsort(stack_a, stack_b);
}
