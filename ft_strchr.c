/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:42:50 by omatyko           #+#    #+#             */
/*   Updated: 2024/10/31 16:00:29 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	*res = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (res);
}
