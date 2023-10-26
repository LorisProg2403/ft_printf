/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:07:11 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/26 20:07:12 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_search(va_list args, const char c)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (c == 's')
		print_len += ft_printstr(va_arg(args, char *));
	/*else if (c == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_len += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), c);*/
	else if (c == '%')
		print_len += ft_printchar('%');
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_search(args, str[i + 1]);
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
