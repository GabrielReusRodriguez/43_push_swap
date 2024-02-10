/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_logic_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:49:13 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/10 02:13:48 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stack_bonus.h"
#include "ft_utils_bonus.h"
#include "libft.h"
#include "ft_primitives_bonus.h"
#include "ft_get_next_line.h"

static t_bool	ft_checker_isvalid_action(char *line, size_t size)
{
	if (ft_strncmp(line, "pa\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "pb\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "sa\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "sb\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "ss\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "ra\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "rb\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "rr\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "rra\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "rrb\n", size) == 0)
		return (TRUE);
	if (ft_strncmp(line, "rrr\n", size) == 0)
		return (TRUE);
	return (FALSE);
}

static void	ft_checker_execute_step(t_stack **stack_a, t_stack **stack_b, \
				char *line, size_t size)
{
	if (ft_strncmp(line, "pa\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_PA);
	if (ft_strncmp(line, "pb\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_PB);
	if (ft_strncmp(line, "sa\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_SA);
	if (ft_strncmp(line, "sb\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_SB);
	if (ft_strncmp(line, "ss\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_SS);
	if (ft_strncmp(line, "ra\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RA);
	if (ft_strncmp(line, "rb\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RB);
	if (ft_strncmp(line, "rr\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RR);
	if (ft_strncmp(line, "rra\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RRA);
	if (ft_strncmp(line, "rrb\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RRB);
	if (ft_strncmp(line, "rrr\n", size) == 0)
		ft_execute_action(stack_a, stack_b, PRIMITIVE_RRR);
}

t_bool	ft_checker_loop(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	size_t	size;

	if (ft_stack_issorted(*stack_a) == TRUE && \
			ft_stack_isempty(stack_b) == TRUE)
		return (FALSE);
	line = ft_get_next_line_many_fds(STDIN_FILENO);
	if (line == NULL)
		return (FALSE);
	else
	{
		size = ft_strlen(line);
		if (ft_checker_isvalid_action(line, size) == FALSE)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			ft_stack_clear(stack_a);
			ft_stack_clear(stack_b);
			free(line);
			exit(EXIT_FAILURE);
		}
		ft_checker_execute_step(stack_a, stack_b, line, size);
		free(line);
		return (TRUE);
	}
}
