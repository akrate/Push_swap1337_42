/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:56:27 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/13 20:24:00 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **stack)
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
    rotate(stack_a);
    rotate(stack_b);
}

void reverse_rotate(t_list **stack)
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
}
void reverse_rotate_b_a(t_list **stack_a,t_list **stack_b)
{
    reverse_rotate(stack_b);
    reverse_rotate(stack_a);
}
// // Main function for testing
// int main()
// {
//     // Initialize two stacks
//     t_list *stack_a = NULL;
//     t_list *stack_b = NULL;

//     // Add some elements to stack_a
//     ft_lstadd_back(&stack_a, ft_lstnew(1));
//     ft_lstadd_back(&stack_a, ft_lstnew(2));
//     ft_lstadd_back(&stack_a, ft_lstnew(3));
//     ft_lstadd_back(&stack_a, ft_lstnew(4));

//     // Add some elements to stack_b
//     ft_lstadd_back(&stack_b, ft_lstnew(5));
//     ft_lstadd_back(&stack_b, ft_lstnew(6));
//     ft_lstadd_back(&stack_b, ft_lstnew(7));

//     // Print original stacks
//     printf("Original stack_a: ");
//     printflst(stack_a);
//     printf("Original stack_b: ");
//     printflst(stack_b);

//     // Perform reverse_rotate on both stacks
//     reverse_rotate_b_a(&stack_a, &stack_b);

//     // Print modified stacks
//     printf("\nAfter reverse_rotate_b_a:\n");
//     printf("Modified stack_a: ");
//     printflst(stack_a);
//     printf("Modified stack_b: ");
//     printflst(stack_b);

//     // Free memory (clean up)
//     free(stack_a);
//     free(stack_b);

//     return 0;
// }
