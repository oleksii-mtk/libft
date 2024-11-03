/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:27:16 by omatyko           #+#    #+#             */
/*   Updated: 2024/11/03 22:31:38 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_memset(void *s, int c, size_t n)
{
    unsigned char *b;

    b = (unsigned char *)s;
    while (size_t > 0)
    {
        *(b++) = (unsigned char)c;
        size_t--;
    }
    return (b);
}