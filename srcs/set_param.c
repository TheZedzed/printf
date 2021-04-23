/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:25:56 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 11:45:55 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			set_arg(t_param *el, int len, va_list arg)
{
	int		err;
	char	c;

	c = el->type;
	if (c == 'd' || c == 'i')
		err = extract_int(el, arg);
	else if (c == 'n')
		err = extract_len(el, len, arg);
	else if (el->numeric.no_signed)
		err = extract_uint(el, arg);
	else if (c == 'f' || c == 'e' || c == 'g')
		err = extract_double(el, arg);
	else if (c == 's')
		err = extract_str(el, arg);
	else
		err = extract_char(el, arg);
	if (c != 'n')
		set_convsize(el);
	return (err);
}

void		set_flags(char **s, t_param *el)
{
	char	*ptr;

	ptr = (*s);
	if (*ptr == '-')
		el->adjust = 1;
	else if (*ptr == '+')
		el->plus = 1;
	else if (*ptr == '#')
		el->sharp = 1;
	else if (*ptr == ' ')
		el->space = 1;
	else
		el->zero = 1;
	(*s) = ++ptr;
}

void		set_ltype(char **s, t_param *el)
{
	char	*ptr;

	ptr = (*s);
	while (*ptr == 'l' || *ptr == 'h')
		++ptr;
	if (ptr != (*s))
	{
		if (*(ptr - 1) == 'h')
			el->numeric.length = (*(ptr - 2) == 'h') ? 2 : 1;
		else
			el->numeric.length = (*(ptr - 2) == 'l') ? 4 : 3;
	}
	el->type = *ptr++;
	(*s) = ptr;
}
