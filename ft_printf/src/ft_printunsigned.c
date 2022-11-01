/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:23:08 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/21 14:23:47 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_numlen(unsigned int num)
{
	int		len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_printunsigned(unsigned int n)
{
	int		plen;
	char	*num;

	plen = 0;
	if (n == 0)
		plen = write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(n);
		plen = ft_printstr(num);
		free(num);
	}
	return (plen);
}
