/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:26:31 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 15:12:26 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_uintoa(size_t nb, t_param *el)
{
	char	*res;
	char	c;

	c = el->type;
	if (c == 'p' || !(!nb && el->precision.write && !el->precision.value))
	{
		if (!nb && c != 'p')
			el->prefix.write = 0;
		if (c == 'X')
			res = sub_uintoa(nb, 2, "0123456789ABCDEF");
		else if (c == 'u')
			res = sub_uintoa(nb, 0, "0123456789");
		else
			res = sub_uintoa(nb, 1, "0123456789abcdef");
	}
	else
	{
		el->prefix.write = 0;
		el->prefix.value = 0;
		res = ft_strdup("");
	}
	return (res);
}

char		*sub_uintoa(size_t n, int flag, char *base)
{
	char	*tmp;
	char	*num;
	int		blen;
	int		len;

	blen = (int)ft_strlen(base);
	len = nbrlen(blen, n);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp[len] = '\0';
	while (--len >= 0)
	{
		tmp[len] = base[(n % blen)];
		n /= blen;
	}
	if (flag)
		num = (flag == 1) ? ft_strjoin("0x", tmp) : ft_strjoin("0X", tmp);
	else
		num = ft_strdup(tmp);
	free(tmp);
	return (num);
}

char		*ft_intoa(ssize_t nb, t_param *el)
{
	char	*res;

	if (nb < 0)
		el->prefix.write = 1;
	if (!(!nb && el->precision.write && !el->precision.value))
		res = sub_intoa(nb, el);
	else
	{
		if (el->plus)
			res = ft_strdup("+");
		else if (el->space)
			res = ft_strdup(" ");
		else
			res = ft_strdup("");
	}
	return (res);
}

char		*sub_intoa(ssize_t val, t_param *el)
{
	size_t	val2;
	char	*res;
	int		len;

	val2 = val < 0 ? -val : val;
	len = nbrlen(10, val2) + 1;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	while (--len > 0)
	{
		res[len] = (val2 % 10) + 48;
		val2 /= 10;
	}
	if (val >= 0)
		res[0] = el->space ? ' ' : '+';
	else
		res[0] = '-';
	return (res);
}

int			nbrlen(int base, size_t nbr)
{
	int		len;

	len = 1;
	while ((nbr /= base))
		++len;
	return (len);
}
