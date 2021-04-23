/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_convsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:14:21 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/23 15:17:19 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_convsize(t_param *el)
{
	int		plen;
	int		flen;
	int		pfix;
	char	c;

	c = el->type;
	flen = el->field_len;
	pfix = el->prefix.value;
	plen = el->precision.value;
	if (c == 'd' || c == 'i' || el->numeric.no_signed)
		numsize(el, plen, flen, pfix);
	else if (c == 'f' || c == 'e' || c == 'g')
		doublesize(el, flen);
	else if (c == 's')
		strsize(el, plen, flen);
	else
		charsize(el, flen);
}

void		doublesize(t_param *el, int flen)
{
	int		len;
	int		alen;
	int		wpfix;

	wpfix = el->prefix.write ? 0 : el->prefix.value;
	alen = (int)ft_strlen(el->value) - wpfix;
	len = flen > alen ? flen : alen;
	el->conversion_size = len;
}

void		numsize(t_param *el, int plen, int flen, int pfix)
{
	int		len;
	int		alen;
	int		wpfix;

	wpfix = el->prefix.write ? pfix : 0;
	alen = (int)ft_strlen(el->value) - pfix;
	if (flen > alen + wpfix && flen > plen)
		len = flen;
	else if (plen > alen)
		len = plen + wpfix;
	else
		len = alen + wpfix;
	el->conversion_size = len;
}

void		strsize(t_param *el, int plen, int flen)
{
	int		wplen;
	int		alen;
	int		len;

	wplen = el->precision.write;
	if (!flen && wplen && !plen)
		len = 0;
	else
	{
		alen = (int)ft_strlen(el->value);
		if ((flen > alen) || (flen && wplen && (!plen || plen < flen)))
			len = flen;
		else if (wplen && plen < alen)
			len = plen;
		else
			len = alen;
	}
	el->conversion_size = len;
}

void		charsize(t_param *el, int flen)
{
	if (flen)
		el->conversion_size = flen;
	else
		el->conversion_size = 1;
}
