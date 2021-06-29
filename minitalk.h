/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 17:02:29 by sel-fcht          #+#    #+#             */
/*   Updated: 2021/06/13 18:34:57 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>

typedef struct s_data
{
	char		c;
	int			position_bit;
}				t_data;

t_data			g_mini;

int				send(int pid, char data);
long			ft_atoi(char *nbr);
void			ft_error(void);
void			receive_text(int sig);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			errorr_pid(void);
void			errorr_pid(void);
int				is_digit(char *str);
int				ft_isdigit(int c);
void			ft_putstr(char *str);

#endif