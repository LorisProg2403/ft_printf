/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:58:23 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/28 22:58:25 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	if (format == 's')
		print_len += ft_print_str(va_arg(args, char *));
	if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(va_arg(args, int));
	if (format == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(args, int), format);
	if (format == '%')
		print_len += ft_print_char('%');
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	va_start(args, format);
	i = 0;
	print_length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_format(args, format[i + 1]);
			if (format[i + 1] != '%')
				va_arg(args, void *);
			i++;
		}
		else
			print_length += ft_print_char(format[i]);
		i++;
	}
	return (print_length);
}
