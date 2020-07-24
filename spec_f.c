/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:27:56 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 17:42:04 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static double		ft_pow(double n, int pow)
{
	return (pow ? n * ft_pow(n, pow - 1) : 1);
}

void				print_f(t_spec *spec, t_flag *flag)
{
	double long bd;//before dot
	double long ad;//after dot
	if (flag->L)
		bd = (double long)va_arg(spec->ap, double long);
	else
		bd = (double)va_arg(spec->ap, double);
	if (!flag->precision)
		flag->precision = 6;
	if (bd < 0 && ++flag->sign)
		bd *= -1;
	ad = (bd - (long)bd)*(ft_pow(10, flag->precision + 1));

	

	
	return (0);
}