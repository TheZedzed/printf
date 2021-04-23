/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:30:32 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 15:12:08 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*sub_gtoa(double n, int plen, int exp, t_param *el)
{
	char	*new;
	int		len;

	len = nbrlen(10, ft_abs((long)n));
	if (!(exp < -4 || exp >= plen))
	{
		if (plen == len)
			new = sub_ftoa(n, 0, el);
		else
			new = sub_ftoa(n, plen - len, el);
		if (!el->sharp)
			flt_trunc(&new, len + 1);
	}
	else
	{
		if (plen == 1)
			new = sub_exptoa(n, 0, el);
		else if (plen == len - 1)
			new = sub_exptoa(n, len - plen, el);
		else
			new = sub_exptoa(n, plen - 1, el);
		exp_trunc(&new, len + 1);
	}
	return (new);
}

char		*sub_ftoa(double nb, int plen, t_param *el)
{
	char	*left;
	char	*right;
	long	tmp;
	char	*res;
	int		i;

	i = plen;
	tmp = (long)make_right(&nb, plen);
	left = make_left(nb, plen, el);
	if (plen)
	{
		if (!(right = ft_calloc(plen + 1, sizeof(char))))
			return (NULL);
		while (--i >= 0)
		{
			right[i] = tmp % 10 + '0';
			tmp /= 10;
		}
		res = ft_strjoin(left, right);
		free(left);
		free(right);
	}
	else
		res = left;
	return (res);
}

void		flt_trunc(char **str, int nlen)
{
	char	*ptr;
	int		len;
	int		i;

	ptr = (*str);
	len = (int)ft_strlen(ptr);
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
}
