/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_Bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:45:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/24 21:21:46 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_duplicate_before_add(char **strnbr, int i, long new_data)
{
	int	j;

	j = 0;
    if (new_data < INT_MIN || new_data > INT_MAX)
		{
			return (1);
		}
	while (j < i)
	{
		if (new_data == ft_atoi(strnbr[j]))
		{
			return (1);
		}
		if (new_data < INT_MIN || new_data > INT_MAX)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

static char	**breaking_words(int ac, char **av)
{
	char	*str;
	char	**nbr;

	str = arg_accumulation(ac, av);
	nbr = ft_split(str);
	if (nbr == NULL)
	{
		free(str);
		exit(1);
	}
	free(str);
	return (nbr);
}

static t_list	*usenbr_to_stack(char **str)
{
	t_list	*stack;
	int		i;
	long	number;

	stack = NULL;
	i = 0;
	while (str[i] != NULL)
	{
		number = ft_atoi(str[i]);
		if (check_duplicate_before_add(str, i, number))
			free_error(&stack, str);
		ft_lstadd_back_stack(&stack, number);
		i++;
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**strnbr;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		strnbr = breaking_words(ac, av);
		stack_a = usenbr_to_stack(strnbr);
		if (read_line(&stack_a, &stack_b, strnbr) == 1)
		{
			write (2,"Error\n",6);
			return (1);
		}
		if (check_sort(stack_a) && !stack_b)
			write (1,"OK\n",3);
		else
			write (1,"KO\n",3);
		free_main_bo(&stack_a, &stack_b, strnbr);
	}
	return (0);
}
