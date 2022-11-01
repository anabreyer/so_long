/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:44:48 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/20 18:47:26 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int		plen;

	plen = 0;
	if (format == 'c')
		plen += ft_printchar(va_arg(args, int));
	else if (format == 's')
		plen += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		plen += ft_printptr(va_arg(args, unsigned long long),
				"0123456789abcdef");
	else if (format == 'd' || format == 'i')
		plen += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		plen += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		plen += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		plen += ft_printper();
	return (plen);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		plen;

	i = 0;
	plen = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			plen += ft_format(args, str[i + 1]);
			i++;
		}
		else
			plen += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (plen);
}
