/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:28:53 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/10 15:52:29 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	k_sort(t_list *stack_a, t_list *stack_b)
{
	int	d_line;
	int	stackb_size;

	d_line = ft_sqrt(ft_lstsize(stack_a));
	ft_printf("sqrt: %i\n", d_line);
	while (ft_lstsize(stack_a) != 0)
	{
		stackb_size = ft_lstsize(stack_b);
		ft_printf("stack a size ========== %i\n", ft_lstsize(stack_a));
		ft_printf("number:%i | %i", (int)stack_a->content, stackb_size);
		if ((int)stack_a->content <= stackb_size)
		{
			pb(&stack_a, &stack_b);
			rb(&stack_b);
		}
		else if ((int)stack_a->content <= d_line + stackb_size)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a);
	}
	print_values(stack_b);
}
