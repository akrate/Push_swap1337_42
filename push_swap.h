/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:28:12 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/08 14:06:55 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct l_list
{
    int content;
    struct l_list *next;
}   t_list;

char *arg_accumulation(int ac,char **av);
int checking_digit(char *str);
int checking_sin(char *str);
int long ft_atoi(const char *str);
char	**ft_split(char const *s);
void	ft_lstadd_back(t_list **lst, int data);
t_list	*ft_lstnew(int content);
void printflst(t_list *lst);
void free_error(t_list **lst,char **split,char *str);


#endif