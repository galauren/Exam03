/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:41:24 by galauren          #+#    #+#             */
/*   Updated: 2025/07/28 15:32:13 by galauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_recur_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_recur_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	print_board(int *board, int n)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= n + 1)
	{
		write(1, "\n", 1);
		x = -1;
		while (++x <= n + 1)
		{
			if ((y == 0 || y == n + 1) && (x == 0 || x == n + 1))
				write(1, "-", 1);
			else if (y == 0 || y == n + 1)
				write(1, "---", 3);
			else if (x == 0 || x == n + 1)
				write(1, "|", 1);
			else if (board[x - 1] == y - 1)
				write(1, " D ", 3);
			else
				write(1, " . ", 3);
		}
	}
	write(1, "\n", 1);
}

void	print_queens(int *board, int n)
{
	int		i;
	char	c;

	i = 0;
	write(1, "\n", 1);
	write(1, "                            ", ((n * 3 + 2) - (((n < 10) * n * 2) + ((n > 9) * ((n - 10) * 3 + 20)))) / 2);
	while (i < n)
	{
		if (board[i] >= 10)
		{
			ft_recur_putnbr(board[i]);
			write(1, " ", 1);
		}
		else
		{
			c = (char)board[i] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
		}
		i++;
	}
}


int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	is_safe(int *board, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (board[i] == -1)
			break ;
		if (y == board[i] || ft_abs(x - i) == ft_abs(y - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	n_queens(int *board, int n, int x)
{
	int	height;

	if (x >= n)
	{
		print_queens(board, n);
		print_board(board, n);
		return ;
	}
	height = -1;
	while (++height < n)
		if (is_safe(board, x, height))
		{
			board[x] = height;
			n_queens(board, n, x + 1);
			board[x] = -1;
		}
}

int main(int ac, char **av)
{
	int	board[100] = {-1};
	int	n;

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n > 50)
		return (2);
	n_queens(board, n, 0);
	return (0);
}
