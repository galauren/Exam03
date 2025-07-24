/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:47:40 by galauren          #+#    #+#             */
/*   Updated: 2025/07/24 23:45:04 by galauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	recursive_identify_parenthesis(char **str, int open, int index, int open_index, int *over)
{
	if (!*(str)[index])
	{
		if (open && *over != 1)
			*(str)[open_index] = ' ';
		return ;
	}
	if (*(str)[index] == '(')
	{
		recursive_identify_parenthesis(str, 1, index + 1, index, --*over);
	}
	else if (*(str)[index] == ')')
	{
		if (open)
			recursive_identify_parenthesis(str, 1, index + 1, open_index, ++*over);	
		else
		{
			*(str)[index] = ' ';
			return ;
		}
			
	}
	else
		recursive_identify_parenthesis(str, open, index + 1, over);
}

void	rip(char *str)
{
	int	over;

	over = 1;
	recursive_identify_parenthesis(&str, 0, 0, 0, &over);
	puts(str);
}

int main()
{
	int i;
}
