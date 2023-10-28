/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:42:22 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/28 20:42:25 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_putstr(char *str);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_ptr(unsigned long long ptr);
#endif
