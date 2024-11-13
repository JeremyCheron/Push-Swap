/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:28:14 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:51:41 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ps_sort_three(t_ps *stacks)
{
	int	first, last, mid;
	first = stacks->a->content;
	mid = stacks->a->next->content;
	last = stacks->a->next->next->content;
	// while (!is_sorted(stacks))
	// {
		if (first < last && last < mid)
		{
			ps_rrot_a(stacks);
			ps_swap_a(stacks);
		}
		else if (mid < first && first < last)
			ps_swap_a(stacks);
		else if (mid < last && last < first)
			ps_rot_a(stacks);
		else if (last < first && first < mid)
			ps_rrot_a(stacks);
		else if (last < mid && mid < first)
		{
			ps_swap_a(stacks);
			ps_rrot_a(stacks);
		}
	// }
	return (stacks);
}






t_ps	*ps_sort_four(t_ps *stacks)
{
}

t_ps	*ps_sort_five(t_ps *stacks)
{
}

t_ps	*sort_small_stack(t_ps *stacks, int size)
{
	if (size == 2)
	{
		if ((int)(size_t)stacks->a->content > (int)(size_t)stacks->a->next->content)
			ps_swap_a(stacks);
	}
	else if (size == 3)
		ps_sort_three(stacks);
	else if (size == 4)
		ps_sort_four(stacks);
	else if (size == 5)
		ps_sort_five(stacks);
	return (stacks);
}
