/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:48:46 by jcheron           #+#    #+#             */
/*   Updated: 2025/01/21 08:29:23 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

void	handle_syntax_error(bool is_split, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			if (is_split)
				free_split(argv);
			ft_printf(ERROR);
			exit (1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	bool			is_split;

	a = NULL;
	b = NULL;
	is_split = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = split(argv[1], ' ');
		is_split = true;
	}
	handle_syntax_error(is_split, argv);
	if (is_split)
		init_split_stack_a(&a, argv + 1);
	else
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
		sort(&a, &b);
	if (is_split)
		free_split(argv);
	free_stack(&a);
	return (0);
}
