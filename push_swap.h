/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:28:12 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/12 21:09:10 by aoussama         ###   ########.fr       */
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
void free_error(t_list **lst,char **split,char *str);
///////////////////////list
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void printflst(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back_stack(t_list **lst, int data);
void rotate_b(t_list **stack);
//void rotate_a(t_list **stack);




#endif