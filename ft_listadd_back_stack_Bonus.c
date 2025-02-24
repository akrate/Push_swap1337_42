/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_back_stack_Bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:34:09 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/24 20:58:01 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_error(t_list **lst, char **split)
{
	t_list	*current;
	t_list	*next_node;
	int		i;

	current = *lst;
	i = 0;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_main_bo(t_list **stack_a, t_list **stack_b, char **split)
{
	int	i;

	t_list *(next_node), *(current), *(current2), *(next_node2);
	i = 0;
	current = *stack_a;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	current2 = *stack_b;
	while (current2 != NULL)
	{
		next_node2 = current2->next;
		free(current2);
		current2 = next_node2;
	}
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_lstadd_back_stack(t_list **lst, int data)
{
	t_list	*new;
	t_list	*current;

	new = ft_lstnew(data);
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}
