/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 13:12:20 by dritsema      #+#    #+#                 */
/*   Updated: 2022/06/10 13:08:14 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static int	push_swap_convert(char *str, int *n)
{
	int	mins;
	int	prev;

	*n = 0;
	prev = 0;
	mins = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-')
		mins = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = *n;
		*n = *n * 10 + ((*str - 48) * mins);
		if ((*n < prev && prev > 0) || (prev < 0 && *n > prev))
			return (0);
		str++;
	}
	return (1);
}

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	*nums;
	int	ret;

	i = 0;
	ret = 0;
	nums = malloc(sizeof(int) * (argc));
	while (argv[i] && ret != 1)
	{
		if (!push_swap_convert(argv[i], &nums[i]))
			ret = 1;
		j = 0;
		while (j < i && ret != 1)
		{
			if (nums[j] == nums[i])
				ret = 1;
			else
				j++;
		}
		i++;
	}
	free(nums);
	return (ret);
}

static int	check_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (j == 1 && argv[i][j] == 0)
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_error_check(int argc, char **argv)
{
	if (check_digits(argv) || check_duplicates(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
