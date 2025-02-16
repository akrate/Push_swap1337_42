/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_back_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:34:09 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/16 17:40:51 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_error(t_list **lst,char **split)
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
        write(2, "Error\n", 6);
        exit (1);   
}
void free_main(t_list **stack_a,t_list **stack_b,char **split)
{
    t_list *current = *stack_a;  
    t_list *next_node;
    int i = 0;
        while (current != NULL)
        {
            next_node = current->next;
            free(current);
            current = next_node; 
        }
         t_list *current2 = *stack_b;  
        t_list *next_node2;
        while (current2 != NULL)
        {
            next_node2 = current2->next;
            free(current2);
            current2 = next_node2; 
        }
        while (split[i])
        {
            free(split[i]);
            i++;
        }
        free(split);
        exit (1);   
}
void	ft_lstadd_back_stack(t_list **lst, int data)
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
            current = current->next; 
        }
        current->next = new;
    }
}
