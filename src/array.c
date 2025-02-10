/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:09:00 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/27 18:15:56 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	fill_indexes(int *array, t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return ;
}

void	sort_indexes(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array [j])
				int_swap(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}

void	organize_indexes(t_stack *stack)
{
	t_node	*current;
	int		*arr;
	int		i;

	arr = (int *)malloc(stack->size * sizeof(int));
	if (!arr)
		ft_return_error("Error", EXIT_ERROR);
	fill_indexes(arr, stack);
	sort_indexes(arr, stack->size);
	current = stack->head;
	while (current)
	{
		i = -1;
		while (++i < stack->size)
		{
			if (current->value == arr[i])
			{
				current->index = i;
				break ;
			}
		}
		current = current->next;
	}
	free(arr);
}
