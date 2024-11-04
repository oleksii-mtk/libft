/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:28:07 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/04 00:39:46 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st1;
	unsigned char *st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if ((*st1 != *st2))
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	return (0);
}