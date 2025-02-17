/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/17 13:45:26 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_duplicate_before_add(char **strnbr, int i, long new_data)
{
    int j = 0;
    while ( j < i)
    {
        if (new_data == ft_atoi(strnbr[j]))
        {
            return (1); 
        }
        if (new_data < INT_MIN || new_data > INT_MAX)
        {
            return (1);
        }
         j++;
    }
    return (0);
}

static char **breaking_words(int ac,char **av)
{
    char *str;
    char **nbr;
    
    str = arg_accumulation(ac,av);
    nbr = ft_split(str);
    if (nbr == NULL)
    {
        free(str);
        exit(1);
    }
    free(str);
    return (nbr);
}
static t_list *usenbr_to_stack(char **str)
{
    t_list *stack;
    int i;
    long number;
    
    stack = NULL;
    i = 0;
    while (str[i] != NULL)
    {
        number = ft_atoi(str[i]);
         if (check_duplicate_before_add(str, i, number))
            free_error(&stack, str);
        ft_lstadd_back_stack(&stack,number);
        i++;
    }
    return (stack);
    
}

int check_sort(t_list *list)
{
    while (list && list->next)
    {
        if (list->content > list->next->content)
            return (0);
        list = list->next;
    }
    return (1);
}
void sort_2(t_list **stack)
{
    if ((*stack)->content > (*stack)->next->content)
        swap_stack(*stack,"sa\n");
}
int git_max(t_list *stack)
{
    int i;
    t_list *lst = stack;
    
    i = lst->content;
    if (i < lst->next->content)
        i = lst->next->content;
    if (i < lst->next->next->content)
        i = lst->next->next->content;
    return (i);
}
void sort_3(t_list **stack)
{
    if ((*stack)->content > (*stack)->next->content
        && (*stack)->content > (*stack)->next->next->content)
    {
        rotate(stack,"ra\n");
    }
    sort_2(stack);
    if ((*stack)->content > (*stack)->next->next->content)
    {
        reverse_rotate(stack,"rra\n");
    }
    if ((*stack)->next->content > (*stack)->next->next->content)
    {
        reverse_rotate(stack,"rra\n");
        swap_stack(*stack,"sa\n");
    }
}
void opration_stack(t_list **stack)
{
    int i;

    i = ft_lstsize(*stack);
    if (i == 2)
        sort_2(stack);
    else if (i == 3)
        sort_3(stack);
}

int main(int ac,char **av)
{
   if (ac > 1)
   {
        t_list *stack_a;
        t_list *stack_b;
        char **strnbr;
        // int size_stack;
    
        stack_a = NULL;
        stack_b = NULL;
        strnbr = breaking_words(ac,av);
        stack_a = usenbr_to_stack(strnbr);
        if (check_sort(stack_a) == 0)
        {
            index_stack(&stack_a);
            // // printf("test1");
            pushb(&stack_a,&stack_b);
            opration_stack(&stack_a);
            target_stack(&stack_a,&stack_b);
            // printf("test2");
            // size_stack = ft_lstsize(stack_a);
            // while (size_stack > 3)
            // {
            //     index_stack(&stack_a);
            // // printf("test1");
            //     pushb(&stack_a,&stack_b);
            //     size_stack--;
            // }
        }
        printflst(stack_a);
        printf("------------------------------");
        printflstg(stack_b);

        // printflst(find_mini(stack_a));
        free_main(&stack_a,&stack_b, strnbr);
   }
   return (0);
}
