/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacknode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:13:44 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/28 15:15:23 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ft_return_error("Error", EXIT_ERROR);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_return_error("Error", EXIT_ERROR);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	stack->size--;
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return ;
	while (stack->head)
	{
		node = pop(stack);
		free(node);
	}
	free(stack);
}
