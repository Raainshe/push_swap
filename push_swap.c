/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:23:26 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/18 14:43:02 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_values(t_list *stack)
{
	int	num;

	while (stack != NULL)
	{
		num = (int)(intptr_t)stack->content;
		ft_printf("%i\n", num);
		stack = stack->next;
	}
}

void	ft_free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

// Checks if a list is already sorted
int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if ((int)(intptr_t)stack->content > (int)(intptr_t)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Creates a linked list from command line arguments
t_list	*create_list(char **argv, size_t *size, int argc, int type)
{
	long	content;
	size_t	i;
	t_list	*stacka;
	t_list	*new_node;
	t_list	*tail;

	stacka = NULL;
	tail = NULL;
	i = 0;
	*size = 0;
	while (i < (size_t)argc)
	{
		if (!ft_str_is_numeric(argv[i + !type]))
			return (ft_free_stack(&stacka), NULL);
		content = ft_atoi(argv[i + !type]);
		if (content > INT_MAX || content < INT_MIN)
			return (ft_free_stack(&stacka), NULL);
		new_node = ft_lstnew((void *)(intptr_t)content);
		if (!new_node)
			return (ft_free_stack(&stacka), NULL);
		if (!stacka)
			stacka = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		(*size)++;
		i++;
	}
	return (stacka);
}

// Decides sorting algorithm based on list size
int	decision_alg(size_t size)
{
	if (size > 10)
		return (1);
	if (size > 3)
		return (1);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	size_t	a_size;
	char	**arguments;

	stacka = NULL;
	stackb = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		arguments = ft_split(argv[1], ' ');
		stacka = create_list(arguments, &a_size, (int)ft_arrlen(arguments), 1);
		free(arguments);
	}
	else
		stacka = create_list(argv, &a_size, argc - 1, 0);
	if (!stacka)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (is_sorted(stacka))
		return (ft_free_stack(&stacka), 0);
	if (decision_alg(a_size) == 1)
		k_sort(&stacka, &stackb);
	//ft_printf("Sorted stack:\n");
	// print_values(stacka);
	ft_free_stack(&stacka);
	return (0);
}
