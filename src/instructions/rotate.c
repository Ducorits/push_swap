/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 19:25:12 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/10 15:18:31 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotate(t_link **stack)
{
	if (*stack != 0)
		*stack = (*stack)->next;
}

void	rotate_both(t_link **stack_1, t_link **stack_2)
{
	if (*stack_1 != 0)
		*stack_1 = (*stack_1)->next;
	if (*stack_2 != 0)
		*stack_2 = (*stack_2)->next;
}

void	ra(t_link **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_link **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_link **stack_a, t_link **stack_b)
{
	rotate_both(stack_a, stack_b);
	write(1, "rr\n", 3);
}
