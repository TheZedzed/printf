/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:58:15 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/23 15:23:08 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			init_param(char **s, int len, t_param *el, va_list arg)
{
	char	*ptr;

	ptr = (*s);
	while (!el->type)
	{
		if (*ptr == '.')
			set_length(&ptr, 1, el, arg);
		else if (ft_strchr("- 0#+", *ptr))
			set_flags(&ptr, el);
		else if (*ptr == '*' || ft_isdigit(*ptr))
			set_length(&ptr, 0, el, arg);
		else
			set_ltype(&ptr, el);
	}
	set_pflag(el);
	set_ptype(el);
	set_ppfix(el);
	el->format_len = ptr - (*s);
	(*s) = ptr;
	return (set_arg(el, len, arg));
}

int			parse(char **buff, char *str, t_param **param, va_list arg)
{
	t_param	*new;
	int		len;

	len = 0;
	while (*str)
	{
		if (*str != 0x25)
		{
			++len;
			++str;
		}
		else if (*str++ == 0x25)
		{
			if (!(new = curr_elem(param)))
				return (-1);
			if (init_param(&str, len, new, arg) < 0)
				return (-1);
			len += new->conversion_size;
		}
	}
	if (!((*buff) = ft_calloc(len + 1, sizeof(char))))
		return (-1);
	return (len);
}

void		format(char **buff, char *str, t_param *el)
{
	char	*ptr;
	char	*val;
	int		len;

	ptr = (*buff);
	while (*str)
	{
		if (*str != 0x25)
			*ptr++ = *str++;
		else if (*str == 0x25)
		{
			val = el->value;
			len = (int)ft_strlen(val);
			if (el->type == 'd' || el->type == 'i' || el->numeric.no_signed)
				write_num(&ptr, len, el);
			else if (el->type == 'f' || el->type == 'e' || el->type == 'g')
				write_double(&ptr, val, len, el);
			else if (el->type == 's')
				write_str(&ptr, val, len, el);
			else
				write_char(&ptr, val, el);
			str += el->format_len + 1;
			el = el->next;
		}
	}
}
