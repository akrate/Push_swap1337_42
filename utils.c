/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:10:24 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/23 20:40:25 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	checking_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '+' && str[i] != '-' && str[i] != ' ')
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

t_list	*cheapes_stack(t_list **stack_b)
{
	t_list	*cheapest;
	t_list	*b;

	cheapest = *stack_b;
	b = *stack_b;
	while (b)
	{
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

t_list	*find_mini(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
