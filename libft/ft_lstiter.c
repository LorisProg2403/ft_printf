/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <lgaume@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:22:26 by lgaume            #+#    #+#             */
/*   Updated: 2023/10/17 14:22:28 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*prev;

	if (lst && f)
	{
		prev = (t_list *)lst;
		while (prev)
		{
			f(prev->content);
			prev = prev->next;
		}
	}
}
