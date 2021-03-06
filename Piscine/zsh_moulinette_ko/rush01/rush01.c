/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:51:44 by dantremb          #+#    #+#             */
/*   Updated: 2022/03/21 00:32:37 by dantremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_solve(int **board);

void	ft_putchar(char c)
	{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
	{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	value;

	i = 0;
	neg = 1;
	value = 0;
	while (str[i] <= 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
	}
	while (str[++i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		value = (str[i] - 48) + (value * 10);
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (value * neg);
	}
	return (0);
}

int	ft_in_row(int **board, int number, int row)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (board[row][i] == number)
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}

int	ft_in_col(int **board, int number, int col)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (board[i][col] == number)
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}

int	ft_is_valid(int **board, int number, int row, int col)
{
	int	vrow;
	int	vcol;

	vrow = ft_in_row(board, number, row);
	vcol = ft_in_col(board, number, col);
	if ((vrow + vcol) > 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	**ft_init_board(int size)
{
	int		**board;
	int		row;
	int		col;

	row = 0;
	board = (malloc(sizeof(int) * size * size) + 1);
	while (row <= size)
	{
		col = 0;
		while (col <= size)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	return (board);
}

void	ft_print_board(int **board, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row <= size)
	{
		col = 0;
		while (col <= size)
		{
			ft_putnbr(board[row][col]);
			ft_putchar(' ');
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}

int	ft_try_number(int **board, int number, int row, int col)
{
	if (ft_is_valid(board, number, row, col))
	{
		board[row][col] = number;
		if (ft_solve(board))
		{
			return (1);
		}
		else
		{
			board[row][col] = 0;
		}
	}
	return (0);
}

int	ft_solve(int **board)
{
	int	row;
	int	col;
	int	number;

	row = 1;
	number = 1;
	while (row <= 5)
	{
		col = 0;
		while (col <= 5)
		{
			if (board[row][col] == 0)
			{
				while (number <= 4)
				{
					if (ft_try_number(board, number, row, col))
						return (1);
					number++;
				}
			}
		col++;
		}
	row++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		size;
	int		**board;

	size = ft_atoi(av[1]);
	board = ft_init_board(size);
	ft_print_board(board, size);
/*
	if (ft_solve(board))
	{
		ft_putstr("\n-------RESOLU-------\n");
	}
	else
	{
		ft_putstr("\n-----IMPOSSIBLE-----n");
	}
	ft_print_board(board);
*/
	return (0);
}
