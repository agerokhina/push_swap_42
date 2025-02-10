/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmoveb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:01:39 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/16 13:29:20 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->head != NULL)
	{
		node = pop(b);
		push(a, node);
		write (1, "pa\n", 3);
	}
}

void	ra(t_stack *a)
{
	t_node	*node;

	if (a->head != NULL && a->head != a->tail)
	{
		node = pop(a);
		a->size++;
		if (node)
		{
			node->next = NULL;
			node->prev = a->tail;
			a->tail->next = node;
			a->tail = node;
		}
		write (1, "ra\n", 3);
	}
}

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*prev_last;

	if (a->head == NULL || a->head == a->tail)
		return ;
	last = a->tail;
	prev_last = a->tail->prev;
	prev_last->next = NULL;
	a->tail = prev_last;
	last->next = a->head;
	last->prev = NULL;
	a->head->prev = last;
	a->head = last;
	write (1, "rra\n", 4);
}

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->head == NULL || a->head == a->tail)
		return ;
	first = a->head;
	second = a->head->next;
	first->next = second->next;
	if (second->next != NULL)
		first->next->prev = first;
	second->prev = NULL;
	first->prev = second;
	second->next = first;
	a->head = second;
	write (1, "sa\n", 3);
}
