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

void    flags(t_spec *spec, t_flag *flag)
{
    first_flag(spec, flag);
    second_flag(spec, flag);
    third_flag(spec, flag);
    fourth_flag(spec, flag);
	print_spec(spec, flag);
}

int		parse(t_spec *spec, t_flag *flag)
{
    spec->i = 0;
    spec->bytes = 0;
    while (spec->format[spec->i] != '\0')
    {
		if (spec->format[spec->i] == '%')
		{
			spec->i++;
			flags(spec, flag);
		}
		else if (spec->format[spec->i] == '{' && spec->format[spec->i + 1] == 'f' &&\
				spec->format[spec->i + 2] == 'd' && spec->format[spec->i + 3] == '}')
        {
			spec->fd = (unsigned int)va_arg(spec->ap, unsigned int);
			spec->i += 4;
		}
		else
        {
            ft_putchar_bytes(spec->format[spec->i], spec);
			spec->i++;
        }
    }
    return (spec->bytes);
}

int		ft_printf(const char *format, ...)
{
	t_spec		spec;
	t_flag		flag;

	va_start(spec.ap, format);
	spec.format = ft_strdup(format);
	spec.fd = 1;
	parse(&spec, &flag);
	va_end(spec.ap);
	free(spec.format);
	//printf("\nbytes: %d", spec.bytes);
	return (spec.bytes);
}



/*
	записываем в spec.format format

	шаг 1:выводить сразу обычный текст 
	если встретили % начинаем парсить флаг, длину, точность, размер типа и сам спецификатор типа
		параллельно записываем в структуру все эти данные
	после парсинга % есть структура заполненная 
	отправляем её в функцию вывода
	выводим спецификатор
	возврат к шагу 1
	

	ТУДУ:
	расписать для каждого типа флаги
	рассмотреть совместимости флагов
	узнать про цвета
	
	запись в файл
	

	Пояснения.
	spec -	хранит:
			поданую строку
			аргументы для va_arg,
			количество байтов на выход(то что возвращает принтф)
			индекс текущего символа в поданой строке
	flag - хранит:
			все флаги

	bonus:
	добавить флаг q - смайлики :), :(, xD, Dx, 
	морзе
	вывод двоичных чисел
	fd
	*
*/