/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_Bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:47:04 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/24 20:13:00 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !(*stack_b))
		return ;
	if (!*stack_a)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		*stack_a = tmp;
		(*stack_a)->next = NULL;
	}
	else
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, tmp);
	}
}

void	push_to_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a) || !stack_a)
		return ;
	if (!*stack_b)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = tmp;
		(*stack_b)->next = NULL;
	}
	else
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, tmp);
	}
}
