/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/08 10:14:11 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
            if (ft_lstadd_back(&stack_a,number) == 1)
            {
                free(str);
                free(stack_a);
                free(strnbr);
                exit (1);
            }
            i++;
        }
        printflst(stack_a);
   }
   return (0);
}
