/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:26:32 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/27 18:20:28 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int				max_bits;
	int				bit;
	int				size;
	int				i;
	unsigned int	index;

	organize_indexes(a);
	bit = -1;
	size = a->size;
	max_bits = get_max_bits(a);
	while (++bit < max_bits)
	{
		i = -1;
		while (++i < size)
		{
			index = a->head->index;
			if (((index >> bit) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->head != NULL)
			pa(a, b);
	}
}

void	nodes_sort_two(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		sa(stack);
}

void	nodes_sort_three(t_stack *stack)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = stack->head->value;
	v2 = stack->head->next->value;
	v3 = stack->tail->value;
	if (stack->head->next == stack->tail && v1 > v2)
		sa(stack);
	if (v1 > v2 && v2 < v3 && v1 < v3)
		sa(stack);
	else if (v1 > v2 && v2 > v3)
	{
		sa(stack);
		rra(stack);
	}
	else if (v1 > v2 && v2 < v3 && v1 > v3)
		ra(stack);
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		sa(stack);
		ra(stack);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		rra(stack);
}

void	nodes_sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	min2;
	int	size;

	get_two_mins(a, &min, &min2);
	size = a->size;
	while (a->size > size - 2)
	{
		if (a->head->value == min || a->head->value == min2)
			pb(a, b);
		else
			ra(a);
	}
	if (a->size == 2)
		nodes_sort_two(a);
	else
		nodes_sort_three(a);
	if (b->head && b->head->next && b->head->value < b->head->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}
