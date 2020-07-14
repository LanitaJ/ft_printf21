/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 17:41:45 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void make_4thflag(t_spec *spec, t_flag *flag)
{
	long long int num;

	num = 0;
	if (flag->hh)
		num = (signed char)va_arg(spec->ap, int);
	else if (flag->h)
		num = (short)va_arg(spec->ap, int);
	else if (flag->l)
		num = (long)va_arg(spec->ap, long int);
	else if (flag->ll)
		num = (long long)va_arg(spec->ap, long long int);
	else
		num = (int)va_arg(spec->ap, int);
	if (num < 0 && ++flag->sign)
		flag->num = -1 * (unsigned int)num;
	else
		flag->num = (unsigned int)num;
	flag->len = ft_len_number(num);
}

int	ft_len_number(unsigned long num)
{
	int	res;

	res = 1;
	while (num >= 10)
	{
		num /= 10;
		res++;
	}
	return (res);
}

void		ft_figure_put(t_spec *spec, unsigned long n)
{
	if (n >= 10)
		ft_figure_put(spec, n / 10);
	n = n % 10;
	n += n < 10 ? '0' : 97 - 10;
	ft_putchar_bytes((char)n, spec);
}

void				print_sign(t_spec *spec, t_flag *flag)
{
	if (flag->plus && !flag->sign)
		ft_putchar_bytes('+', spec );
	if (flag->sign)
		ft_putchar_bytes('-', spec);
	else if (flag->space && !flag->plus)
		ft_putchar_bytes(' ', spec);
}

int pd(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if ((p > w && w > l) || (p > l && l > w) || (w == p && p > l)\
		|| (p > w && w == l))
	{
		print_sign(spec, flag);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		return (1);
	}
	return (0);
}

int wpd(t_spec *spec, t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if (w > p && p > l && !flag->minus) 
	{
		print_sign(spec, flag);
		while (flag->width--)
			ft_putchar_bytes(' ', spec);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
		return (1);
	}
	return (0);
}
/* 
static int wd(t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if ()
	return (0);
}

static int d(t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if ()
	return (0);
}

static int pdw(t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if ()
	return (0);
}

static int dw(t_flag *flag)
{
	int p;
	int w;
	int l;

	p = flag->precision;
	w = flag->width;
	l = flag->len;
	if ()
	return (0);
} */

int			print_d(t_spec *spec, t_flag *flag)
{
	make_4thflag(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	if (flag->minus || flag->plus || flag->space)
		flag->width--;
	//flag->len = ft_len_number(flag->num);

	if (pd(spec, flag))
		return (1);
	else if (wpd(spec, flag))
		return (1);
	return (0);
}