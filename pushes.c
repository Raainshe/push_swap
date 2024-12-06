/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:34:14 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/06 18:27:03 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//take the first element at the top of a/b and put it at the top of a/b.
//Do nothing if a/b is empty.
void	push(t_list **stack1, t_list **stack2)
{
	t_list	*first;

	if (*stack1 == NULL)
		return ;
	first = *stack1;
	*stack1 = first->next;
	first->next = *stack2;
	*stack2 = first;
}

//ake the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void	pa(t_list **stacka, t_list **stackb)
{
	push(stackb, stacka);
	ft_printf("pa\n");
}

//ake the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
void	pb(t_list **stacka, t_list **stackb)
{
	push(stacka, stackb);
	ft_printf("pb\n");
}
