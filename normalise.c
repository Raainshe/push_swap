/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:00:34 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/16 12:21:35 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
			if ((int)current->content == (int)checker->content)
			{
				return (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	get_largest(t_list *stack)
{
	t_list	*largest;

	largest = stack;
	while (stack != NULL)
	{
		if ((int)largest->content < (int)stack->content)
			largest = stack;
		stack = stack->next;
	}
	return ((int)largest->content);
}

int	get_smallest(t_list *stack)
{
	t_list	*smallest;

	smallest = stack;
	while (stack != NULL)
	{
		if ((int)smallest->content > (int)stack->content)
			smallest = stack;
		stack = stack->next;
	}
	return ((int)smallest->content);
}
void	normalise(t_list **stack)
{
	int		largest;
	int		smallest;
	int		k;
	t_list	*current;
	int		i_current;

	if (has_duplicates(*stack))
		exit(EXIT_FAILURE);
	k = ft_sqrt(ft_lstsize(*stack));
	largest = get_largest(*stack);
	smallest = get_smallest(*stack);
	if (largest == smallest)
		return ;
	if (*stack == NULL || (*stack)->next == NULL || largest == smallest)
		return ;
	current = *stack;
	while (current != NULL)
	{
		i_current = (int)current->content;
		current->content = (void *)(intptr_t)(k * ((i_current - smallest)
					/ (largest - smallest)));
		current = current->next;
	}
}
