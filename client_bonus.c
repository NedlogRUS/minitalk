/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:44:16 by apanikov          #+#    #+#             */
/*   Updated: 2023/05/03 16:44:20 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include "./libft/libft.h"

static void	ft_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		pause();
		usleep(100);
	}
}

static void	ft_string(int pid, char *str)
{
	char	c;

	while (*str)
	{
		c = *str++;
		ft_char(pid, c);
	}
}

static void	ft_act(int sig, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (sig == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	s_sigaction;

	if (argc == 3)
	{
		s_sigaction.sa_flags = SA_SIGINFO;
		s_sigaction.sa_sigaction = ft_act;
		sigemptyset(&s_sigaction.sa_mask);
		sigaction(SIGUSR1, &s_sigaction, 0);
		sigaction(SIGUSR2, &s_sigaction, 0);
		pid = ft_atoi(argv[1]);
		ft_string(pid, argv[2]);
	}
	return (0);
}
