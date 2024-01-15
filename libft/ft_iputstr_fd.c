/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:31:02 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/14 22:38:18 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iputstr_fd(char *s, int fd)
{
	size_t	i;
	int		total_num_bytes;
	int		char_num_bytes;

	i = 0;
	total_num_bytes = 0;
	while (s[i] != '\0')
	{
		char_num_bytes = ft_iputchar_fd(s[i], fd);
		if (char_num_bytes >= 0)
			total_num_bytes = total_num_bytes + char_num_bytes;
		i++;
	}
	return (total_num_bytes);
}
