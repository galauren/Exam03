/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:38:10 by galauren          #+#    #+#             */
/*   Updated: 2025/07/25 13:22:50 by galauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
void	print_set(int *set, int size)
{
	int	i = 0;

	if (i >= size)
	{
		printf("\n");
		return ;
	}
	while (i < size)
	{
		printf("%d ", set[i]);
		++i;
	}
	printf("\n");
}

int	calculate(int *set, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		res += set[i];
		++i;
	}
	return (res);
}

void	power_set(int n, int *set, int set_index, int *ret, int ret_index, int max_size)
{
	if (ret_index == max_size)
		return ;
	if (set_index == max_size)
	{
		if (calculate(ret, ret_index) == n)
			print_set(ret, ret_index);
		return ;
	}
	power_set(n, set, set_index + 1, ret, ret_index, max_size);
	ret[ret_index] = set[set_index];
	power_set(n, set, set_index + 1, ret, ret_index + 1, max_size);
}

int main(int ac, char **av)
{
	int	n;
	int	i;
	int	*set;
	int	*ret;

	if (ac < 2)
		return (2);
	av[ac] = NULL;
	if (!(set = malloc(sizeof(int) * (ac - 2))))
		return (1);
	if (!(ret = malloc(sizeof(int) * (ac - 2))))
		return (1);
	n = atoi(av[1]);
	i = 0;
	while (i < ac - 2 && av[i + 2])
	{
		set[i] = atoi(av[i + 2]);
		ret[i] = 0;
		++i;
	}
	power_set(n, set, 0, ret, 0, ac - 2);
	return (0);
}
