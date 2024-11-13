/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:23:54 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:31:45 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_dlist
{
	long			content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct	s_ps
{
	t_dlist	*a;
	t_dlist	*b;
	int		*values;
	size_t	count;
}				t_ps;

void		ps_clear(t_ps **ps);
void		ps_push_a(t_ps *ps);
void		ps_push_b(t_ps *ps);
void		ps_rot_a(t_ps *ps);
void		ps_rot_b(t_ps *ps);
void		ps_rot_r(t_ps *ps);
void		ps_swap_a(t_ps *ps);
void		ps_swap_b(t_ps *ps);
void		ps_swap_s(t_ps *ps);
void		ps_rrot_a(t_ps *ps);
void		ps_rrot_b(t_ps *ps);
void		ps_rrot_r(t_ps *ps);
t_ps		*sort_small_stack(t_ps *ps, int size);
void		quick_sort(t_ps *ps, int size);
void		free_ps(t_ps *ps);
t_ps		*ps_init(int argc, char **argv);
int			get_stack_size(t_dlist *stack);
void 		print_stack(t_dlist *stack);
int			is_sorted(t_ps *stacks);
t_dlist		*ps_lstlast(t_dlist *lst);
t_dlist		*ps_lstfirst(t_dlist *lst);
void		ps_lstadd_back(t_dlist **lst, t_dlist *new);
t_dlist		*ps_lstnew(int content);
void		ps_lstclear(t_dlist **lst);

#endif
