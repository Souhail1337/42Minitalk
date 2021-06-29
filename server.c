/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:32:56 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/06/13 18:36:56 by sel-fcht         ###   ########.fr       */
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

void	receive_text(int sig)
{
	if (sig == SIGUSR2)
		g_mini.c |= 1 << g_mini.position_bit;
	g_mini.position_bit++;
	if (g_mini.position_bit == 8)
	{
		g_mini.position_bit = 0;
		if (!g_mini.c)
			ft_putchar('\n');
		else
			ft_putchar(g_mini.c);
		g_mini.c = 0;
	}
}

int	main(int ac, char **av)
{
	if (av[1])
	{
		ft_putstr("USAGE : ./server ");
		exit(0);
	}
	if (ac == 1)
	{
		g_mini.c = 0;
		g_mini.position_bit = 0;
		ft_putnbr(getpid());
		ft_putchar('\n');
		signal(SIGUSR1, receive_text);
		signal(SIGUSR2, receive_text);
		while (1)
			pause();
	}
	else
	{
		ft_putstr("USAGE : ./server");
		exit(0);
	}
	return (0);
}
