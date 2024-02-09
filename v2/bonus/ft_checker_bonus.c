/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:31 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 20:18:51 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "ft_stack_bonus.h"
#include "ft_validations_bonus.h"
#include "ft_primitives_bonus.h"
#include "ft_stack_bonus.h"
#include "ft_utils_bonus.h"
#include "ft_checker_logic_bonus.h"

static int	ft_inform_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (1);
}

static void	*push_new_content(const char *str_number, t_stack **stack)
{
	t_stack	*node;
	long	content;

	content = ft_atol(str_number);
	if (content > INT_MAX || content < INT_MIN)
		return (NULL);
	node = ft_stack_newnode(content);
	if (node == NULL)
	{
		ft_stack_clear(stack);
		return (NULL);
	}
	ft_stack_push(stack, node);
	return (node);
}

static t_stack	*fill_stack(int argc, char **argv)
{
	int			i;
	t_stack		*stack;

	stack = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		if (ft_isvalid_arg(argv[i]) == FALSE)
			return (NULL);
		if (push_new_content(argv[i], &stack) == NULL)
			return (NULL);
		i--;
	}
	return (stack);
}


int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_bool			loop;

	if (argc == 1)
		return (1);
	if (argc < 2)
		return (ft_inform_error());
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		return (ft_inform_error());
	stack_b = fill_stack(0, NULL);
	if (ft_isvalid_stack(&stack_a) == FALSE)
		return (ft_inform_error());
	loop = TRUE;
	while (loop == TRUE)
		loop = ft_checker_loop(&stack_a, &stack_b);		
	if (ft_stack_issorted(stack_a))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	//ft_stack_debug(stack_a);
	//ft_stack_debug(stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
