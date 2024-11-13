/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:48:46 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:54:33 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;
	int		size;

	ps = ps_init(argc, argv);
	size = get_stack_size(ps->a);
	print_stack(ps->a);
	quick_sort(ps, size);
	print_stack(ps->a);
	free_ps(ps);

	return (0);
}
