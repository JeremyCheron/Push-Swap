/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:34:17 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:25:26 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap(t_dlist **stack)
{
	t_dlist	*first;
	t_dlist	*second;
	t_dlist	*rest;

	if (*stack == NULL)
		return ;
	first = *stack;
	second = first->next;
	rest = second->next;
	first->next = rest;
	second->next = first;
	*stack = second;
}

void		ps_swap_a(t_ps *ps)
{
	_swap(&ps->a);
}

void		ps_swap_b(t_ps *ps)
{
	_swap(&ps->b);
}

void		ps_swap_s(t_ps *ps)
{
	_swap(&ps->a);
	_swap(&ps->b);
}
