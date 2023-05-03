/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:43:15 by apanikov          #+#    #+#             */
/*   Updated: 2023/05/03 16:43:22 by apanikov         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int					pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_string(pid, argv[2]);
	}
	return (0);
}
