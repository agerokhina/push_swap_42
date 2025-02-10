/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:55:46 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/28 15:15:59 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_return_error(char *err_msg, int err_flag)
{
	if (err_flag == EXIT_ERROR)
	{
		ft_putendl_fd(err_msg, 1);
		exit (EXIT_FAILURE);
	}
	else
	{
		ft_putendl_fd(err_msg, 1);
		return (EXIT_FAILURE);
	}
}

int	get_max_bits(t_stack *stack)
{
	int		max;
	int		bits;

	if (stack->head == NULL)
		return (-1);
	max = stack->size;
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	get_two_mins(t_stack *stack, int *min1, int *min2)
{
	t_node	*current;

	current = stack->head;
	*min1 = INT32_MAX;
	*min2 = INT32_MAX;
	while (current != NULL)
	{
		if (current->value < *min1)
		{
			*min2 = *min1;
			*min1 = current->value;
		}
		else if (current->value < *min2)
			*min2 = current->value;
		current = current->next;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return ;
	current = stack->head;
	ft_printf("");
	while (current)
	{
		ft_printf ("%d:%d, ", current->index, current->value);
		current = current->next;
	}
	ft_printf("\n");
}

long	ft_atol(const char *nptr)
{
	long			i;
	unsigned long	res;
	int				str_len;
	long			sign;

	i = 0;
	res = 0;
	sign = 1;
	str_len = ft_strlen(nptr);
	while (ft_isspace(nptr[i]) == 1 && (i < str_len))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (i < str_len && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return ((sign * (long)res));
}
