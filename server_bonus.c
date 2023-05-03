/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:43:51 by apanikov          #+#    #+#             */
/*   Updated: 2023/05/03 16:43:55 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

static void	ft_act(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void) context;
	{
		i++;
		c <<= 1;
		if (sig == SIGUSR1)
			c |= 1;
		if (i == 8)
		{
			if (c == 0)
				kill(info->si_pid, SIGUSR2);
			else
				ft_putchar_fd(c, 1);
			i = 0;
			c = 0;
		}
		usleep(40);
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_act;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
