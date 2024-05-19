#include "minitalk.h"

void	print_message(int signal, siginfo_t *client, void *context)
{
	static int				bit;
	static unsigned char	c;

	(void) context;
	if (signal == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		kill(client->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	printf("hello there i am the server and this is my PID:%d\n", getpid());
	sa.sa_sigaction = &print_message;
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
