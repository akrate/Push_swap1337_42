/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:34:09 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/07 20:33:14 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static t_list	*ft_lstlast(t_list *lst)
// {
//     if (lst == NULL)
//         return (NULL);
//     while (lst->next != NULL)
//     {
//         lst = lst->next;
//     }
//     return (lst);
// }
// void	ft_lstadd_back(t_list **lst, int data)
// {
//     // if (lst == NULL || new == NULL)
//     //     return ;
//     t_list *new;

//     new = ft_lstnew(data);
//     if(*lst == NULL)
//         *lst = new;
//     else{
//     //    ft_lstlast(*lst)->next = new;
//     while(lst)
//     {
        
//     }
//     }
// }

int	ft_lstadd_back(t_list **lst, int data)
{
    t_list *new;

     new = ft_lstnew(data);
    if (*lst == NULL || lst == NULL)
        *lst = new;
    else
    {
        t_list *current = *lst;
        while (current->next != NULL)
        {
            if(data == current->content)
            {
                write(2, "Error\n", 6);
                return (1);
            }
            current = current->next; 
        }
        if(data == current->content)
            {
                write(2, "Error\n", 6);
                return (1);
            }
        current->next = new;
    }
    return (0);
}
