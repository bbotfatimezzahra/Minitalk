/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:52:51 by fbbot             #+#    #+#             */
/*   Updated: 2024/05/27 19:09:06 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_message(int signal, siginfo_t *client, void *context)
{
	static int				bit;
	static unsigned char	c;
	static int				pid;

	(void) context;
	if (pid && (pid != client->si_pid) && (bit > 0))
	{
		c = 0;
		bit = 0;
	}
	pid = client->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			if (kill(client->si_pid, SIGUSR2))
				write(1, "acknowledgement not sent\n", 25);
		}
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &print_message;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
