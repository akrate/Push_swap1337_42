/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:34:47 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/19 16:58:45 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstnew(int content)
{
    t_list *node;
    
    node = (t_list *) malloc(sizeof(t_list));
    if (node == NULL)
        return (NULL);
    node->content = content;
    node->index = 0;
    node->next = NULL;
    return (node);
}
void printflst(t_list *lst)
{
    while (lst)
    {
        printf("nbr = %d\n", lst->content);
        lst = lst->next;
    }
}
void printflstg(t_list *lst)
{
    while (lst)
    {
        // إذا كان target ليس فارغًا، قم بطباعة content الخاص به
        if (lst->target)
        {
            printf("nbr = %d-------->target = %d\n", lst->content, lst->target->content);
        }
        
        lst = lst->next;  // الانتقال إلى العنصر التالي في القائمة
    }
}


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
void ft_lstadd_back(t_list **stack, t_list *new_node)
{
    t_list *last;

    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new_node;
	last->next->next = NULL;
}
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}