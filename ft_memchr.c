/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:08:42 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/12 12:16:19 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	b;

	p = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (*p == b)
		{
			return ((void *)p);
		}
		p++;
	}
	return (NULL);
}
