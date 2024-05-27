/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:52:12 by fbbot             #+#    #+#             */
/*   Updated: 2024/05/27 19:07:56 by fbbot            ###   ########.fr       */
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
}

int	main(int argc, char *argv[])
{
	int		server;
	char	*message;

	if (check_arg(argc, argv))
		return (-1);
	server = ft_atoi(argv[1]);
	if (server == -1)
		return (write(1, "error\n", 6));
	message = argv[2];
	send_message(server, message);
	return (0);
}
