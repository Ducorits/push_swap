/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 14:34:01 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/24 14:04:41 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_indexes(t_link **stack_a, t_link **copy_a, int size)
{
	t_link	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (i < size)
	{
		while (tmp->content != (*copy_a)->content)
		{
			tmp = tmp->next;
		}
		tmp->index = (*copy_a)->index;
		*copy_a = (*copy_a)->next;
		i++;
	}
}

void	push_lowest(t_link **copy_a, t_link **copy_b, t_link *lowest)
{
	while (*copy_a != lowest)
	{
		*copy_a = (*copy_a)->next;
	}
	push(copy_a, copy_b);
}

void	empty_to_stack(t_link **a, t_link **b, int size)
{
	int	i;

	i = size - 1;
	while (*a)
	{
		(*a)->index = i;
		push(a, b);
		i--;
	}
}

void	sort_indexes(t_link **copy_a, t_link **copy_b, int size)
{
	t_link	*tmp;
	t_link	*lowest;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0 + i;
		tmp = *copy_a;
		lowest = *copy_a;
		while (j < size)
		{
			if (tmp->content < lowest->content)
			{
				lowest = tmp;
			}
			tmp = tmp->next;
			j++;
		}
		push_lowest(copy_a, copy_b, lowest);
		i++;
	}
	empty_to_stack(copy_b, copy_a, size);
}
