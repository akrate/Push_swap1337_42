/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:34:09 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/08 11:50:23 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_error(t_list **lst,char **split,char *str)
{
    t_list *current = *lst;  
    t_list *next_node;
    int i = 0;
        while (current != NULL)
        {
            next_node = current->next;
            free(current);
            current = next_node; 
        }
        while (split[i])
        {
            free(split[i]);
            i++;
        }
        free(split);
        free(str);
        write(2, "Error\n", 6);
        exit (1);   
}

void	ft_lstadd_back(t_list **lst, int data)
{
    t_list *new;

     new = ft_lstnew(data);
    if (*lst == NULL)
        *lst = new;
    else
    {
        t_list *current = *lst;
        while (current->next != NULL)
        {
            // if(data == current->content)
            //     free_error(lst ,split, str);
            current = current->next; 
        }
        // if(data == current->content)
        //     free_error(lst ,split ,str);
        current->next = new;
    }
}
