/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_Bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:27:54 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/25 13:43:54 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_operation(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap_stack(*a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_stack(*b);
	else if (ft_strcmp(str, "ss\n") == 0)
		swap_stack_ss(*a, *b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push_to_a(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push_to_b(b, a);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate_rr(a, b);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		reverse_rotate_b_a(a, b);
	else
		return (1);
	return (0);
}

int	read_line(t_list **stack_a, t_list **stack_b, char **strnbr)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (check_operation(stack_a, stack_b, str) == 1)
		{
			free(str);
			free_main_bo(stack_a, stack_b, strnbr);
			return (1);
		}
		free(str);
		str = get_next_line(0);
	}
	return (0);
}
