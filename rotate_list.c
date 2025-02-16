/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:56:27 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/15 20:58:08 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **stack,char *str)
{
    t_list *tmp;

    if (!*stack || !(*stack)->next)
        return;
    tmp = (*stack);
    *stack = (*stack)->next;
    tmp->next = NULL;
    ft_lstadd_back(stack,tmp);
    put_str(str);
}

void rotate_rr(t_list **stack_a,t_list **stack_b)
{
    rotate(stack_a,"r");
    rotate(stack_b,"r\n");
}

void reverse_rotate(t_list **stack,char *str)
{
    t_list *tmp;
    t_list *last;
    
    if (!*stack || !(*stack)->next)
        return;
    tmp = ft_lstlast(*stack);
     last = *stack;
    while (last->next->next)
        last = last->next;
    last->next = NULL;
    ft_lstadd_front(stack,tmp);
    put_str(str);
}
void reverse_rotate_b_a(t_list **stack_a,t_list **stack_b)
{
    reverse_rotate(stack_b,"rr");
    reverse_rotate(stack_a,"r\n");
}
