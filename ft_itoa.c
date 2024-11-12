/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:02:18 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/12 15:27:56 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	minus(int *n, char *result, int *length)
{
	if (*n == -2147483648)
	{
		result[--(*length)] = '8';
		*n /= 10;
	}
	*n = -(*n);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;

	length = get_num_length(n);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
	{
		result[0] = '-';
		minus(&n, result, &length);
	}
	while (n)
	{
		result[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
