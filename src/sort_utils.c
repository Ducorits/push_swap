/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/11 21:41:48 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/24 18:20:00 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_average_index(t_link **stack, int size)
{
	t_link			*tmp;
	unsigned int	average;
	int				i;

	tmp = *stack;
	i = 0;
	average = 0;
	while (i < size)
	{
		average += tmp->index;
		tmp = tmp->next;
		i++;
	}
	average /= size;
	return (average);
}

unsigned int	get_lowest_index(t_link **stack)
{
	t_link			*tmp;
	unsigned int	lowest;

	tmp = *stack;
	lowest = tmp->index;
	while (tmp)
	{
		if (tmp->index < lowest)
			lowest = tmp->index;
		tmp = tmp->next;
		if (tmp == *stack)
			tmp = 0;
	}
	return (lowest);
}

unsigned int	get_highest_index(t_link **stack)
{
	t_link			*tmp;
	unsigned int	highest;

	tmp = *stack;
	highest = tmp->index;
	while (tmp)
	{
		if (tmp->index > highest)
			highest = tmp->index;
		tmp = tmp->next;
		if (tmp == *stack)
			tmp = 0;
	}
	return (highest);
}

/*	Goes through size number of links in stack.
	Returns 0 if link content is larger than the next link content.
	Else returns 1.
	*/
int	check_sorted(t_link **stack, int size)
{
	t_link	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	if (*stack != 0 && size == 0)
	{
		while (tmp != (*stack)->previous->previous)
		{
			if (tmp->content > tmp->next->content)
				return (0);
			tmp = tmp->next;
		}
	}
	else
	{
		while (i < size - 1)
		{
			if (tmp->content > tmp->next->content)
				return (0);
			tmp = tmp->next;
			i++;
		}
	}
	return (1);
}
