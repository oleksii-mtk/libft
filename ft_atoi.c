/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:58:30 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/13 15:45:21 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((minus * res) != (int)(minus * res))
		return (-1);
	return ((int)(minus * res));
}
