/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:56:58 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:33:50 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_ps(t_ps *ps)
{
    if (ps)
    {
        ps_lstclear(&ps->a);  // Libérer la pile a
        ps_lstclear(&ps->b);  // Libérer la pile b
        free(ps);             // Libérer la structure
        ps = NULL;            // S'assurer que ps ne pointe plus vers une zone libérée
    }
}

