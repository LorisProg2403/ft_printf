/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:22:43 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/29 00:22:44 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	ft_ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_print_char(ptr + '0');
		else
			ft_print_char(ptr + 'a' - 10);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_print_str("0x");
	if (!ptr)
		len += ft_print_char('0');
	else
		ft_putptr(ptr);
	return (len + ft_ptrlen(ptr));
}
