/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:08:28 by ljerk             #+#    #+#             */
/*   Updated: 2020/07/11 17:29:16 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	init_flag(t_flag *flag)
{
    ///spec->flag = malloc(sizeof(t_flag));
    flag->plus = 0;
    flag->minus = 0;
	flag->hash = 0;
    flag->space = 0;
    flag->zero = 0;
    flag->width = 0;
	flag->dot = 0;
    flag->precision = 0;
    flag->l = 0;
    flag->ll = 0;
    flag->h = 0;
    flag->hh = 0;
    flag->L = 0;
    flag->type = 0;
}

void    first_flag(t_spec *spec, t_flag *flag)
{
    init_flag(flag);
    while (spec->format[spec->i] == '+' || spec->format[spec->i] == '-' ||
            spec->format[spec->i] == '#' ||spec->format[spec->i] == '0' ||
            spec->format[spec->i] == ' ')
    {
        if (spec->format[spec->i] == '+')
            flag->plus = 1;
        if (spec->format[spec->i] == '-')
            flag->minus = 1;
        if (spec->format[spec->i] == '#')
            flag->hash = 1;
        if (spec->format[spec->i] == ' ')
            flag->space = 1;
        if (spec->format[spec->i] == '0')
            flag->zero = 1;
        spec->i++;
    }
}

void    second_flag(t_spec *spec, t_flag *flag)
{
    parse_star(spec, flag);
    //parse_number();
    
    /* if (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0')
    {
        spec->flag->width = ft_atoi(&spec->format[spec->i]);
		while (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0' &&
            spec->format[spec->i])
        spec->i++;
	}  */
}
/* 
void    third_flag(t_spec *spec)
{
    if (spec->format[spec->i] == '.')
	{
		spec->flag->dot = 1;
		spec->i++;
	}
    if (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0')
	{
		spec->flag->precision = ft_atoi(&spec->format[spec->i]);
		while (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0' &&
				spec->format[spec->i])
			spec->i++;
	}
}

void	fourth_flag(t_spec *spec)
{
	if (spec->format[spec->i] == 'L')
	{
		spec->flag->L = 1;
		spec->i++;
	}
	else if (spec->format[spec->i] == 'h' && (spec->format[spec->i + 1] == 'h'))
	{
		spec->flag->hh = 1;
		spec->i++;
	}
	else if (spec->format[spec->i] == 'h')
	{
		spec->flag->h = 1;
		spec->i++;
	}
	else if (spec->format[spec->i] == 'l' && (spec->format[spec->i + 1] == 'l'))
	{
		spec->flag->ll = 1;
		spec->i++;
	}
	else if (spec->format[spec->i] == 'l')
	{
		spec->flag->l = 1;
		spec->i++;
	}
} */
