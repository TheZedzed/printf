/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:44:33 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 11:44:35 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_length(char **s, int flag, t_param *el, va_list arg)
{
	char	*ptr;

	ptr = (*s);
	if (flag)
	{
		++ptr;
		el->precision.write = 1;
		set_precision(&ptr, el, arg);
	}
	else
		set_fieldlen(&ptr, el, arg);
	(*s) = ptr;
}

void		set_fieldlen(char **s, t_param *el, va_list arg)
{
	char	*ptr;
	int		val;

	val = 0;
	ptr = (*s);
	while (*ptr)
	{
		if (*ptr == '*')
		{
			if ((val = va_arg(arg, int)) < 0)
				el->adjust = 1;
			val = (val < 0) ? val * -1 : val;
			++ptr;
		}
		else if (ft_isdigit(*ptr))
		{
			val = ft_atoi(ptr);
			ptr += nbrlen(10, val);
		}
		else
			break ;
	}
	el->field_len = val;
	(*s) = ptr;
}

void		set_precision(char **s, t_param *el, va_list arg)
{
	char	*ptr;
	int		val;

	val = 0;
	ptr = (*s);
	while (*ptr)
	{
		if (*ptr == '*')
		{
			if ((val = va_arg(arg, int)) < 0)
				el->precision.write = 0;
			val = val < 0 ? 0 : val;
			++ptr;
		}
		else if (ft_isdigit(*ptr))
		{
			val = ft_atoi(ptr);
			ptr += nbrlen(10, val);
		}
		else
			break ;
	}
	el->precision.value = val;
	(*s) = ptr;
}
