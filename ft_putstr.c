/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:52:23 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 18:55:50 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putstr_bytes(char const *s, t_spec *spec)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(spec->fd, s, 1);
		s++;
		spec->bytes++;
	}
}
