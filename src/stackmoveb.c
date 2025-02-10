/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmoveb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:01:39 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/28 15:16:07 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->head != NULL)
	{
		node = pop(a);
		push(b, node);
		write (1, "pb\n", 3);
	}
}

void	sb(t_stack *a)
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
	write (1, "sb\n", 3);
}
