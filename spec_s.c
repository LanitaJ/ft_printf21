/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:11 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 20:46:22 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
/* 
static int				print_ls()
{
	
	return (0);
}
static int		print_flag_s(t_spec *spec, char *s, int len)
{
	spec->flag->width -= (spec->flag->precision > len ? len : spec->flag->precision);
	if (spec->flag->minus)
	{
		while (*s && spec->flag->precision--)
		{
			ft_putchar(*s++);
			spec->bytes++;
		}
		while (spec->flag->width--)
		{
			ft_putchar(' ');
			spec->bytes++;
		}
	}
	else
	{
		while (spec->flag->width--)
		{
			ft_putchar(' ');
			spec->bytes++;
		}
		while (*s && spec->flag->precision--)
		{
			ft_putchar(*s++);
			spec->bytes++;
		}
	}
	return (0);
}

int			print_s(t_spec *spec, t_flag *flag)
{
	char	*s;
	size_t	len;
	
	if (spec->flag->l && !spec->flag->h)
		print_ls();
	else
	{
		s = va_arg(*(spec->ap), char *);
		if (s == 0)
			s = "(null)";
		len = ft_strlen(s);
		if (!spec->flag->dot)
			spec->flag->precision = ((size_t)spec->flag->width < len) ? len : spec->flag->width;
		if (spec->flag->width && ((size_t)spec->flag->width > len || spec->flag->width > spec->flag->precision))
			print_flag_s(spec, s, len);
		else
			while (*s && spec->flag->precision--)
			{
				ft_putchar(*s++);
				spec->bytes++;
			}
	}
	return (0);
} */