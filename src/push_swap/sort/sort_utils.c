/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:44:28 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:50:40 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_ps *stacks)
{
    t_dlist *current = stacks->a;
    while (current && current->next)
    {
        if (*(int *)current->content > *(int *)current->next->content)
            return 0;  // Pile non triée
        current = current->next;
    }
    return 1;  // Pile triée
}


