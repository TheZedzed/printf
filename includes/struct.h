/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:47:02 by azeraoul          #+#    #+#             */
/*   Updated: 2021/02/25 11:50:13 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef unsigned short		t_us;
typedef unsigned char		t_uc;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

typedef struct				s_pfix
{
	int	write;
	int	value;
}							t_pfix;

typedef struct				s_preci
{
	int	write;
	int	value;
}							t_preci;

typedef struct				s_num
{
	int	length;
	int	no_signed;
	int	is_signed;
}							t_num;

typedef struct				s_param
{
	char			*value;
	char			type;
	int				zero;
	int				plus;
	int				space;
	int				sharp;
	int				adjust;
	t_pfix			prefix;
	t_num			numeric;
	t_preci			precision;
	int				field_len;
	int				format_len;
	int				conversion_size;
	struct s_param	*next;
}							t_param;

#endif
