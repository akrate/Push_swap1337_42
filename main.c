/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/13 20:29:42 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicate_before_add(char **strnbr, int i, long new_data)
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
int main(int ac,char **av)
{
   if (ac > 1)
   {
        t_list *stack_a;
        long number;
    
        stack_a = NULL;
         
        char *str = arg_accumulation(ac,av);
        char **strnbr = ft_split(str);
        if (strnbr == NULL)
        {
            free(str);
            exit (1);
        }
        int i = 0;
        while (strnbr[i] != NULL)
        {
            number = ft_atoi(strnbr[i]);
             if (check_duplicate_before_add(strnbr, i, number))
                free_error(&stack_a, strnbr, str);
            ft_lstadd_back_stack(&stack_a,number);
            i++;
        }
        printflst(stack_a);
        free_error(&stack_a, strnbr, str);
   }
   return (0);
}
