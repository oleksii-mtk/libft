/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:19:00 by omatyko           #+#    #+#             */
/*   Updated: 2024/10/31 17:29:26 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	l_len;

	i = 0;
	l_len = 0;
	while (little[l_len] != '\0')
		l_len++;
	if (l_len == 0)
		return ((char *)big);
	while (big[i] != '\0' && (i < len))
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j < len))
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);	
}
