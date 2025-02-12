/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sawp_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:50:31 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/12 16:33:39 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void swap_stack_a(t_list *stack)
{
    int tmp;
    
    if (stack && stack->next)
    {
        tmp = stack->content;
        stack->content = stack->next->content;
        stack->next->content = tmp;
    }
}
void swap_stack_b(t_list *stack)
{
    int tmp;
    
    if (stack && stack->next)
    {
        tmp = stack->content;
        stack->content = stack->next->content;
        stack->next->content = tmp;
    }
}
void swap_stack_ss(t_list *stack_a,t_list *stack_b)
{
    swap_stack_a(stack_a);
    swap_stack_b(stack_b);
}

// int main()
// {
//     t_list node1 = {1,NULL};
//     t_list node2 = {2,NULL};
    
//     node1.next = &node2;
//     swap_stack(&node1);
//     printf("%d\n",node1.content);
//     printf("%d\n",node2.content);
    
// }
