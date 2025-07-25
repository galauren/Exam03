/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:34:25 by galauren          #+#    #+#             */
/*   Updated: 2025/07/25 14:46:13 by galauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void permutation(char *str, char *res, int res_index, int max_index, char *tab)
{
	if (res_index == max_index)
	{
		printf("%s\n", res);
		return ;
	}
	int i = 0;
	while (i < max_index)
	{
		if (tab[i] == 0)
		{
			res[res_index] = str[i];
			tab[i] = 1;
			permutation(str, res, res_index + 1, max_index, tab);
			tab[i] = 0;
		}
		++i;
	}
}

int  main(int ac, char **av)
{
	char	*res;
	char	*tab;
	int		i;

	if (ac != 2) 
		return (-1);
	i = 0;
	while (av[1][i])
		++i;
	res = calloc(sizeof(char), (i + 1));
	tab = calloc(sizeof(char), (i + 1));
	res[i] = '\0';
	permutation(av[1], res, 0, i, tab);
	return (0);
}
