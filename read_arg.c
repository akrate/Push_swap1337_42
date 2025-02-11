/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:25:27 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/08 13:46:09 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void ft_null(char *str)
{
    int i;
    int check;
    
    check = 0;
    i = 0;
    if (str[i] == '\0')
    {
        write(2,"Erorr\n",6);
        exit (1);
    }
    while (str[i])
    {
        if(str[i] != ' ')
            check = 1;
        i++;
    }
    if(check == 0)
    {
        write(2,"Erorr\n",6);
        exit (1);
    }
}
static int countline_arg(int ac,char **av)
{
    int i;
    int j;
    int count;
    
    i = 1;
    count = 0;
    while(i < ac)
    {
        j = 0; 
        ft_null(av[i]); 
        while(av[i][j])
        {
            j++;
        }
        i++;
        count += j;
    } 
    return (count);
}
static int filter(char *str)
{
    if (checking_digit(str) == 1)
    {
        return (1);
    }
    if (checking_sin(str) == 1)
    {
        return (1);
    }
    return (0);
}
char *arg_accumulation(int ac,char **av)
{
    int i;
    int j;
    int index;
    char *str;
    
    i = 1;
    index = 0;
    str = (char *)malloc((countline_arg(ac,av) + (ac - 2) + 1) * sizeof(char));
    if(str == NULL)
        exit(1);
    while(i < ac)
    {
        j = 0;
        while(av[i][j])
            str[index++] = av[i][j++];
        if (i < ac - 1)
            str[index++] = ' ';
        i++;
    } 
    str[index] = '\0';
    if(filter(str) == 1)
    {
        free(str);
        exit (1);
    }
    return (str);
}
