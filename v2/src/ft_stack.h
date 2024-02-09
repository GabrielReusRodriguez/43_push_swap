/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:47:50 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 08:37:20 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>
# include "ft_utils.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

void		ft_stack_push(t_stack **stack, t_stack *node);
t_stack		*ft_stack_pop(t_stack **stack);
size_t		ft_stack_size(const t_stack *stack);
t_bool		ft_stack_isempty(t_stack **stack);
t_stack		*ft_stack_newnode(int content);
void		ft_stack_clear(t_stack **stack);
void		ft_stack_debug(const t_stack *stack);

void		ft_stack_debug(const t_stack *stack);
int			*ft_stack_to_array(t_stack **stack);
t_bool		ft_stack_issorted(const t_stack *stack);
t_bool		ft_stack_isnsorted(const t_stack *stack, size_t n);
t_stack		*ft_stack_get_node(t_stack *stack, size_t n);

#endif