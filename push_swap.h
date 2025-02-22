/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:28:12 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/21 11:57:18 by aoussama         ###   ########.fr       */
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
    int index;
    int pos;
    int pos_target;
    int cost;
    // int cost_b;
    // int cost_a;
    struct l_list *target;
    struct l_list *next;
}   t_list;

char *arg_accumulation(int ac,char **av);
int checking_digit(char *str);
int checking_sin(char *str);
int long ft_atoi(const char *str);
char	**ft_split(char const *s);
void free_error(t_list **lst,char **split);
///////////////////////list
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void printflst(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back_stack(t_list **lst, int data);
int	ft_lstsize(t_list *lst);
// void rotate_b(t_list **stack);
//void rotate_a(t_list **stack);
void free_main(t_list **stack_a,t_list **stack_b,char **split);
void put_str(char *str);
void rotate(t_list **stack,char *str);
void rotate_rr(t_list **stack_a,t_list **stack_b);
void reverse_rotate(t_list **stack,char *str);
void reverse_rotate_b_a(t_list **stack_a,t_list **stack_b);
void swap_stack(t_list *stack,char *str);
void swap_stack_ss(t_list *stack_a,t_list *stack_b);
void push_to_b(t_list **stack_b,t_list **stack_a);
void push_to_a(t_list **stack_a, t_list **stack_b);
void pushb(t_list **stack_a,t_list **satck_b);
void index_stack(t_list **list);
void target_stack(t_list **stack_a,t_list **stack_b);
// void printflstindex(t_list *lst);
t_list *find_mini(t_list *stack);
void printflstg(t_list *lst);
void push_to_stack_a(t_list **stack_a, t_list **stack_b);
int check_sort(t_list *list);

#endif
