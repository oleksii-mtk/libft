/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:18:43 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/04 13:57:59 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t count_words(char const *s, char c)
{
	size_t count;

	count = 0;
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

char **ft_split(char const *s, char c)
{
	char **res;
	size_t i;
	size_t len;

	i = 0;
	if (!s || !(res = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (!(res[i++] = strndup(s, len)))
				return (free_all(res, i));
			s += len;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}

