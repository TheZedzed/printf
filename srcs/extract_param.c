/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:57:49 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/20 15:20:29 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			extract_int(t_param *el, va_list arg)
{
	ssize_t	val;
	int		len;

	len = el->numeric.length;
	if (len == 1 || len == 2)
		val = (len == 1) ? (short)va_arg(arg, int) : (char)va_arg(arg, int);
	else if (len == 3 || len == 4)
		val = (len == 3) ? va_arg(arg, long) : va_arg(arg, long long);
	else
		val = va_arg(arg, int);
	el->value = ft_intoa(val, el);
	return (el->value ? 0 : -1);
}

int			extract_uint(t_param *el, va_list arg)
{
	size_t	val;
	int		len;

	len = el->numeric.length;
	if (el->type != 'p')
	{
		if (len == 1 || len == 2)
			val = (len == 1) ? (t_us)va_arg(arg, int) : (t_uc)va_arg(arg, int);
		else if (len == 3 || len == 4)
			val = (len == 3) ? va_arg(arg, t_ul) : va_arg(arg, t_ull);
		else
			val = va_arg(arg, unsigned int);
	}
	else
		val = va_arg(arg, size_t);
	el->value = ft_uintoa(val, el);
	return (el->value ? 0 : -1);
}

int			extract_len(t_param *el, int len, va_list arg)
{
	int		length;

	length = el->numeric.length;
	if (length == 1 || length == 2)
	{
		if (length == 1)
			*(short *)va_arg(arg, int *) = len;
		else
			*(signed char *)va_arg(arg, int *) = len;
	}
	else if (length == 3 || length == 4)
	{
		if (length == 2)
			*va_arg(arg, long *) = len;
		else
			*va_arg(arg, long long *) = len;
	}
	else
		*va_arg(arg, int *) = len;
	el->value = ft_strdup("");
	return (el->value ? 0 : -1);
}

int			extract_str(t_param *el, va_list arg)
{
	char	*val;

	val = va_arg(arg, char *);
	if (!el->field_len && el->precision.write && !el->precision.value)
		el->value = ft_strdup("");
	else if (!val)
		el->value = ft_strdup("(null)");
	else
		el->value = ft_strdup(val);
	return (el->value ? 0 : -1);
}

int			extract_char(t_param *el, va_list arg)
{
	char	c;
	char	val;
	char	*res;

	c = el->type;
	val = (c == 'c') ? va_arg(arg, int) : c;
	res = ft_calloc(2, sizeof(char));
	*res = val;
	el->value = res;
	return (el->value ? 0 : -1);
}
