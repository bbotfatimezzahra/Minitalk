/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:52:12 by fbbot             #+#    #+#             */
/*   Updated: 2024/05/21 06:57:56 by fbbot            ###   ########.fr       */
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
}

int	main(int argc, char *argv[])
{
	int		server;
	char	*message;

	if (check_arg(argc, argv))
		return (-1);
	server = ft_atoi(argv[1]);
	message = argv[2];
	send_message(server, message);
	return (0);
}
