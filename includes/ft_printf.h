/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeraoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:14:31 by azeraoul          #+#    #+#             */
/*   Updated: 2021/04/24 00:21:30 by azeraoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "struct.h"
# include "../libft/libft.h"

/*
** llist
*/
t_param	*last_param(t_param *el);
t_param	*curr_elem(t_param **head);
void	push_back(t_param **head, t_param *el);
void	final_free(char *buffer, t_param *el);

/*
** set_params
*/
void	set_length(char **buffer, int flag, t_param *el, va_list list);
void	set_fieldlen(char **buffer, t_param *el, va_list list);
void	set_precision(char **buffer, t_param *el, va_list list);
void	set_flags(char **buffer, t_param *el);
int		set_arg(t_param *el, int len, va_list list);
void	set_pflag(t_param *el);
void	set_ptype(t_param *el);
void	set_ppfix(t_param *el);
void	set_ltype(char **str, t_param *el);

/*
** set_convsize
*/
void	set_convsize(t_param *el);
void	numsize(t_param *el, int plen, int flen, int prefix);
void	strsize(t_param *el, int plen, int flen);
void	charsize(t_param *el, int flen);
void	doublesize(t_param *el, int flen);

/*
** utils
*/
char	*ft_uintoa(size_t nb, t_param *el);
char	*ft_intoa(ssize_t nb, t_param *el);
char	*sub_uintoa(size_t nb, int flag, char *base);
char	*sub_intoa(ssize_t nb, t_param *el);
char	*ft_dbltoa(double nb, int sign, int plen, t_param *el);
char	*sub_ftoa(double nb, int plen, t_param *el);
int		nbrlen(int base, size_t nb);
void	print_list(t_param *el);
double	ft_pow(double nb, int pow);
char	*check_limits(double nb, t_param *el);
char	*make_left(double n, int plen, t_param *el);
/*
** parse_param
*/
int		parse(char **buffer, char *str, t_param **head, va_list list);
int		init_param(char **buffer, int len, t_param *el, va_list list);
void	format(char **buffer, char *str, t_param *el);

/*
** format_param
*/
void	write_num(char **buffer, int len, t_param *el);
void	write_str(char **buffer, char *val, int len, t_param *el);
void	write_char(char **buffer, char *val, t_param *el);
void	write_adjusted(char **buffer, int pad, int prefix, t_param *el);
void	simple_write(char **buffer, int pad, int prefix, t_param *el);
void	write_double(char **buffer, char *val, int len, t_param *el);

/*
** extract_param
*/
int		extract_int(t_param *el, va_list list);
int		extract_uint(t_param *el, va_list list);
int		extract_addr(t_param *el, va_list list);
int		extract_str(t_param *el, va_list list);
int		extract_char(t_param *el, va_list list);
int		extract_len(t_param *el, int len, va_list list);
int		extract_double(t_param *el, va_list list);
t_ul	make_right(double *nb, int plen);
char	*sub_exptoa(double nb, int plen, t_param *el);
char	*sub_gtoa(double nb, int plen, int exp, t_param *el);
double	remake(double *nb, t_param *el, int *exp);
void	set_fplen(t_param *el);
int		lil_nblen(double n);
void	flt_trunc(char **str, int nlen);
void	exp_trunc(char **str, int nlen);
char	*new_exp(char *str, int len);
double	ft_abs(double nb);
void	set_buffer(char *buff, t_param *el);
char	*new_exptoa(char *str, int exp, int len);

int		ft_printf(const char *str, ...);

#endif
