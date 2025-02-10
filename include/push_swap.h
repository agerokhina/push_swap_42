/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerokhin <aerokhin@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:52:38 by aerokhin          #+#    #+#             */
/*   Updated: 2025/01/28 15:16:41 by aerokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <ft_printf.h>

# ifndef RETURN_ERROR
#  define RETURN_ERROR 2
#  define EXIT_ERROR 1
# endif

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;	

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

// Function prototypes
// Stack initialization and management
t_stack	*init_stack(void);
t_node	*create_node(int value);
void	push(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	free_stack(t_stack *stack);

// Array functions
void	organize_indexes(t_stack *stack);

// Sorting and operations
void	radix_sort(t_stack *a, t_stack *b);
void	nodes_sort_two(t_stack *stack);
void	nodes_sort_three(t_stack *a);
void	nodes_sort_five(t_stack *a, t_stack *b);

// Moving nodes
// a
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	sa(t_stack *a);
// b
void	pb(t_stack *a, t_stack *b);
void	sb(t_stack *a);

// Extra (prepairing) functions
int		ft_return_error(char *err_msg, int err_flag);
int		get_max_bits(t_stack *stack);
void	get_two_mins(t_stack *stack, int *min1, int *min2);
void	print_stack(t_stack *stack);
long	ft_atol(const char *nptr);

//Reading
void	ft_freearr(char **arr);
void	read_stack(t_stack *stack, int argc, char **argv);

// Validation functions
int		ft_isnumber(char *str);
int		ft_isspace(char c);
void	validate_input1(int argc, char **argv);
void	validate_input2(t_stack *stack);
void	validate_input3(t_stack *stack);

#endif