/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:37:38 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 15:12:38 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_pflag(t_param *el)
{
	if (el->zero && (el->adjust || (el->precision.write &&
		el->type != 'f' && el->type != 'e' && el->type != 'g')))
		el->zero = 0;
	if (el->space && el->plus)
		el->space = 0;
}

void		set_ptype(t_param *el)
{
	char	c;

	c = el->type;
	if (c == 'p' || c == 'x' || c == 'X' || c == 'u')
		el->numeric.no_signed = 1;
	else if (c == 'd' || c == 'i' || c == 'f' || c == 'e' || c == 'g')
		el->numeric.is_signed = 1;
}

void		set_ppfix(t_param *el)
{
	char	c;

	c = el->type;
	if (el->numeric.is_signed)
	{
		if (el->space || el->plus)
			el->prefix.write = 1;
		el->prefix.value = 1;
	}
	if (el->numeric.no_signed)
	{
		el->plus = 0;
		el->space = 0;
		if (c != 'u')
		{
			if (el->sharp || c == 'p')
				el->prefix.write = 1;
			el->prefix.value = 2;
		}
	}
}

void		set_fplen(t_param *el)
{
	if (el->precision.write && !el->precision.value)
	{
		if (el->type == 'g')
			el->precision.value = 1;
		else
			el->precision.value = 0;
	}
	if (!el->precision.write)
		el->precision.value = 6;
}
