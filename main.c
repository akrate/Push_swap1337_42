/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/07 18:02:04 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac,char **av)
{
    t_list *stack_a;
    int number;

    stack_a = NULL;
     
    char *str = arg_accumulation(ac,av);
    checking_digit(str);
    checking_sin(str);
    char **strnbr = ft_split(str);
    int i = 0;
    while (strnbr[i] != NULL)
    {
        number = ft_atoi(strnbr[i]);
        ft_lstadd_back(&stack_a,number);
        i++;
    }
    printflst(stack_a);
}