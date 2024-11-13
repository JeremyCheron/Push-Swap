/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:51:25 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:27:40 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dlist	*_new_node(int value)
{
	t_dlist	*node;
	int		content;

	content = value;
	node = ps_lstnew(content);
	if (!node)
	{
		return (NULL);
	}
	return (node);
}

t_ps	*ps_init(int argc, char **argv)
{
	t_ps	*ps;
	int		i;
	t_dlist	*new_elem;
	int		value;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (NULL);
	ps->a = NULL;
	ps->b = NULL;
	ps->count = 0;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new_elem = _new_node(value);
		if (!new_elem)
		{
			free_ps(ps);
			return (NULL);
		}
		ps_lstadd_back(&(ps->a), new_elem);
		i++;
	}
	return (ps);
}

int	get_stack_size(t_dlist *stack)
{
	int		size;
	t_dlist	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
