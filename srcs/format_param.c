/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:45:41 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/24 07:37:31 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_adjusted(char **buff, int pad, int pfix, t_param *el)
{
	char	*val;
	int		index;

	index = -1;
	val = el->value;
	while (++index < pfix && el->prefix.write)
		(*buff)[index] = val[index];
	while (pad--)
		(*buff)[index++] = '0';
	while (val[pfix])
		(*buff)[index++] = val[pfix++];
	(*buff) += el->conversion_size;
}

void		simple_write(char **buff, int pad, int pfix, t_param *el)
{
	char	*val;
	int		index;
	int		len;

	val = el->value;
	len = (int)ft_strlen(val);
	index = el->conversion_size;
	while (len-- > pfix)
		(*buff)[--index] = val[len];
	while (pad--)
		(*buff)[--index] = '0';
	while (el->zero && index > pfix)
		--index;
	while (el->prefix.write && pfix--)
		(*buff)[--index] = val[pfix];
	(*buff) += el->conversion_size;
}

void		write_num(char **buff, int len, t_param *el)
{
	int		pfix;
	int		plen;
	int		pad;

	plen = el->precision.value;
	pfix = (len > 1) ? el->prefix.value : 0;
	pad = ((plen > len - pfix) ? plen - len + pfix : 0);
	set_buffer((*buff), el);
	if (el->adjust)
		write_adjusted(buff, pad, pfix, el);
	else
		simple_write(buff, pad, pfix, el);
}

void		write_str(char **buff, char *val, int len, t_param *el)
{
	int		index;
	int		plen;
	int		lim2;
	int		lim;

	lim = el->conversion_size;
	plen = el->precision.value;
	set_buffer((*buff), el);
	if (!(el->precision.write && !plen))
	{
		if (plen)
			lim2 = plen > len ? len : plen;
		else
			lim2 = len;
		index = lim - lim2;
		if (el->adjust)
			index = 0;
		while (*val && lim2-- && index < lim)
			(*buff)[index++] = *val++;
	}
	(*buff) += lim;
}

void		write_char(char **buff, char *val, t_param *el)
{
	int		lim;

	if (el->type != 'n')
	{
		lim = el->conversion_size;
		set_buffer((*buff), el);
		if (el->adjust)
			(*buff)[0] = *val;
		else
			(*buff)[lim - 1] = *val;
		(*buff) += lim;
	}
}
