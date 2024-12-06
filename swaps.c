/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:35 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/06 18:31:33 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_list *list)
{
	t_list	*first;
	t_list	*second;
	void	*temp_c;

	if (ft_lstsize(list) > 1)
	{
		first = list;
		second = first->next;
		temp_c = first->content;
		first->content = second->content;
		second->content = temp_c;
	}
}

// Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	sa(t_list **list)
{
	swap(*list);
	ft_printf("sa\n");
}

//Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void	sb(t_list **list)
{
	swap(*list);
	ft_printf("sb\n");
}

//sa and sb at the same time.
//Swap the first 2 elements at the top of stack a & b.
//Do nothing if there is only one or no elements.
void	ss(t_list **list1, t_list **list2)
{
	swap(*list1);
	swap(*list2);
	ft_printf("ss\n");
}
