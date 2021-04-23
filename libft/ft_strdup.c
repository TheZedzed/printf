/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:18:51 by azeraoul          #+#    #+#             */
/*   Updated: 2021/01/18 17:04:34 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	size;

	size = ft_strlen(s);
	if (!(new_s = (char *)malloc(size + 1)))
		return (NULL);
	new_s[size] = '\0';
	ft_memcpy(new_s, s, size);
	return (new_s);
}
