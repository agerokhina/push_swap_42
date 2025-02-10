/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:52:55 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/28 13:37:01 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	validate_input1(argc, argv);
	a = init_stack();
	b = init_stack();
	read_stack(a, argc, argv);
	validate_input2(a);
	validate_input3(a);
	if (a->size == 1)
		return (0);
	if (a->size <= 3)
		nodes_sort_three(a);
	else if (a->size <= 5)
		nodes_sort_five(a, b);
	else
		radix_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
