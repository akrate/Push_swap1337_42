/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/14 00:04:26 by aoussama         ###   ########.fr       */
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

static char **opration_stack(int ac,char **av)
{
    char *str;
    char **nbr;
    
    str = arg_accumulation(ac,av);
    nbr = ft_split(str);
    if (nbr == NULL)
    {
        free(str);
        exit (1);
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

int main(int ac,char **av)
{
   if (ac > 1)
   {
        t_list *stack_a;
        char **strnbr;
    
        stack_a = NULL;
        strnbr = opration_stack(ac,av);
        stack_a = usenbr_to_stack(strnbr);
        printflst(stack_a);
        free_error(&stack_a, strnbr);
   }
   return (0);
}
