/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:36:33 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:24:16 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	_rrot(t_list **stack)
// {
// 	t_list **itr;

// 	if (*stack == NULL);
// 		return ;
// 	itr = stack;
// 	while ((*itr)->next)
// 		itr = &(*itr)->next;
// 	(*itr)->next = *stack;
// 	*stack = (*itr);
// 	*itr = NULL;
// }

static void _rrot(t_dlist **stack)
{
	t_dlist *itr;
	t_dlist *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	itr = *stack;
	while (itr->next)
		itr = itr->next;
	last = itr;
	itr->next = *stack;
	*stack = last;
}

void		ps_rrot_a(t_ps *ps)
{
	_rrot(&ps->a);
}

void		ps_rrot_b(t_ps *ps)
{
	_rrot(&ps->b);
}

void		ps_rrot_r(t_ps *ps)
{
	_rrot(&ps->a);
	_rrot(&ps->b);
}
