/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:00:34 by rmakoni           #+#    #+#             */
/*   Updated: 2024/12/17 14:22:41 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Checks for duplicate values in stack
int	has_duplicates(t_list *stack)
{
	t_list	*checker;
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if ((int)(intptr_t)current->content == (int)(intptr_t)checker->content)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	*create_sorted_array(t_list *stack, int size)
{
	int	*sorted_array;
	int	i;

	sorted_array = malloc(size * sizeof(int));
	i = 0;
	if (!sorted_array)
		return (NULL);
	while (stack && i < size)
	{
		sorted_array[i] = (int)(intptr_t)stack->content;
		stack = stack->next;
		i++;
	}
	return (sorted_array);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	temp;
	int	j;

	j = 0;
	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	normalise(t_list **stack)
{
	t_list	*current;
	int		*sorted_array;
	int		size;
	int		i;
	int		j;
	int		original_value;

	if (has_duplicates(*stack))
		exit(EXIT_FAILURE);
	size = ft_lstsize(*stack);
	sorted_array = create_sorted_array(*stack, size);
	if (!sorted_array)
		exit(EXIT_FAILURE);
	sort_array(sorted_array, size);
	current = *stack;
	i = 0;
	while (current && i < size)
	{
		original_value = (int)(intptr_t)current->content;
		j = 0;
		while (j < size)
		{
			if (sorted_array[j] == original_value)
			{
				current->content = (void *)(intptr_t)j;
				break ;
			}
			j++;
		}
		current = current->next;
		i++;
	}
	free(sorted_array);
}
