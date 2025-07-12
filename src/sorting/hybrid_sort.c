/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hybrid_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 14:28:59 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/26 13:58:52 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Filter everything lower than the average.
	everything that matches the filter gets pushed to stack b. */
static int	filter_low(t_link **stack_a, t_link **stack_b, int size)
{
	int				i;
	int				count;
	unsigned int	average;

	i = 0;
	count = 0;
	average = get_average_index(stack_a, size);
	while (i < size)
	{
		if ((*stack_a)->index <= average)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
		i++;
	}
	return (count);
}

void	do_optimized_moves(t_link **stack_a, t_link **stack_b, t_link *to_move)
{
	while (to_move->rotate_a > 0 && to_move->rotate_b > 0)
	{
		rr(stack_a, stack_b);
		to_move->rotate_a--;
		to_move->rotate_b--;
	}
	while (to_move->rotate_a < 0 && to_move->rotate_b < 0)
	{
		rrr(stack_a, stack_b);
		to_move->rotate_a++;
		to_move->rotate_b++;
	}
}

void	do_moves(t_link **stack_a, t_link **stack_b, t_link *to_move)
{
	while (to_move->rotate_a != 0 || to_move->rotate_b != 0)
	{
		if (to_move->rotate_a > 0)
		{
			ra(stack_a);
			to_move->rotate_a--;
		}
		else if (to_move->rotate_a < 0)
		{
			rra(stack_a);
			to_move->rotate_a++;
		}
		if (to_move->rotate_b > 0)
		{
			rb(stack_b);
			to_move->rotate_b--;
		}
		else if (to_move->rotate_b < 0)
		{
			rrb(stack_b);
			to_move->rotate_b++;
		}
	}
}

void	do_best_moves(t_link **stack_a, t_link **stack_b)
{
	t_link	*tmp;
	t_link	*to_move;
	int		least_moves;

	if (*stack_b)
	{
		tmp = *stack_b;
		least_moves = tmp->moves;
		to_move = tmp;
		while (tmp)
		{
			if (tmp->moves < least_moves)
			{
				least_moves = tmp->moves;
				to_move = tmp;
			}
			tmp = tmp->next;
			if (tmp == *stack_b)
				tmp = 0;
		}
		do_optimized_moves(stack_a, stack_b, to_move);
		do_moves(stack_a, stack_b, to_move);
	}
}

/*	Move all indexes that are below the average index from stack a to stack b.
	Update average index and repeat untill stack a is empty.
	Sort stack a by moving back the link with the least moves needed to position
	correctly in stack a */
void	hybrid_sort(t_link **stack_a, t_link **stack_b, int size)
{
	int	filter_size;

	filter_size = size;
	while (*stack_a)
	{
		filter_size -= filter_low(stack_a, stack_b, filter_size);
	}
	while (*stack_b)
	{
		update_move_count(stack_a, stack_b);
		do_best_moves(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	set_right(stack_a, size);
}
