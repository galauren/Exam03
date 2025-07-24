/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:40:55 by galauren          #+#    #+#             */
/*   Updated: 2025/07/25 00:47:37 by galauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	recursive_identify_parenthesis(char *str, int index)
{
	int balance;

	if (!str[index])
		return (0);
	balance = recursive_identify_parenthesis(str, index + 1);
	if (str[index] == ')')
		return (balance + 1);
	else if (str[index] == '(')
	{
		if (balance == 0)
			str[index] = ' ';
		else
			return (balance - 1);
	}
	return (balance);
}

void	rip(char *str)
{
	recursive_identify_parenthesis(str, 0);
	puts(str);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	rip(av[1]);
}
