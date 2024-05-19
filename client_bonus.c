#include "minitalk.h"

void	send_message(int server, char * message)
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
			usleep(255);
		}
		i++;
	}
}

void	confirm_message(int signal)
{
	if (signal == SIGUSR1)
		printf("message acknowledged\n");
}

int	main(int argc, char *argv[])
{
	int	server;
	char	*message;
	struct sigaction	sa;	

	if (check_arg(argc, argv))
		return (-1);
	sa.sa_handler = &confirm_message;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	server = ft_atoi(argv[1]);
	message = argv[2];
	send_message(server, message);
	return (0);
}
