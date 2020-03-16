/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:29:44 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 17:54:05 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void    flags(t_spec *spec)
{
    first_flag(spec);
    second_flag(spec);
    third_flag(spec);
    fourth_flag(spec);
/* 
	printf("\n---------------\n");
	printf("plus  %d\n", spec->flag->plus);
	printf("minus %d\n", spec->flag->minus);
	printf("hash  %d\n", spec->flag->hash);
	printf("space %d\n", spec->flag->space);
	printf("zero  %d", spec->flag->zero);
	printf("\n---------------\n");
	printf("width %d", spec->flag->width);
	printf("\n---------------\n");
	printf("precision %d", spec->flag->precision);
	printf("\n---------------\n");
	printf("h  %d\n", spec->flag->h);
	printf("hh %d\n", spec->flag->hh);
	printf("l  %d\n", spec->flag->l);
	printf("ll %d\n", spec->flag->ll);
	printf("L  %d\n", spec->flag->L); */
	print_spec(spec); 
    free(spec->flag);
}

int		parse(t_spec *spec)
{
    int len;

    len = (int)ft_strlen(spec->format);
    spec->i = 0;
    spec->bytes = 0;
    while (spec->format[spec->i] != '\0' && spec->i < len)
    {
        while (spec->format[spec->i] != '%' && spec->i < len)
        {
            ft_putchar(spec->format[spec->i++]);
            spec->bytes++;
        } 
        if (spec->format[spec->i++] == '%')
            flags(spec);
    }
    return (spec->bytes);
}

int		ft_printf(const char *format, ...)
{
	t_spec		spec;
	va_list		ap;

	va_start(ap, format);
	spec.format = ft_strdup(format);
    spec.ap = &ap;
	if (!parse(&(spec)))
		return (-1);
	va_end(ap);
	free(spec.format);
	return (spec.bytes);
}



/*
	записываем в spec.format format
	начинаем парсить строку
	выбрать: записываем всё в буфер и потом выводить или выводить сразу
	идем по строке
	если встретили символ, выводим
	если втретили \ обрабатываем
	если встретили % начинаем парсить флаг, длину, точность, размер типа и сам спецификатор типа
		параллельно записываем в структуру все эти данные
	после парсинга % есть структура заполненная 
	отправляем её в функцию вывода
*/