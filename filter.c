/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:02:31 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/04 13:50:06 by aoussama         ###   ########.fr       */
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
                printf("error\n");
                exit(1);
            }
        }
        i++;
    }
    printf("digit nadi\n");
    
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
                printf("sin error\n");
                exit(1);
            }
        }else if(str[i] == '+' || str[i] == '-')
        {
            if (str[i + 1] == ' ' || str[i + 1] == '\0')
            {
                printf("sin error\n");
                exit(1);
            }
        }
        i++;
    }
    printf("sin nadi\n");
}