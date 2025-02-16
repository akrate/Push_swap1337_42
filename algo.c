/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:27:54 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/16 22:24:34 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushb(t_list **stack_a,t_list **stack_b)
{
    int size;
    int i;
    
    size = ft_lstsize(*stack_a);
    i = 0;
    while (size > 3 && i < size / 2)
    {
        if ((*stack_a)->index <= size / 2)
        {
            push_to_b(stack_b,stack_a);
            i++;  
        }else{
            rotate(stack_a,"ra\n");
        }
    }
    while (size - i > 3)
    {
        push_to_b(stack_b, stack_a);
        i++;
    }
}
void target_stack(t_list **stack_a,t_list **stack_b)
{
    while (stack_b)
    {
        if ((*stack_b)->index < (*stack_a)->index)
            (*stack_b)->target = (*stack_a)->index;
        else if ((*stack_b)->index < (*stack_a)->next->index)
            (*stack_b)->target = (*stack_a)->next->index;
        else if ((*stack_b)->index < (*stack_a)->next->next->index)
            (*stack_b)->target = (*stack_a)->next->next->index;
        else if ((*stack_b)->index > (*stack_a)->next->next->index)
            (*stack_b)->target = (*stack_a)->index;
        *stack_b = (*stack_b)->next;
    }
}
