/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:28:12 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/24 22:07:03 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct l_list
{
	int				content;
	int				index;
	int				pos;
	int				cost;
	struct l_list	*target;
	struct l_list	*next;
}					t_list;


char				*arg_accumulation(int ac, char **av);
int					checking_digit(char *str);
int					checking_sin(char *str);
int long			ft_atoi(const char *str);
char				**ft_split(char const *s);
void				free_error(t_list **lst, char **split);
///////////////////////list
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back_stack(t_list **lst, int data);
void				ft_lstadd_back(t_list **stack, t_list *new_node);
int 				read_line(t_list **stack_a,t_list **stack_b, char **strnbr);
int					ft_lstsize(t_list *lst);
void				free_main_bo(t_list **stack_a, t_list **stack_b, char **split);
void				put_str(char *str);
void				rotate(t_list **stack);
void				rotate_rr(t_list **stack_a, t_list **stack_b);
void				reverse_rotate(t_list **stack);
void				reverse_rotate_b_a(t_list **stack_a, t_list **stack_b);
void				swap_stack(t_list *stack);
void				swap_stack_ss(t_list *stack_a, t_list *stack_b);
void				push_to_b(t_list **stack_b, t_list **stack_a);
void				push_to_a(t_list **stack_a, t_list **stack_b);;
int					check_sort(t_list *list);
void				sort_stack(t_list **stack_a, t_list **stack_b);
int					ft_strcmp(char *s1, char *s2);
//////////////////////////////////next_line
char	*get_next_line(int fd);
int		ft_strchr(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*get_left_line(char *str);
char	*get_right_line(char *str);
int		ft_strlen(char *str);

////////////////////////////////////

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
