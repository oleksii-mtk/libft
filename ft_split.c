/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:18:43 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/04 15:34:30 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count = 0;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}
#include <stdlib.h>

void	free_all(char **arr, size_t count)
{
	size_t	i;

	if (!arr)
		return;
	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i = 0, len;

	if (!s || !(res = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (!(res[i++] = ft_substr(s, 0, len)))
				return (free_all(res, i));
			s += len;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
