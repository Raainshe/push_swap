/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:46 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/10 15:07:38 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/ft_printf.h"
# include "libft/libft.h"

void	print_values(t_list *stack);
void	k_sort(t_list *stack_a, t_list *stack_b);
//Swaps
void	sa(t_list **list);
void	sb(t_list **list);
void	ss(t_list **list1, t_list **list2);
//Pushes
void	pa(t_list **stacka, t_list **stackb);
void	pb(t_list **stacka, t_list **stackb);
//Rotates
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lista, t_list **listb);
//Reverse Rotates
void	rra(t_list **lista);
void	rrb(t_list **listb);
void	rrr(t_list **lista, t_list **listb);

#endif