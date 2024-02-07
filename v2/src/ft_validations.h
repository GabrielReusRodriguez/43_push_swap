/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:34:05 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/05 22:29:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATIONS_H
# define FT_VALIDATIONS_H

# include "ft_stack.h"

t_bool	ft_isvalid_arg(const char *str);
t_bool	ft_isvalid_stack(t_stack **stack);

#endif