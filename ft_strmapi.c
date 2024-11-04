/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:40:32 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/04 10:41:50 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t i;
	char *result;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}