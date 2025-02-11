/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:49:54 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/09 10:21:27 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printflst(t_list *lst)
{
    while (lst)
    {
        printf("%d ", lst->content);
        lst = lst->next;
    }
    printf("\n");
}
