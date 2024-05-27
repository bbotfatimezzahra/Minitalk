/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:52:23 by fbbot             #+#    #+#             */
/*   Updated: 2024/05/27 19:30:55 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(int server)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		kill(server, SIGUSR2);
		usleep(50);
		bit++;
	}
}

void	send_message(int server, char *message)
{
	int	bit;
	int	i;

	i = 0;
	while (message[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((message[i] >> bit) & 1)
			{
				if (kill(server, SIGUSR1))
					write(1, "bit 1 not sent\n", 13);
			}
			else
			{
				if (kill(server, SIGUSR2))
					write(1, "bit 0 not sent\n", 13);
			}
			bit--;
			usleep(150);
		}
		i++;
	}
	send_null(server);
}

void	confirm_message(int signal)
{
	write(1, "message acknowledged\n", 21);
}

int	main(int argc, char *argv[])
{
	int					server;
	char				*message;
	struct sigaction	sa;	

	if (check_arg(argc, argv))
		return (-1);
	sa.sa_handler = &confirm_message;
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	server = ft_atoi(argv[1]);
	if (server < 0)
		return (write(1, "error\n", 6));
	message = argv[2];
	send_message(server, message);
	return (0);
}
