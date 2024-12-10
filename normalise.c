/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:00:34 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/10 17:30:03 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_largest(t_list *stack)
{
	t_list	*largest;

	largest = stack;
	while (stack != NULL)
	{
		if ((int)largest->content > (int)stack->content)
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
		if ((int)smallest->content < (int)stack->content)
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

	k = ft_sqrt(ft_lstsize(*stack));
	largest = get_largest(*stack);
	smallest = get_smallest(*stack);
	if (largest == smallest)
		return ;
	current = *stack;
	while (current != NULL)
	{
		current->content = (intptr_t)(k * (((float)current->content - smallest)
					/ (largest - smallest)));
		current = current->next;
	}
}
