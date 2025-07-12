/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:08:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/05/26 16:47:47 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUBSIZE 2

typedef struct s_link	t_link;
struct	s_link
{
	struct s_link	*previous;
	int				content;
	unsigned int	index;
	int				rotate_a;
	int				rotate_b;
	int				moves;
	struct s_link	*next;
};

// Stack utility functions

void			fill_stack(char **argv, t_link **stack);
int				freestack(t_link **stack);
void			add_to_top(t_link **stack, t_link *new);
void			add_to_bottom(t_link **stack, t_link *new);
int				get_stack_size(t_link **stack);

// Sort utility functions

int				get_average_index(t_link **stack, int size);
int				check_sorted(t_link **stack, int size);
unsigned int	get_lowest_index(t_link **stack);
unsigned int	get_highest_index(t_link **stack);

// Input error checking

int				input_error_check(int argc, char **argv);

// Rotate functions

void			ra(t_link **stack_a);
void			rb(t_link **stack_b);
void			rr(t_link **stack_a, t_link **stack_b);
void			rra(t_link **stack_a);
void			rrb(t_link **stack_b);
void			rrr(t_link **stack_a, t_link **stack_b);

// Push functions

void			push(t_link **stack_1, t_link **stack_2);
void			pa(t_link **stack_a, t_link **stack_b);
void			pb(t_link **stack_a, t_link **stack_b);

// Swap functions

void			sa(t_link **stack_a);
void			sb(t_link **stack_b);
void			ss(t_link **tack_a, t_link **stack_b);

// Sort functions

void			small_sort(t_link **stack_a, t_link **stack_b, int size);
void			hybrid_sort(t_link **stack_a, t_link **stack_b, int size);
void			sort_indexes(t_link **copy_a, t_link **copy_b, int argc);
void			update_indexes(t_link **stack_a, t_link **copy_a, int size);

// Hybrid sort funtions

void			set_right(t_link **stack_a, int size);
int				move_count_a(t_link **stack_a, t_link *link, unsigned int size);
void			calc_moves(t_link *link);
void			update_move_count(t_link **stack_a, t_link **stack_b);
void			do_best_moves(t_link **stack_a, t_link **stack_b);

#endif //PUSH_SWAP_H
