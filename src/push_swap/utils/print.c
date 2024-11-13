/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:20:37 by jcheron           #+#    #+#             */
/*   Updated: 2024/11/13 06:53:42 by jcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void print_stack(t_dlist *head)
{
    t_dlist *current = head;
    while (current != NULL) {
        printf("%d -> ", current->content);  // Affichage de la valeur du noeud
        current = current->next;  // Passage au noeud suivant
    }
    printf("NULL\n");  // Fin de la liste
}



