/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_service.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:09:32 by ljerk             #+#    #+#             */
/*   Updated: 2020/03/06 17:50:57 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_putchar_bytes(int c, t_spec *spec)
{
	write(spec->fd, &c, 1);
	spec->bytes++;
	return (0);
}

void		ft_putstr_bytes(char const *s, t_spec *spec)
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

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (len + 1 < len)
		return (0);
	return (len);
}

int			ft_len_number(unsigned long num, unsigned rang)
{
	int	res;

	res = 1;
	while (num >= rang)
	{
		num /= rang;
		res++;
	}
	return (res);
}

char		*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
