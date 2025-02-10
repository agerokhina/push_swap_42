/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:49:55 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/27 18:20:37 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void	read_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	t_node	*node;
	char	**arr;

	i = (argc != 2) * argc;
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			ft_return_error("Error", EXIT_ERROR);
		while (arr[i] != NULL)
			i++;
	}
	else
		arr = argv;
	while (--i >= (argc > 2))
	{
		node = create_node(ft_atoi(arr[i]));
		push(stack, node);
	}
	if (argc == 2)
		ft_freearr(arr);
}
