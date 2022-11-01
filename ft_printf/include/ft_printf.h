/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaduan-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:15:40 by aaduan-b          #+#    #+#             */
/*   Updated: 2022/06/21 14:16:27 by aaduan-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printper(void);
int		ft_hexlen(unsigned int num);
void	ft_puthex(unsigned int num, const char format);
int		ft_printhex(unsigned int num, const char format);
int		ft_ptrlen(long long unsigned int *num);
int		ft_printptr(unsigned long int n, const char *ptr);
int		ft_numlen(unsigned int num);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_printunsigned(unsigned int n);
int		ft_printchar(char c);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *str, ...);

#endif
