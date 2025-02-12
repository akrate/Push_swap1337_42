/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:56:27 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/12 16:30:50 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_list **stack)
{
    t_list *tmp;

    if (!*stack || !(*stack)->next)
        return;
    tmp = (*stack);
    *stack = (*stack)->next;
    ft_lstadd_back(stack,tmp);
}
void rotate_b(t_list **stack)
{
    t_list *tmp;

    if (!*stack || !(*stack)->next)
        return;
    tmp = (*stack);
    *stack = (*stack)->next;
    ft_lstadd_back(stack,tmp);
}

void rotate_rr(t_list **stack_a,t_list **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}
void reverse_rotate_a(t_list **stack)
{
    t_list *tmp;
    
    if (!*stack || !(*stack)->next)
        return;
    tmp = ft_lstlast(stack);
    ft_lstadd_front(stack,tmp);
}
void reverse_rotate_b(t_list **stack)
{
    t_list *tmp;
    
    if (!*stack || !(*stack)->next)
        return;
    tmp = ft_lstlast(stack);
    ft_lstadd_front(stack,tmp);
}
void reverse_rotate_b_a(t_list **stack_a,t_list **stack_b)
{
    reverse_rotate_b(stack_b);
    reverse_rotate_a(stack_a);
}