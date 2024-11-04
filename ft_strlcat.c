/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:13:35 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/04 14:37:26 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	res_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	res_len = 0;
	while (src[res_len] != '\0')
		res_len++;
	res_len = res_len + dst_len - 1;
	i = 0;
	size = size - dst_len - 1;
	while (src[i] != '\0' && i < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len] = '\0';
	return (res_len);
}
