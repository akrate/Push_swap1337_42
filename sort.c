/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:43:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/23 20:47:12 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		swap_stack(*stack, "sa\n");
}

void	sort_3(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
	{
		rotate(stack, "ra\n");
	}
	sort_2(stack);
	if ((*stack)->content > (*stack)->next->next->content)
	{
		reverse_rotate(stack, "rra\n");
	}
	if ((*stack)->next->content > (*stack)->next->next->content)
	{
		reverse_rotate(stack, "rra\n");
		swap_stack(*stack, "sa\n");
	}
}

void	opration_stack(t_list **stack)
{
	int	i;

	i = ft_lstsize(*stack);
	if (i == 2)
		sort_2(stack);
	else if (i == 3)
		sort_3(stack);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_lstsize(*stack_a);
	if (i <= 3)
		opration_stack(stack_a);
	else
	{
		index_stack(stack_a);
		pushb(stack_a, stack_b);
		sort_3(stack_a);
		push_to_stack_a(stack_a, stack_b);
	}
}

int	check_sort(t_list *list)
{
	while (list && list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
