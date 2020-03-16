/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:08:28 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 21:15:41 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	init_flag(t_spec *spec)
{
    spec->flag = malloc(sizeof(t_flag));
    spec->flag->plus = 0;
    spec->flag->minus = 0;
    spec->flag->hash = 0;
    spec->flag->space = 0;
    spec->flag->zero = 0;
    spec->flag->width = 0;
	spec->flag->dot = 0;
    spec->flag->precision = 0;
    spec->flag->l = 0;
    spec->flag->ll = 0;
    spec->flag->h = 0;
    spec->flag->hh = 0;
    spec->flag->L = 0;
    spec->flag->type = 0;
}

void    first_flag(t_spec *spec)
{
    init_flag(spec);
    while (spec->format[spec->i] == '+' || spec->format[spec->i] == '-' ||
            spec->format[spec->i] == '#' ||spec->format[spec->i] == '0' ||
            spec->format[spec->i] == ' ')
    {
        if (spec->format[spec->i] == '+')
            spec->flag->plus = 1;
        if (spec->format[spec->i] == '-')
            spec->flag->minus = 1;
        if (spec->format[spec->i] == '#')
            spec->flag->hash = 1;
        if (spec->format[spec->i] == ' ')
            spec->flag->space = 1;
        if (spec->format[spec->i] == '0')
            spec->flag->zero = 1;
        spec->i++;
    }
}

void    second_flag(t_spec *spec)
{
    if (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0')
    {
        spec->flag->width = ft_atoi(&spec->format[spec->i]);
		while (spec->format[spec->i] <= '9' && spec->format[spec->i] >= '0' &&
            spec->format[spec->i])
        spec->i++;
	}
}

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
}
