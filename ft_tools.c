/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 04:02:17 by rlamtaou          #+#    #+#             */
/*   Updated: 2023/11/28 20:17:57 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len(char *s, int *sum)
{
	size_t	x;

	if (s == NULL)
	{
		ft_putstr_len("(null)", sum);
		return ;
	}
	x = 0;
	if (!s)
		return ;
	while (s[x])
	{
		ft_putchar_len(s[x], sum);
		x++;
	}
}

void	ft_putnbr_len(int n, int *sum)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_len('-', sum);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_len((nb / 10), sum);
		ft_putnbr_len((nb % 10), sum);
	}
	else
		ft_putchar_len((nb + 48), sum);
}

void	ft_print_hex(size_t hex_v, char c, int *sum)
{
	char	*hex_type;

	if (c == 'x' || c == 'p')
		hex_type = "0123456789abcdef";
	if (c == 'X')
		hex_type = "0123456789ABCDEF";
	if (hex_v < 16)
		ft_putchar_len(hex_type[hex_v % 16], sum);
	else
	{
		ft_print_hex(hex_v / 16, c, sum);
		ft_putchar_len(hex_type[hex_v % 16], sum);
	}
}

void	ft_putnbr_uns(unsigned int n, int *sum)
{
	unsigned long	nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putnbr_len(nb / 10, sum);
		ft_putnbr_len(nb % 10, sum);
	}
	else
		ft_putchar_len(nb + 48, sum);
}

void	ft_print_address(void *addr, int *sum)
{
	if (addr == NULL)
	{
		ft_putstr_len("(nil)", sum);
		return ;
	}
	ft_putstr_len("0x", sum);
	ft_print_hex((size_t)addr, 'p', sum);
}
