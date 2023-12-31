/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:20:55 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/09 12:20:59 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

/*
 *
 */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
