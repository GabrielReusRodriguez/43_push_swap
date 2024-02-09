/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitives_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:43:37 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 19:06:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIMITIVES_H
# define FT_PRIMITIVES_H

# define PRIMITIVE_NO 0
# define PRIMITIVE_SA 1
# define PRIMITIVE_SB 2
# define PRIMITIVE_SS 3
# define PRIMITIVE_PA 4
# define PRIMITIVE_PB 5
# define PRIMITIVE_RA 6
# define PRIMITIVE_RB 7
# define PRIMITIVE_RR 8
# define PRIMITIVE_RRA 9
# define PRIMITIVE_RRB 10
# define PRIMITIVE_RRR 11

# include "ft_stack_bonus.h"

void	ft_primitives_sx(t_stack **stack);
void	ft_primitives_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_primitives_px(t_stack **src, t_stack **dest);
void	ft_primitives_rx(t_stack **stack);
void	ft_primitives_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_primitives_rrx(t_stack **stack);
void	ft_primitives_rrr(t_stack **stack, t_stack **stack_b);
void	ft_execute_action(t_stack **stack, t_stack **stack_b, int action);
void	ft_execute_step(int stacka_action, int stackb_action, \
			t_stack **stack_a, t_stack **stack_b);

#endif