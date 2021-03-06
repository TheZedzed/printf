/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:19:32 by azeraoul          #+#    #+#             */
/*   Updated: 2021/01/31 23:33:28 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char const *src)
{
	int		dest_len;
	int		src_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
	{
		dest[dest_len + src_len] = src[src_len];
		src_len++;
	}
	dest[dest_len + src_len] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (s1 && !s2)
		len = ft_strlen(s1);
	else if (!s1 && s2)
		len = ft_strlen(s2);
	else if (!s1 && !s2)
		len = 0;
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char*)malloc(len + 1)))
		return (NULL);
	ft_memset(res, 0, len + 1);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	return (res);
}
