/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:31:14 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/12 00:38:19 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	ft_get_num_tokens(char *s, char c)
{
	unsigned int	num_tokens;

	num_tokens = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			return (num_tokens);
		while (*s != c && *s != '\0')
		{
			s++;
		}
		num_tokens++;
	}
	return (num_tokens);
}

char	**ft_split(char const *s, char c)
{
	char			**tokens;
	unsigned int	num_tokens;
	unsigned int	i;
	unsigned int	start;
	unsigned int	len;

	num_tokens = ft_get_num_tokens((char *)s, c);
	tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (i < num_tokens && s[start] != '\0')
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		len = 0;
		while (s[start + len] != c && s[start + len] != '\0')
			len++;
		if (len > 0)
			tokens[i++] = ft_substr(s, start, len);
		start = start + len;
	}
	tokens[i] = NULL;
	return (tokens);
}
