/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:27:54 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/23 18:08:43 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushb(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);

    while (size > 3)
    {
        if ((*stack_a)->index <= size / 2)
        {
            push_to_b(stack_b, stack_a);
            index_stack(stack_a);
            size--;
        }
        else
        {
            rotate(stack_a, "ra\n");
        }
    }
}

void target_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *a;
    t_list *b;
    t_list *target;
    int min;
    
    b = *stack_b;
    while (b)
    {
        target = NULL;
        min = INT_MAX;
        a = *stack_a;
        while (a)
        {
            if (a->content > b->content && a->content <= min)
            {
                min = a->content;
                target = a;
            }
            a = a->next;
        }
        if (target)
            b->target = target;
        else
            b->target = find_mini(*stack_a);
        b = b->next;
    }
}

t_list *find_mini(t_list *stack)
{
    t_list *min;

    min = stack;
    while (stack)
    {
        if (stack->content < min->content)
            min = stack;
        stack = stack->next;
    }
    return min;
}

void pos_stack(t_list **stack)
{
    t_list *head;
    int i;

    i = 0;
    head = *stack;
    while (head)
    {
        head->pos = i;
        head = head->next;
        i++;
    }
}

void cost_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *b;
    int (target_pos_val),pos_val,size_a,size_b;

    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
    b = *stack_b;
    while (b)
    {
        if (b->pos <= size_b / 2)
            pos_val = b->pos;
        else
            pos_val = size_b - b->pos;
        if (b->target->pos <= size_a / 2)
            target_pos_val = b->target->pos;
        else
            target_pos_val = size_a - b->target->pos;
        if ((b->pos <= size_b / 2 && b->target->pos <= size_a / 2) ||
            (b->pos >= size_b / 2 && b->target->pos >= size_a / 2))
            if (pos_val > target_pos_val)
                b->cost = pos_val;
            else
                b->cost = target_pos_val;
        else
            b->cost = pos_val + target_pos_val;
        b = b->next;
    }
}

t_list *cheapes_stack(t_list **stack_b)
{
    t_list *cheapest;
    t_list *b;

    cheapest = *stack_b;
    b = *stack_b;
    while (b)
    {
        if (b->cost < cheapest->cost)
            cheapest = b;
        b = b->next;
    }
    return cheapest;
}

void move_to_top(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
    int size_a;
    int size_b;

    size_a = ft_lstsize(*stack_a) / 2;
    size_b = ft_lstsize(*stack_b) / 2;
    
   if (cheapest->pos <= size_b && cheapest->target->pos <= size_a )
		while (cheapest != *stack_b && cheapest->target != *stack_a)
			rotate_rr(stack_a, stack_b);
	if (cheapest->pos >= size_b && cheapest->target->pos >= size_a )
		while (cheapest != *stack_b && cheapest->target != *stack_a)
			reverse_rotate_b_a(stack_a, stack_b);
    while (cheapest != *stack_b)
        if (cheapest->pos <= size_b)
            rotate(stack_b, "rb\n");
        else
            reverse_rotate(stack_b, "rrb\n");
            
    while (cheapest->target != *stack_a)
        if (cheapest->target->pos >= size_a)
            reverse_rotate(stack_a, "rra\n");
        else
            rotate(stack_a, "ra\n");
}

// void move_to_top(t_list **stack_a, t_list **stack_b, t_list *cheapest)
// {
//     int size_a;
//     int size_b;

//     size_a = ft_lstsize(*stack_a) / 2;
//     size_b = ft_lstsize(*stack_b) / 2;
    
//     while (cheapest != *stack_b && cheapest->target != *stack_a)
//     {
//         if (cheapest->pos < size_b && cheapest->target->pos < size_a)
//         {
//             rotate_rr(stack_a, stack_b);
//         }
//         else if (cheapest->pos > size_b && cheapest->target->pos > size_a)
//         {
//             reverse_rotate_b_a(stack_a, stack_b);
//         }
//         else if (cheapest->pos < size_b && cheapest->target->pos > size_a)
//         {
//             if (cheapest->pos <= size_b)
//             {
//                 rotate(stack_b, "rb\n");
//             }
//             else
//             {
//                 reverse_rotate(stack_b, "rrb\n");
//             }    
//         }
//         else if (cheapest->pos > size_b && cheapest->target->pos < size_a)
//         {
//             if (cheapest->target->pos >= size_a)
//             {
//                 reverse_rotate(stack_a, "rra\n");
//             }
//             else
//             {
//                 rotate(stack_a, "ra\n");
//             }
//         }
//     }
// }


void push_to_stack_a(t_list **stack_a, t_list **stack_b)
{
    t_list *cheapest;
    t_list *mini_node;
    
    while (*stack_b)
    {
        target_stack(stack_a, stack_b);
        pos_stack(stack_b);
        pos_stack(stack_a);
        cost_stack(stack_a, stack_b);
        cheapest = cheapes_stack(stack_b);
        move_to_top(stack_a, stack_b, cheapest);
        push_to_a(stack_a, stack_b);
    }
    mini_node = find_mini(*stack_a);
    if (!check_sort(*stack_a))
    {
        int mid = ft_lstsize(*stack_a) / 2;
        while (*stack_a != mini_node)
        {
            if (mini_node->pos <= mid)
                rotate(stack_a, "ra\n");
            else
                reverse_rotate(stack_a, "rra\n");
        }
    }
}
