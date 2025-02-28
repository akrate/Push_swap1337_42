/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:55:34 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/23 20:16:00 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_list **list)
{
	int		i;
	t_list	*node;
	t_list	*current;

	if (!list || !*list)
		return ;
	current = *list;
	i = 0;
	while (current)
	{
		node = *list;
		while (node)
		{
			if (current->content != node->content)
			{
				if (current->content > node->content)
					i++;
			}
			node = node->next;
		}
		current->index = i;
		current = current->next;
		i = 0;
	}
}
