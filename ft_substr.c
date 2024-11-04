/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:55:38 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/04 09:06:52 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t actual_len;
	char *str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	actual_len = ft_strlen(s + start);
	if (actual_len < len)
		len = actual_len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}