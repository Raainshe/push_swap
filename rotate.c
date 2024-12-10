/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryan <ryan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:35:36 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/06 22:49:58 by ryan             ###   ########.fr       */
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

//Shift up all elements of stack a by 1.
//The first element becomes the last one
void	ra(t_list **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

//Shift up all elements of stack b by 1.
//The first element becomes the last one
void	rb(t_list **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}

//Shift up all elements of stack a & b by 1.
//The first element becomes the last one
void	rr(t_list **lista, t_list **listb)
{
	rotate(lista);
	rotate(listb);
	ft_printf("rr\n");
}
