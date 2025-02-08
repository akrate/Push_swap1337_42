/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/08 11:51:32 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicate_before_add(char **strnbr, int i, int new_data)
{
    int j = 0;
    while ( j < i)
    {
        if (new_data == ft_atoi(strnbr[j]))
        {
            return 1; 
        }
         j++;
    }
    return 0;
}
int main(int ac,char **av)
{
   if (ac > 1)
   {
        t_list *stack_a;
        int number;
    
        stack_a = NULL;
         
        char *str = arg_accumulation(ac,av);
        char **strnbr = ft_split(str);
        int i = 0;
        while (strnbr[i] != NULL)
        {
            number = ft_atoi(strnbr[i]);
             if (check_duplicate_before_add(strnbr, i, number))
                free_error(&stack_a, strnbr, str);
            ft_lstadd_back(&stack_a,number);
            i++;
        }
        printflst(stack_a);
        free_error(&stack_a, strnbr, str);
   }
   return (0);
}
