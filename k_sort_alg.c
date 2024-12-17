/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:28:53 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/17 12:55:53 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	shortest_route(t_list *stack_b)
{
	int	size;
	int	i;
	int	pos_of_largest;
	int	largest;

	if (!stack_b)
		return (0);
	i = 0;
	size = ft_lstsize(stack_b);
	largest = (int)(intptr_t)stack_b->content;
	pos_of_largest = 0;
	while (stack_b != NULL)
	{
		if ((int)(intptr_t)stack_b->content > largest)
		{
			largest = (int)(intptr_t)stack_b->content;
			pos_of_largest = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	if (pos_of_largest <= size / 2)
		return (pos_of_largest);
	else
		return (pos_of_largest - size);
}

// Sends elements from B back to A
void	send_to_a(t_list **stack_a, t_list **stack_b)
{
	int	direction;

	while (ft_lstsize(*stack_b) != 0)
	{
		direction = shortest_route(*stack_b);
		if (direction > 0)
		{
			while (direction--)
				rb(stack_b);
		}
		else
		{
			while (direction++)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

// Main sorting function
void	k_sort(t_list **stack_a, t_list **stack_b)
{
	int	d_line;
	int	stackb_size;

	d_line = ft_sqrt(ft_lstsize(*stack_a));
	normalise(stack_a);
	while (ft_lstsize(*stack_a) != 0)
	{
		stackb_size = ft_lstsize(*stack_b);
		if ((int)(intptr_t)(*stack_a)->content <= stackb_size)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if ((int)(intptr_t)(*stack_a)->content <= d_line + stackb_size)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	send_to_a(stack_a, stack_b);
}
