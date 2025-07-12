/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:58:57 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/25 18:54:25 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

void	add_to_bottom(t_link **stack, t_link *new)
{
	if (*stack == 0)
	{
		*stack = new;
		(*stack)->next = new;
		(*stack)->previous = new;
	}
	else
	{
		new->next = *stack;
		new->previous = (*stack)->previous;
		(*stack)->previous->next = new;
		(*stack)->previous = new;
	}
}

void	add_to_top(t_link **stack, t_link *new)
{
	add_to_bottom(stack, new);
	*stack = new;
}

void	fill_stack(char **argv, t_link **stack)
{
	int		i;
	t_link	*link;

	i = 1;
	while (argv[i])
	{
		link = malloc(sizeof(t_link));
		link->content = ft_atoi(argv[i]);
		link->index = i;
		add_to_bottom(stack, link);
		i++;
	}
}

int	freestack(t_link **stack)
{
	t_link	*tmp;

	if (*stack == 0)
	{
		return (1);
	}
	else
	{
		tmp = (*stack)->previous;
		while (*stack != tmp)
		{
			(*stack) = (*stack)->next;
			free((*stack)->previous);
		}
		free(*stack);
	}
	return (1);
}

int	get_stack_size(t_link **stack)
{
	t_link	*tmp;
	int		size;

	size = 0;
	if (*stack)
	{
		tmp = *stack;
		while (tmp)
		{
			tmp = tmp->next;
			size++;
			if (tmp == *stack)
				tmp = 0;
		}
	}
	return (size);
}
