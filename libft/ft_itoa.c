/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:53:56 by azeraoul          #+#    #+#             */
/*   Updated: 2021/01/31 23:20:16 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int nbr)
{
	int		len;

	len = 1;
	if (nbr < 0)
		++len;
	while ((nbr /= 10))
		++len;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	len = nbrlen(n);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len] = '\0';
	while (--len >= 0)
	{
		num[len] = 48 + (sign * (n % 10));
		n /= 10;
	}
	if (sign == -1)
		num[0] = '-';
	return (num);
}
