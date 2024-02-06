/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:02:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/05 23:12:39 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "ft_stack.h"

int		ft_sort3_next_mov(t_stack **stack);
void	ft_sort_size3(t_stack **stack_a);
void	ft_sort_size5(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_big_size(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack, t_stack **stack_b);

#endif