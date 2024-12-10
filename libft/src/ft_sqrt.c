/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:08:02 by ryan              #+#    #+#             */
/*   Updated: 2024/12/10 13:44:44 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int	is_factor;

	if (nb < 0)
		return (0);
	is_factor = 1;
	while ((is_factor * is_factor <= nb) && is_factor <= 46340)
	{
		if ((is_factor * is_factor) == nb)
		{
			return (is_factor);
		}
		is_factor++;
	}
	if (is_factor * is_factor > nb)
	{
		return (is_factor - 1);
	}
	return (0);
}
