/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:17:43 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/29 00:17:49 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_print_nbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}
