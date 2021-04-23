/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_dblparam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:25:41 by azeraoul          #+#    #+#             */
/*   Updated: 2021/04/24 00:22:39 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			extract_double(t_param *el, va_list arg)
{
	size_t	*ptr;
	int		sign;
	char	*res;
	double	val;

	val = va_arg(arg, double);
	ptr = (size_t *)&val;
	sign = *ptr >> 63;
	if (sign)
		el->prefix.write = 1;
	if (!(res = check_limits(val, el)))
	{
		set_fplen(el);
		res = ft_dbltoa(val, sign, el->precision.value, el);
	}
	el->value = res;
	return (el->value ? 0 : -1);
}

char		*ft_dbltoa(double nb, int sign, int plen, t_param *el)
{
	char	*res;
	int		len;
	int		exp;

	exp = 0;
	len = lil_nblen(nb);
	if (nb < 1.0 && nb > -1.0 && el->type == 'g')
	{
		if (plen < 3)
		{
			if (len < 4)
				plen += len > 1 ? len + 1 : len;
		}
		else
			plen += len < 4 ? len : 0;
	}
	if (el->type == 'f')
		res = sub_ftoa(nb, plen, el);
	else if (el->type == 'e')
		res = sub_exptoa(nb, plen, el);
	else
		res = sub_gtoa(nb, plen, exp, el);
	if (sign)
		res[0] = '-';
	return (res);
}

char		*make_left(double nb, int plen, t_param *el)
{
	char	*tmp;
	char	*left;

	tmp = sub_intoa((ssize_t)nb, el);
	if (nb < 0)
		tmp[0] = '-';
	if (el->sharp || plen)
		left = ft_strjoin(tmp, ".");
	else
		left = ft_strdup(tmp);
	free(tmp);
	return (left);
}

t_ul		make_right(double *nb, int plen)
{
	double	nb2;
	t_ul	right;

	nb2 = ft_abs(*nb);
	nb2 = (nb2 - (long)(ft_abs(*nb))) * ft_pow(10, plen + 1);
	if ((long)nb2 % 10 > 4)
	{
		nb2 = (nb2) / 10 + 1;
		if ((long)nb2 == (long)ft_pow(10, plen)
			&& (nb2 - ft_pow(10, plen) > 0.5 || (long)(*nb) % 2))
			(*nb) += (*nb) > 0 ? 1 : -1;
	}
	else
		nb2 = (nb2) / 10;
	right = (t_ul)nb2;
	return (right);
}

void		write_double(char **buff, char *val, int len, t_param *el)
{
	int		index;
	int		pfix;

	pfix = el->prefix.value;
	set_buffer((*buff), el);
	index = el->adjust ? -1 : el->conversion_size;
	if (el->adjust)
	{
		while (++index < pfix && el->prefix.write)
			(*buff)[index] = val[index];
		while (val[pfix])
			(*buff)[index++] = val[pfix++];
	}
	else
	{
		while (len-- > pfix)
			(*buff)[--index] = val[len];
		while (el->zero && index > pfix)
			--index;
		if (el->prefix.write && el->prefix.value)
			(*buff)[--index] = val[0];
	}
	(*buff) += el->conversion_size;
}
