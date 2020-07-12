/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/05 19:29:25 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void print_width(t_spec *spec, t_flag *flag)
{
	spec->bytes += flag->width;
	while (flag->width--)
	{
		ft_putchar(' ');
	}
}

static void	print_lc(char c)
{
	c = (wchar_t)c;
	write(1, &c, 1);
}

int		print_c(t_spec *spec, t_flag *flag)
{
	char	c;

	c = (char)va_arg(spec->ap, char*);
	if (flag->width)
		flag->width--;
	if (flag->minus)
	{
		if (flag->l)
			print_lc(c);
		else
			ft_putchar(c);	
	}
	print_width(spec, flag);
	if (!flag->minus)
		ft_putchar(c);
	spec->bytes++;
	return (0);
}