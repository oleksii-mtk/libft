/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:58:50 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/08 16:37:56 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!src || !dest)
		return (0);
	s = (char *)src;
	d = (char *)dest;
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}
