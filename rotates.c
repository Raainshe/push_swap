/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:35:36 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/06 18:44:46 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
}

void	ra(t_list **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	rb(t_list **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}
