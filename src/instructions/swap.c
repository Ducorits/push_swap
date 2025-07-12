/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:53 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/24 18:53:07 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*	Swap the first link with the second link in the stack.
	This is done by relinking all pointers of both links. */
void	swap(t_link **stack)
{
	t_link	*tmp;

	if (*stack != 0 && (*stack)->next != *stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next->previous = tmp;
		(*stack)->previous = tmp->previous;
		tmp->previous->next = *stack;
		tmp->previous = *stack;
		(*stack)->next = tmp;
	}
}

/*	The sa instruction from push swap.
	Takes the pointer to the first link of stack a. */
void	sa(t_link **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

/*	The sb instruction from push swap.
	Takes the pointer to the first link of stack b. */
void	sb(t_link **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

/*	The ss instruction from push swap.
	Takes the pointer to the first link of both stack a and stack b. */
void	ss(t_link **stack_a, t_link **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
