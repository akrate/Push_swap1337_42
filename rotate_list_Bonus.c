/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list_Bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:56:27 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/24 20:13:11 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = ft_lstlast(*stack);
	last = *stack;
	while (last->next->next)
		last = last->next;
	last->next = NULL;
	ft_lstadd_front(stack, tmp);
}

void	reverse_rotate_b_a(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_b);
	reverse_rotate(stack_a);
}
