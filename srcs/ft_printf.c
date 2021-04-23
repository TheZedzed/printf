/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:49:07 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/24 07:43:47 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	t_param	*param;
	va_list	list;
	char	*buf;
	int		size;
	int		wlen;

	param = NULL;
	va_start(list, str);
	if ((size = parse(&buf, (char *)str, &param, list)) < 0)
		return (-1);
	va_end(list);
	format(&buf, (char *)str, param);
	wlen = write(1, buf, size);
	final_free(buf, param);
	return (wlen);
}
