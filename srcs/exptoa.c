/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exptoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:30:06 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 16:18:52 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*sub_exptoa(double nb, int plen, t_param *el)
{
	char	*tmp;
	char	*enb;
	int		len;
	int		exp;

	exp = 0;
	nb = remake(&nb, el, &exp);
	tmp = sub_ftoa(nb, plen, el);
	enb = ft_strjoin(tmp, "e+00");
	len = (int)ft_strlen(enb);
	if (exp)
	{
		if (exp < 0)
			enb[len - 3] = '-';
		enb[len - 2] = (exp > 0 ? exp / 10 : -exp / 10) + '0';
		enb[len - 1] = (exp > 0 ? exp % 10 : -exp % 10) + '0';
	}
	if (enb[2] == '0')
		enb = new_exptoa(enb, exp + 1, len);
	free(tmp);
	return (enb);
}

char		*new_exptoa(char *str, int exp, int len)
{
	char	*new;

	if (!(new = ft_calloc(len, sizeof(char))))
		return (NULL);
	new[0] = str[0];
	new[1] = '1';
	ft_memcpy(new + 2, str + 3, len - 3);
	new[len - 4] = exp < 0 ? '-' : '+';
	new[len - 3] = (exp > 0 ? exp / 10 : -exp / 10) + '0';
	new[len - 2] = (exp > 0 ? exp % 10 : -exp % 10) + '0';
	free(str);
	return (new);
}

double		remake(double *nb, t_param *el, int *exp)
{
	double	nb2;

	nb2 = (*nb);
	if (ft_abs(nb2) >= 10.0)
	{
		while (1)
		{
			if (ft_abs(nb2) >= 10.0)
				nb2 /= 10.0;
			else
				break ;
			++(*exp);
		}
	}
	else
	{
		if (nb2)
		{
			while (!(size_t)nb2)
			{
				--(*exp);
				nb2 *= 10.0;
			}
		}
	}
	if (el->type == 'g' && el->precision.value == 1)
		make_right(nb, el->precision.value + ft_abs(*exp));
	if (ft_abs((long)*nb) == 10)
		(*exp) += (*exp) < 0 ? -1 : 1;
	return (nb2);
}

void		exp_trunc(char **str, int nlen)
{
	char	*ptr;
	int		len;
	int		i;

	ptr = (*str);
	len = (int)ft_strlen(ptr) - 4;
	i = len;
	if (i > nlen)
	{
		while (--i)
		{
			if (ptr[i] == '0')
				ptr[i] = '\0';
			else if (ptr[i] == '.')
			{
				ptr[i] = '\0';
				break ;
			}
			else
				break ;
		}
	}
	(*str) = new_exp(ptr, len + 4);
	free(ptr);
}

char		*new_exp(char *str, int len)
{
	char	*new;
	int		size1;
	int		size2;
	int		i;
	int		diff;

	i = -1;
	size1 = 0;
	size2 = 0;
	while (++i < len && str[i])
		++size1;
	while (i < len && !str[i])
		++i;
	diff = i;
	while (str[i] && ++i)
		++size2;
	if (!(new = ft_calloc(size1 + size2 + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(new, str, size1);
	if (size2)
		ft_memcpy(new + size1, str + diff, size2);
	return (new);
}
