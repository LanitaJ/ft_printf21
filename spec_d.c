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

static int make_4flag(t_spec *spec, t_flag *flag)
{
	long long int num;

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
	
	
}

static int	ft_len_number(unsigned long num)
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

int			print_d(t_spec *spec, t_flag *flag)
{
	int len;

	make_flag4(spec, flag);
	if (flag->minus)
		flag->zero = 0;
	len = ft_len_number(flag->num);

	if ((flag->precision > flag->width && flag->width > len) || (flag->precision > len))
	{

	}
	return (0);
}