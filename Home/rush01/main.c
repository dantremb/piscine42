#include <unistd.h>
void	ft_putchar(char c)
	{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
	{
	int i = 0;
	while(str[i] != '\0')
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

void ft_print_board(int board[6][6])
{
	int row;
	int col;

	row = 0;
	while (row < 6)
	{
		col = 0;
		while (col < 6)
		{
			ft_putnbr(board[row][col]);
			ft_putchar(32);
			col++;
		}
	row++;
	ft_putchar('\n');
	}
}

int ft_in_row(int board[6][6], int number, int row)
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
int ft_in_col(int board[6][6], int number, int col)
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

int ft_compare_right(int board[6][6], int row, int col)
{
	int	i;
	int vision;

	i = 1;
	vision = 1;

		while (i < 4)
		{

			if (board[row][i] < board[row][i+1])
			{
			vision++;
			}
			i++;
		}
		if (vision == board[row][0])
		{
			return (1);
		}
		else if (col != 4)
		{
		  return (1);
		}
		else
		{
			return (0);
		}
}

int ft_is_valid(int board[6][6], int number, int row, int col)
{
	int vrow = ft_in_row(board, number, row);
	int vcol = ft_in_col(board, number, col);
	int vright = ft_compare_right(board, row, col);

	if ((vrow + vcol + vright) > 2)
	{
	 return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_solve(int board[6][6])
{
	int row;
	int col;
	int numberToTry;

	row = 1;
	numberToTry = 1;
	while (row <= 4)
	{
		col = 1;
		while(col <= 4)
		{
			if (board[row][col] == 0)
			{
				while (numberToTry <= 4)
				{
					if (ft_is_valid(board, numberToTry, row, col))
					{
						board[row][col] = numberToTry;
						ft_putstr("\n-------------\n");
						ft_print_board(board);
						if (ft_solve(board))
						{
							return (1);
						}
						else
						{
							board[row][col] = 0;
						}
					}
					numberToTry++;
				}
			}
		col++;
		}
	row++;
	}
	return (0);
}

int main(void)
{
	int board[6][6] = {
	{0, 2, 1, 3, 2, 0},
	{2, 0, 0, 0, 0, 3},
	{3, 0, 0, 0, 0, 1},
	{3, 0, 0, 0, 0, 2},
	{1, 0, 0, 0, 0, 2},
	{0, 1, 3, 2, 2, 0},
	};

	ft_print_board(board);
	if (ft_solve(board))
	{
		ft_putstr("\n R�solu !!! \n");
	}
	else
	{
		ft_putstr("\n Impossible! \n");
	}
	ft_print_board(board);
	return (0);
  }
