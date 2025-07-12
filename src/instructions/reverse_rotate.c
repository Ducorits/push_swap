/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 15:41:10 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/05 18:54:51 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rev_rotate(t_link **stack)
{
	if (*stack != 0)
		*stack = (*stack)->previous;
}

void	rev_rotate_both(t_link **stack_1, t_link **stack_2)
{
	if (*stack_1 != 0)
		*stack_1 = (*stack_1)->previous;
	if (*stack_2 != 0)
		*stack_2 = (*stack_2)->previous;
}

void	rra(t_link **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_link **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_link **stack_a, t_link **stack_b)
{
	rev_rotate_both(stack_a, stack_b);
	write(1, "rrr\n", 4);
}
