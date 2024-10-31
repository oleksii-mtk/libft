/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:13:35 by omatyko           #+#    #+#             */
/*   Updated: 2024/10/31 15:39:44 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	return_len;
	size_t	dst_len;
	int		i;

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
