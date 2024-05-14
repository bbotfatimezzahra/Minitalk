#include <unistd.h>
#include <stdio.h>

void	handle_signal()
{
	struct	sigaction	sa;

	sa.sa_handler = &print_message;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main()
{
	printf("hello there i am the server and this is my PID:%d\n",getpid());
	while (1)
		handle_signal();
	return (0);
}
