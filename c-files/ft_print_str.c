/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:16:37 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/29 00:16:41 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[len])
		len += ft_print_char(str[len]);
	return (len);
}
