/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:52:23 by fbbot             #+#    #+#             */
/*   Updated: 2024/05/21 06:57:41 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
				kill(server, SIGUSR1);
			else
				kill(server, SIGUSR2);
			bit--;
			usleep(50);
		}
		i++;
	}
	while (bit < 7)
	{
		kill(server, SIGUSR2);
		usleep(50);
		bit++;
	}
}

void	confirm_message(int signal)
{
	printf("message acknowledged\n");
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
	message = argv[2];
	send_message(server, message);
	return (0);
}
