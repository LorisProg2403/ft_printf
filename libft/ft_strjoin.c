/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:18 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/11 11:07:26 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		*dst = s1[i];
		i++;
		dst++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		*dst = s2[i];
		i++;
		dst++;
	}
	*dst = '\0';
	return (dst -= len);
}
