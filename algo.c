/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:27:54 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/17 21:45:27 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushb(t_list **stack_a,t_list **stack_b)
{
    int size;
    
    size = ft_lstsize(*stack_a);
    while (size > 3)
    {
        if ((*stack_a)->index <= size / 2)
        {
            push_to_b(stack_b,stack_a);
            index_stack(stack_a);
            size--;
        }else{
            rotate(stack_a,"ra\n");
        }
    }
}

void target_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *a = (*stack_a);
    t_list *b = (*stack_b);
    t_list *target;
    int min;

    while (b)
    {
        min = INT_MAX;
        target = NULL; 
        while (a)
        {
            if (a->content > b->content && a->content < min)
            {
                min = a->content;
                target = a;
            }
            a = a->next;
        }
        if (target == NULL)
            target = find_mini(*stack_a);
        b->target = target;
        b = b->next;
        a = (*stack_a);
    }
}
t_list *find_mini(t_list *stack)
{
    t_list *find;
    find = stack;
    while (stack)
    {
        if (stack->content < find->content)
            find = stack;
        stack = stack->next;
    }
    return find;
}
void pos_stack(t_list **stack)
{
    t_list *head;
    int i;

    i = 0;
    head = (*stack);
    while (head)
    {
        head->pos = i;
        i++;
        head = head->next;
    }
}
// void pos_stack_a(t_list **stack)
// {
//     t_list *head;
//     int i;

//     i = 0;
//     head = (*stack);
//     while (head)
//     {
//         head->pos_target = i;
//         i++;
//         head = head->next;
//     }
// }
void pos_target(t_list **stack_a,t_list **stack_b)
{
    t_list *node_a = *stack_a;
    t_list *node_b = *stack_b;
    while (node_b)
    {
        while (node_a)
        {
            if (node_b->target == node_a)
            {
                node_b->pos_target = node_a->pos;
                break;
            }
            node_a = node_a->next;
        }
        node_b = node_b->next;
    }
}
void cost_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *node_b;

    node_b = *stack_b;
    int size_a = ft_lstsize(*stack_a) / 2;
    int size_b =ft_lstsize(*stack_b) / 2;
    int pos_val = 0;
    int targrt_po_val = 0;
    while (node_b)
    {
        if (node_b->pos <= size_b)
            pos_val = node_b->pos;
        else 
            pos_val = size_b - node_b->pos;
        if (node_b->pos_target <= size_a)
            targrt_po_val = node_b->pos;
        else
            targrt_po_val = size_a - node_b->pos;
        if (node_b->pos <= size_b && node_b->pos_target <= size_a 
                        || node_b->pos >= size_b && node_b->pos_target >= size_a)
        {
            if (pos_val > targrt_po_val)
                node_b->cost = pos_val;
            else
                node_b->cost = targrt_po_val;
        }else
            node_b->cost = targrt_po_val + pos_val;
        node_b = node_b->next;
    }
}
