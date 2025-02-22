/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:27:54 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/22 20:32:55 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushb(t_list **stack_a,t_list **stack_b)
{
    int size;
    
    size = ft_lstsize(*stack_a);
    while (size > 3)
    {
        if ((*stack_a)->index <= size / 4)
        {
            push_to_b(stack_b,stack_a);
            index_stack(stack_a);
            size = ft_lstsize(*stack_a);
        }
        else{
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

    // هنا نستخدم البحث الثنائي بدلاً من الفحص البسيط.
    while (b)
    {
        min = INT_MAX;
        target = NULL;
        
        // استخدم البحث الثنائي أو تحديد أقرب هدف بشكل أكثر كفاءة
        while (a)
        {
            if (a->content > b->content && a->content <= min)
            {
                min = a->content;
                target = a;
            }
            a = a->next;
        }
        
        if (target == NULL)
            target = find_mini(*stack_a); // إذا لم نجد هدفًا، نبحث عن العنصر الأصغر

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
        if (node_b->target->pos <= size_a)
            targrt_po_val = node_b->pos;
        else
            targrt_po_val = size_a - node_b->target->pos;
        if ((node_b->pos <= size_b && node_b->target->pos <= size_a) 
                        || (node_b->pos >= size_b && node_b->target->pos >= size_a))
        {
            if (pos_val > targrt_po_val)
                node_b->cost = pos_val;
            else
                node_b->cost = targrt_po_val;
        }
        else
            node_b->cost = targrt_po_val + pos_val;
        node_b = node_b->next;
    }
}
t_list *cheapes_satck(t_list **stack_b)
{
    t_list *result;
    t_list *stack;
    
    stack = *stack_b;
    result = *stack_b;
    while (stack)
    {
        // && stack->target->cost < result->target->cost
        if(stack->cost < result->cost )
        {
            result = stack;
        }
        stack = stack->next;
    }
    return (result);
}
void move_to_top(t_list **stack_a, t_list **stack_b, t_list *cheaps_node)
{
    int size_a = ft_lstsize(*stack_a) / 2;
    int size_b = ft_lstsize(*stack_b) / 2;

    while (cheaps_node != *stack_b && cheaps_node->target != *stack_a)
    {
        if (cheaps_node->pos < size_b && cheaps_node->target->pos < size_a)
            rotate_rr(stack_a, stack_b);
        else if (cheaps_node->pos > size_b && cheaps_node->target->pos > size_a)
            reverse_rotate_b_a(stack_a, stack_b);
        else
            break;
    }

    while (cheaps_node != *stack_b)
    {
        if (cheaps_node->pos <= size_b)
            rotate(stack_b, "rb\n");
        else
            reverse_rotate(stack_b, "rrb\n");
    }

    while (cheaps_node->target != *stack_a)
    {
        if (cheaps_node->target->pos >= size_a)
            reverse_rotate(stack_a, "rra\n");
        else
            rotate(stack_a, "ra\n");
    }
}



void push_to_stack_a(t_list **stack_a, t_list **stack_b)
{
    t_list *cheaps;
    t_list *mini_node;
    while (*stack_b)
    {
        target_stack(stack_a,stack_b);
        pos_stack(stack_b);
        pos_stack(stack_a);
        cost_stack(stack_a,stack_b);
        cheaps = cheapes_satck(stack_b);
        move_to_top(stack_a,stack_b,cheaps);
        push_to_a(stack_a,stack_b);
    }
    mini_node = find_mini(*stack_a); 
    if (check_sort(*stack_a)== 0)
    {
        int i = ft_lstsize(*stack_a) / 2;
        while (*stack_a != mini_node)
        {
            if (mini_node->pos <= i)
                rotate(stack_a,"ra\n");
            else
                reverse_rotate(stack_a,"rra\n");
        }
    }
}
