/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:34:05 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 19:05:16 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATIONS_H
# define FT_VALIDATIONS_H

# include "ft_stack_bonus.h"

t_bool	ft_isvalid_arg(const char *str);
t_bool	ft_isvalid_stack(t_stack **stack);

#endif