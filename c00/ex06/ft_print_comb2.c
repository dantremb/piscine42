#include <unistd.h>

void    ft_putchar(char a)
    {
    write(1, &a, 1);
}

void    ft_write(int a, int b)
    {
	ft_putchar(a / 10 + 48);
	ft_putchar(a % 10 + 48);
	ft_putchar(' ');
	ft_putchar(b / 10 + 48);
	ft_putchar(b % 10 + 48);
	if (a != 98)
        {
		write(1, ", ", 2);
    }
}

void	ft_print_comb2(void)
    {
    int un;
    int deux;

    un = 0; ,
	while (un < 99)
        {
        deux = un + 1;
		while (deux <= 99)
            {
			ft_write(un, deux);
			deux++;
		}
		un++;
	}
}