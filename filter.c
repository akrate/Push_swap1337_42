/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:02:31 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/07 17:56:37 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void checking_digit(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
        {
            if (str[i] != '+' && str[i] != '-' && str[i] != ' ')
            {
                write(1,"error\n",6);
                free(str);
                exit(1);
            }
        }
        i++;
    }
}
void checking_sin(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if(str[i + 1] == '+' || str[i + 1] == '-')
            {
                write(1,"error\n",6);
                free(str);
                exit(1);
            }
        }else if(str[i] == '+' || str[i] == '-')
        {
            if (str[i + 1] == ' ' || str[i + 1] == '\0')
            {
                write(1,"error\n",6);
                free(str);
                exit(1);
            }
        }
        i++;
    }
}