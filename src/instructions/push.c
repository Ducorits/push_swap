/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:47 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/05 18:54:27 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push(t_link **stack_1, t_link **stack_2)
{
	t_link	*tmp;

	if (*stack_1 != 0)
	{
		if ((*stack_1)->next != *stack_1)
		{
			tmp = *stack_1;
			(*stack_1)->previous->next = (*stack_1)->next;
			(*stack_1)->next->previous = (*stack_1)->previous;
			*stack_1 = (*stack_1)->next;
			add_to_top(stack_2, tmp);
		}
		else
		{
			add_to_top(stack_2, *stack_1);
			*stack_1 = 0;
		}
	}
}

void	pa(t_link **stack_a, t_link **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_link **stack_a, t_link **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
