/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hybrid_sort_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 14:10:44 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/25 18:52:40 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_right(t_link **stack_a, int size)
{
	int		rotate;
	t_link	*tmp;

	rotate = 0;
	tmp = *stack_a;
	while (tmp->index != 0)
	{
		rotate++;
		tmp = tmp->next;
	}
	if (rotate > size / 2)
		rotate = (size - rotate) * -1;
	while (rotate != 0)
	{
		if (rotate > 0)
		{
			ra(stack_a);
			rotate--;
		}
		else if (rotate < 0)
		{
			rra(stack_a);
			rotate++;
		}
	}
}

int	move_count_a(t_link **stack_a, t_link *link, unsigned int size)
{
	t_link			*tmp;
	unsigned int	count;
	unsigned int	lowest;
	unsigned int	highest;

	count = 0;
	if (*stack_a)
	{
		lowest = get_lowest_index(stack_a);
		highest = get_highest_index(stack_a);
		tmp = *stack_a;
		while (count < size)
		{
			if ((link->index > tmp->previous->index && link->index < tmp->index)
				|| (link->index < lowest && tmp->index == lowest)
				|| (link->index > highest && tmp->previous->index == highest))
				break ;
			count++;
			tmp = tmp->next;
		}
		if (count > size / 2)
			count = (size - count) * -1;
	}
	return (count);
}

void	calc_moves(t_link *link)
{
	int	rot_a;
	int	rot_b;

	link->moves = 0;
	rot_a = link->rotate_a;
	rot_b = link->rotate_b;
	while (rot_a > 0 || rot_b > 0)
	{
		if (rot_a > 0)
			rot_a--;
		if (rot_b > 0)
			rot_b--;
		link->moves++;
	}
	while (rot_a < 0 || rot_b < 0)
	{
		if (rot_a < 0)
			rot_a++;
		if (rot_b < 0)
			rot_b++;
		link->moves++;
	}
}

void	update_move_count(t_link **stack_a, t_link **stack_b)
{
	int		size_a;
	int		size_b;
	int		move_a;
	int		move_b;
	t_link	*tmp;

	tmp = *stack_b;
	move_b = 0;
	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	while (tmp)
	{
		move_a = move_count_a(stack_a, tmp, size_a);
		tmp->rotate_a = move_a;
		if (move_b > size_b / 2)
			tmp->rotate_b = (size_b - move_b) * -1;
		else
			tmp->rotate_b = move_b;
		calc_moves(tmp);
		move_b++;
		tmp = tmp->next;
		if (tmp == *stack_b)
			tmp = 0;
	}
}
