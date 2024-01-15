/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitives.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:43:37 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 20:49:44 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIMITIVES_H
# define FT_PRIMITIVES_H

# define PRIMITIVE_SA "sa"
# define PRIMITIVE_SB "sb"
# define PRIMITIVE_SS "ss"
# define PRIMITIVE_PA "pa"
# define PRIMITIVE_PB "pb"
# define PRIMITIVE_RA "ra"
# define PRIMITIVE_RB "rb"
# define PRIMITIVE_RR "rr"
# define PRIMITIVE_RRA "rra"
# define PRIMITIVE_RRB "rrb"
# define PRIMITIVE_RRR "rrr"

#include "ft_stack.h"

void	ft_primitives_sa(t_stack **stack);
void	ft_primitives_sb(t_stack **stack);
void	ft_primitives_ss(t_stack **stack);
void	ft_primitives_pa(t_stack **stack);
void	ft_primitives_pb(t_stack **stack);
void	ft_primitives_ra(t_stack **stack);
void	ft_primitives_rb(t_stack **stack);
void	ft_primitives_rr(t_stack **stack);
void	ft_primitives_rra(t_stack **stack);
void	ft_primitives_rrb(t_stack **stack);
void	ft_primitives_rrr(t_stack **stack);

#endif