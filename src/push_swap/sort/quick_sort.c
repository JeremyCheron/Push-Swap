/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:23:18 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:36:30 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_pivot(t_dlist *stack, int size)
{
	int		values[size];
	t_dlist	*current;
	int		i;
	int		j;
	int		temp;

	i = 0;
	current = stack;
	while (current && i < size)
	{
		values[i++] = (int)(size_t)current->content;
		current = current->next;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
                values[i] = values[j];
                values[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (values[size / 2]);
}

void	quick_sort_b(t_ps *ps, int size)
{
	int	pivot;
	int	i;
	int	pushed_to_a;

	i = 0;
	pushed_to_a = 0;
	pivot = choose_pivot(ps->b, size);
	while (i < size)
	{
		if ((int)(size_t)ps->b->content > pivot)
		{
			ps_push_a(ps);
			pushed_to_a++;
		}
		else
			ps_rot_b(ps);
		i++;
	}
	quick_sort(ps, pushed_to_a);
	quick_sort_b(ps, size - pushed_to_a);
}

void	quick_sort(t_ps *ps, int size)
{
	int	pivot;
	int	i;
	int	pushed_to_b;

	ft_putstr_fd("Starting quick_sort with size: ", 1);
	ft_putnbr_fd(size, 1);
	ft_putstr_fd("\n", 1);

	i = 0;
	pushed_to_b = 0;

	if (size <= 5)
	{
		sort_small_stack(ps, size);
		return ;
	}
	pivot = choose_pivot(ps->a, size);
	ft_putstr_fd("Pivot: ", 1);
	ft_putnbr_fd(pivot, 1);
	ft_putstr_fd("\n", 1);
	while (i < size)
	{
		if (*(int *)ps->a->content < pivot)
		{
			ps_push_b(ps);
			pushed_to_b++;
		}
		else
			ps_rot_a(ps);
		i++;
	}
	ft_putstr_fd("Count: ", 1);
	ft_putnbr_fd(pushed_to_b, 1);
	ft_putstr_fd("\n", 1);
	quick_sort(ps, size - pushed_to_b);
	quick_sort_b(ps, pushed_to_b);
	while (pushed_to_b--)
		ps_push_a(ps);
}
