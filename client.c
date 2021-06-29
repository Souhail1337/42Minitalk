/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:42:31 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/06/13 18:35:46 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

long	ft_atoi(char *nbr)
{
	long	n;
	int		i;
	int		s;

	n = 0;
	i = 0;
	s = 1;
	if (*nbr == '-' && nbr++)
		s = -1;
	while (nbr[i] <= '9' && nbr[i] >= '0')
	{
		n = n * 10 + nbr[i++] - '0';
		if (i == 11)
			ft_error();
	}
	if (nbr[i] == '-' || !i)
		ft_error();
	if (n >= 2147483647)
		ft_error();
	return (n * s);
}

int	send(int pid, char data)
{
	int		i;
	int		bit;

	i = 0;
	while (i < 8)
	{
		bit = (data >> i) & 1;
		if (bit)
		{
			if (kill(pid, SIGUSR2) == -1)
				errorr_pid();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				errorr_pid();
		}
		usleep(150);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	c;

	c = 0;
	if (argc != 3)
		errorr_pid();
	if (is_digit(argv[1]))
		pid = (int)ft_atoi(argv[1]);
	else
		errorr_pid();
	i = 0;
	while (argv[2][i])
	{
		send(pid, argv[2][i]);
		i++;
	}
	if (send(pid, 0) == 1)
		ft_putstr("\033[0;32mMessage received to server\n");
	return (0);
}
