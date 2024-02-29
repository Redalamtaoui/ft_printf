/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:50:22 by rlamtaou          #+#    #+#             */
/*   Updated: 2023/11/24 04:01:51 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int *sum)
{
	write(1, &c, 1);
	*sum = *sum + 1;
}

void	ft_printf_data(char c, va_list argv, int *sum)
{
	if (c == 'c')
		ft_putchar_len(va_arg(argv, int), sum);
	else if (c == 's')
		ft_putstr_len(va_arg(argv, char *), sum);
	else if (c == 'd' || c == 'i')
		ft_putnbr_len(va_arg(argv, int), sum);
	else if (c == 'x' || c == 'X')
		ft_print_hex(va_arg(argv, unsigned int), c, sum);
	else if (c == 'u')
		ft_putnbr_uns(va_arg(argv, unsigned int), sum);
	else if (c == '%')
		ft_putchar_len('%', sum);
	else if (c == 'p')
		ft_print_address(va_arg(argv, void *), sum);
	else
	{
		ft_putchar_len('%', sum);
		ft_putchar_len(c, sum);
	}
}

int	ft_printf(const char *format, ...)
{
	int		sum;
	va_list	argv;

	sum = 0;
	if (format == NULL)
		return (-1);
	va_start(argv, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0' )
		{
			format++;
			ft_printf_data(*format, argv, &sum);
		}
		else if (*format == '%' && *(format + 1) == '\0')
			sum = -1;
		else
			ft_putchar_len(*format, &sum);
		format++;
	}
	va_end(argv);
	return (sum);
}
