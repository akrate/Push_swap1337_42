/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:47:04 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/25 20:05:07 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushb(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		if ((*stack_a)->index < size / 2)
		{
			push_to_b(stack_b, stack_a);
			index_stack(stack_a);
			size--;
		}
		else
		{
			rotate(stack_a, "ra\n");
		}
	}
}

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
	write(1, "pa\n", 3);
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
	write(1, "pb\n", 3);
}
