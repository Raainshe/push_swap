/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:00:34 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/17 12:32:50 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Checks for duplicate values in stack
int	has_duplicates(t_list *stack)
{
	t_list	*checker;
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if ((int)(intptr_t)current->content == (int)(intptr_t)checker->content)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

// Finds largest value in stack
int	get_largest(t_list *stack)
{
	t_list	*largest;

	largest = stack;
	while (stack != NULL)
	{
		if ((int)(intptr_t)largest->content < (int)(intptr_t)stack->content)
			largest = stack;
		stack = stack->next;
	}
	return ((int)(intptr_t)largest->content);
}

// Finds smallest value in stack
int	get_smallest(t_list *stack)
{
	t_list	*smallest;

	smallest = stack;
	while (stack != NULL)
	{
		if ((int)(intptr_t)smallest->content > (int)(intptr_t)stack->content)
			smallest = stack;
		stack = stack->next;
	}
	return ((int)(intptr_t)smallest->content);
}

// Normalizes stack values
void	normalise(t_list **stack)
{
	int		largest;
	int		smallest;
	int		k;
	t_list	*current;
	double	i_current;

	if (has_duplicates(*stack))
		exit(EXIT_FAILURE);
	k = ft_sqrt(ft_lstsize(*stack));
	largest = get_largest(*stack);
	smallest = get_smallest(*stack);
	if (*stack == NULL || (*stack)->next == NULL || largest == smallest)
		return ;
	current = *stack;
	while (current != NULL)
	{
		i_current = (int)(intptr_t)current->content;
		current->content = (void *)(intptr_t)((int)(k * ((i_current - smallest)
						/ (double)(largest - smallest))));
		current = current->next;
	}
}
