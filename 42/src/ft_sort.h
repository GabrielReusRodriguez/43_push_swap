/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:02:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/04 17:58:48 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "ft_stack.h"

# define ORDER_NO -1
# define ORDER_ASC 0
# define ORDER_DESC 1

int		ft_get_inverse_order(int order);
int     ft_are_sorted_values(int first, int next, int order);
int     ft_sort3_next_mov(t_stack **stack, int order);
void    ft_sort_size3(t_stack **stack_a, t_stack **stack_b, int order);
void    ft_sort_size5(t_stack **stack_a, t_stack **stack_b, int order);
void	ft_sort(t_stack **stack, t_stack **stack_b);


#endif