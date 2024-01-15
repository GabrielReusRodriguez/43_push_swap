/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:47:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/15 22:26:22 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_UTILS_H
# define FT_STACK_UTILS_H

# include "ft_stack.h"

void		ft_stack_debug(const t_stack *stack);
int			*ft_stack_to_array(t_stack **stack);


#endif