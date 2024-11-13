/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:06:44 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:31:15 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ps_lstlast(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_dlist	*ps_lstfirst(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}
void	ps_lstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
	new->prev = last;
}


t_dlist	*ps_lstnew(int content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ps_lstclear(t_dlist **stack)
{
	t_dlist	*current;
	t_dlist	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

