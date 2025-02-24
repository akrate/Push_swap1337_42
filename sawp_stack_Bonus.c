/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sawp_stack_Bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:50:31 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/24 20:13:15 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_stack(t_list *stack)
{
	int	tmp;

	if (stack && stack->next)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
}

void	swap_stack_ss(t_list *stack_a, t_list *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}
