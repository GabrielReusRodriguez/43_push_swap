/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:59:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/07 21:13:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHUNKSORT_H
# define FT_CHUNKSORT_H

# include "ft_stack.h"

typedef struct s_chunk
{
	size_t  min;
	size_t  max;
}	t_chunk;

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_chunk_iteration(t_stack **stack_a, t_stack **stack_b, \
			t_chunk chunk);
void	ft_stackb_min_to_top(t_stack **stack_b);
void	ft_stackb_max_to_top(t_stack **stack_b);
void	ft_stacka_min_to_top(t_stack **stack_a);
void	ft_stacka_max_to_top(t_stack **stack_a);
void	ft_stacka_node_to_top(t_stack **stack_a, int node_position);
void	ft_stackb_node_to_top(t_stack **stack_b, int node_position);
int		ft_get_min_position(t_stack *stack);
int		ft_get_max_position(t_stack *stack);

#endif