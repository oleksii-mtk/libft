/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:02:43 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/04 12:00:46 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	int		i;

	src_len = 0;
	i = 0;
	if (size == 0)
		return (0);
	while (src[i] != '/0')
	{
		i++;
	}
	i = 0;
	while ((i < size) && (src[i] != '/0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '/0';
	return (src_len);
}
