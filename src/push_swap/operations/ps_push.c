/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:26:02 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:22:06 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_push(t_dlist **src, t_dlist **dest)
{
	t_dlist	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void		ps_push_a(t_ps *ps)
{
	_push(&ps->a, &ps->b);
}

void		ps_push_b(t_ps *ps)
{
	_push(&ps->b, &ps->a);
}

