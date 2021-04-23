/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:18:40 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 15:07:14 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_buffer(char *buff, t_param *el)
{
	if (el->zero)
		ft_memset(buff, '0', el->conversion_size);
	else
		ft_memset(buff, ' ', el->conversion_size);
}

double		ft_abs(double nb)
{
	return (nb > 0.0f ? nb : -nb);
}

double		ft_pow(double nb, int pow)
{
	double	res;

	res = 1.0;
	if (pow > 0)
	{
		while (pow--)
			res *= nb;
	}
	else if (pow < 0)
	{
		while (pow++ < 0)
			res /= nb;
	}
	else
		return (1);
	return (res);
}

int			lil_nblen(double n)
{
	int		i;

	i = 0;
	while (++i)
	{
		n *= ft_pow(10, i);
		if (((t_ul)n && i < 4) || i >= 4)
			break ;
	}
	return (i);
}

char		*check_limits(double nb, t_param *el)
{
	char	*res;

	if (nb != nb)
		res = ft_strdup("nan");
	else if (nb == -1.0 / 0.0)
		res = ft_strdup("-inf");
	else if (nb == 1.0 / 0.0)
		res = ft_strdup("inf");
	else
		res = NULL;
	if (res)
	{
		el->prefix.value = 0;
		el->zero = 0;
	}
	return (res);
}
