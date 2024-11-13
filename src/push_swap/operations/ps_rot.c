/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:31:33 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:25:11 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rot(t_dlist **stack)
{
	t_dlist	*top;

	if (*stack == NULL)
		return ;
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	ps_lstadd_back(stack, top);
}

void		ps_rot_a(t_ps *ps)
{
	_rot(&ps->a);
}

void		ps_rot_b(t_ps *ps)
{
	_rot(&ps->b);
}

void		ps_rot_r(t_ps *ps)
{
	_rot(&ps->a);
	_rot(&ps->b);
}
