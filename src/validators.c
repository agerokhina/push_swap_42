/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:53:20 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/28 15:16:28 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isnumber(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < ft_strlen(str))
		if (!ft_isdigit(str[i++]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	validate_input1(int argc, char **argv)
{
	int		i;
	char	**arr;

	i = -1 * (argc == 2);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		while (arr[++i] != NULL)
			if (ft_isnumber(arr[i]) != EXIT_SUCCESS || \
					ft_atol(arr[i]) < INT32_MIN || \
					ft_atol(arr[i]) > INT32_MAX || \
					ft_strlen(arr[i]) > 11)
				ft_return_error("Error", EXIT_ERROR);
		ft_freearr(arr);
	}
	else
	{
		while ((++i) < argc)
			if (ft_isnumber(argv[i]) != EXIT_SUCCESS || \
					ft_atol(argv[i]) < INT32_MIN || \
					ft_atol(argv[i]) > INT32_MAX || \
					ft_strlen(argv[i]) > 11)
				ft_return_error("Error", EXIT_ERROR);
	}
}

void	validate_input2(t_stack *stack)
{
	t_node	*current1;
	t_node	*current2;

	current1 = stack->head;
	while (current1->next != NULL)
	{
		current2 = current1->next;
		while (current2 != NULL)
		{
			if (current1->value == current2->value)
				ft_return_error("Error", EXIT_ERROR);
			current2 = current2->next;
		}
		current1 = current1->next;
	}
}

void	validate_input3(t_stack *stack)
{
	t_node	*current;
	int		fl;

	current = stack->head;
	fl = 1;
	while (current->next != NULL && fl)
	{
		fl = (current->value < current->next->value);
		current = current->next;
	}
	if (fl)
		exit(0);
}
