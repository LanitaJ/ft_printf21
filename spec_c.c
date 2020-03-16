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

static int flags_c(t_spec *spec, char *c)
{
	if (spec->flag->minus)
	{
		if (*c)
		{
			write(1, c, 1);
			spec->bytes++;
		}
		spec->bytes += spec->flag->width - 1;
		while (--spec->flag->width)
			write(1, " ", 1);
	}
	else
	{
		spec->bytes += spec->flag->width - 1;
		while (--spec->flag->width)
			write(1, " ", 1);
		if (*c)
		{
			write(1, c, 1);
			spec->bytes++;
		}	
	}
	
	return (0);
}

/* static int		print_lc(t_spec *spec)
{
	
	return (1);
} */

int		print_c(t_spec *spec)
{
	char	c;

	/* if (spec->flag->l && !spec->flag->h)
		print_lc(spec);
	else
	{ */
		c = va_arg(*(spec->ap), int);
		if (spec->flag->width)
			flags_c(spec, &c);
		else
		{
			if (c)
			{
				write(1, &c, 1);
				spec->bytes++;
			}	
		}
	//}
	return (0);
}