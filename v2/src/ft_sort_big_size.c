/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:41:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 12:34:21 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chunksort.h"

void	ft_sort_big_size(t_stack **stack_a, t_stack **stack_b)
{
	ft_chunk_sort(stack_a, stack_b);
}
