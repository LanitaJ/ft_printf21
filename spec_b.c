/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 17:42:29 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void bmake_4thflag(t_spec *spec, t_flag *flag)
{
	long long int num;

	num = 0;
	if (flag->hh)
		num = (unsigned char)va_arg(spec->ap, unsigned int);
	else if (flag->h)
		num = (unsigned short)va_arg(spec->ap, unsigned int);
	else if (flag->l)
		num = (unsigned long)va_arg(spec->ap, unsigned long int);
	else if (flag->ll)
		num = (unsigned long long)va_arg(spec->ap, unsigned long long int);
	else
		num = (unsigned int)va_arg(spec->ap, unsigned int);
	if (num < 0 && ++flag->sign)
		flag->num = (unsigned long)num * -1;
	else
		flag->num = (unsigned long)num;
	flag->len = ft_len_number(flag->num, 2);
    if (flag->hash && flag->precision < 1)
        flag->width--;
	if (flag->num == 0 && flag->dot)
	{
		flag->precision++;
		flag->width++;
	}
}

int bpd(t_spec *spec, t_flag *flag)//done
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
		p -= l;
		while (p--)
			ft_putchar_bytes('0', spec);
        if (flag->hash && flag->precision < 1)
            ft_putchar_bytes('0', spec);
        if (flag->num ||  !flag->precision)
    		ft_print_num(spec, flag->num, 2, 97);
		return (1);
	}
	return (0);
}


int bwpd_and_pdw(t_spec *spec, t_flag *flag)//done
{

	if (flag->width > flag->precision && flag->precision > flag->len) 
	{
		flag->width -= flag->precision;
		flag->precision -= flag->len;
		if (!flag->minus)
			print_width(spec, flag);
		while (flag->precision--)
			ft_putchar_bytes('0', spec);
        if (flag->hash && flag->precision < 1)
            ft_putchar_bytes('0', spec);
		if (flag->num ||  !flag->precision)
			ft_print_num(spec, flag->num, 2, 97);
		if (flag->minus)
			print_width(spec, flag);
		return (1);
	}
	return (0);
}
 

int bwd_and_dw(t_spec *spec, t_flag *flag)//done
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	
	if (((w > l && l > p) || (w > p && p == l)))
	{
		flag->width -= l;
		if (!flag->minus)//wd
			print_width(spec, flag);
        if (flag->hash)
            ft_putchar_bytes('0', spec);
		if (flag->num ||  !flag->precision)
			ft_print_num(spec, flag->num, 2, 97);
		if (flag->minus)//dw
			print_width(spec, flag);
		return (1);
	}
	return (0);
}

int bd(t_spec *spec, t_flag *flag)//done
{
	int p;
	int w;
	int l;

	l = flag->len;
	p = flag->precision;
	w = flag->width;
	
	if ((l > w && w > p) || (l > p && p > w) || (w == l && l > p) || \
		(w == l && l == p) || (p == l && l > w) || (l > w && w == p))
	{
        if (flag->hash)
            ft_putchar_bytes('0', spec);
		if (flag->num ||  !flag->precision)
			ft_print_num(spec, flag->num, 2, 97);
		return (1);
	}
	return (0);
}


int			print_b(t_spec *spec, t_flag *flag)
{
	bmake_4thflag(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	if (flag->precision > 0)
		flag->zero = 0;
    if (flag->num == 0 && !flag->dot)
        flag->hash = 0;
	if (bpd(spec, flag))
		return (1);
	else if (bd(spec, flag))
		return (1);
	else if (bwd_and_dw(spec, flag))
		return (1);
	else if (bwpd_and_pdw(spec, flag))
		return (1);
	return (0);
}