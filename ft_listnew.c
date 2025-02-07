/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:30:08 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/07 18:09:49 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
    t_list *node;
    
    node = (t_list *) malloc(sizeof(t_list));
    if (node == NULL)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}