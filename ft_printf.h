/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamtaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:56:10 by rlamtaou          #+#    #+#             */
/*   Updated: 2023/11/28 20:19:34 by rlamtaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_len(char c, int *sum);
void	ft_putstr_len(char *s, int *sum);
void	ft_putnbr_len(int n, int *sum);
void	ft_print_hex(size_t hex_v, char c, int *sum);
void	ft_putnbr_uns(unsigned int n, int *sum);
void	ft_print_address( void *addr, int *sum);
void	ft_printf_data(char c, va_list argv, int *sum);
#endif
