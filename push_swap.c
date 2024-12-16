/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:23:26 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/16 18:51:00 by rmakoni          ###   ########.fr       */
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
t_list	*create_list(char **argv, size_t *size, int argc)
{
	size_t	i;
	int		content;
	t_list	*stacka;
	t_list	*new_node;
	t_list	*tail;

	i = 0;
	*size = 0;
	while (i < (size_t)argc)
	{
		content = ft_atoi(argv[i + 1]);
		new_node = ft_lstnew((void *)(intptr_t)content);
		if (!new_node)
			return (NULL);
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

int	decision_alg(size_t size)
{
	if (size > 10)
		return (1);
	if (size > 3)
		return (2);
	else
		return (3);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	size_t	a_size;

	stackb = NULL;
	if (argc < 2)
		return (ft_printf("You have not entered enough data for the list!"), 1);
	stacka = create_list(argv, &a_size, argc - 1);
	if (!stacka)
		return (ft_printf("Error with the data!"), 1);
	if (decision_alg(a_size) == 1)
		k_sort(stacka, stackb);
	return (0);
}
