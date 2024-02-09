/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:28:20 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 12:36:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "ft_stack.h"
#include "ft_validations.h"
#include "ft_primitives.h"
#include "ft_sort.h"
#include "ft_index.h"

static int	ft_inform_error(void)
{
	ft_putendl_fd("Error", 2);
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
	t_stack		*stack_a;
	t_stack		*stack_b;

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
	if (ft_create_index_stack(stack_a) == NULL)
		return (ft_inform_error());
	ft_sort(&stack_a, &stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
