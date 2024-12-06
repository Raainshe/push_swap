/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:50:12 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/06 19:22:03 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next == NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

//Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	rra(t_list **lista)
{
	reverse_rotate(lista);
	ft_printf("rra\n");
}

//Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	rrb(t_list **listb)
{
	reverse_rotate(listb);
	ft_printf("rrb\n");
}

//Shift down all elements of stack a by 1.
//The last element becomes the first one.
//rra and rrb at the same time
void	rrr(t_list **lista, t_list **listb)
{
	reverse_rotate(lista);
	reverse_rotate(listb);
	ft_printf("rrr\n");
}
