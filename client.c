#include <unistd.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("Incorrect PID\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = (result * 10) + (str[i++] - '0');
	return (result);
}

int	main(int argc, char *argv[])
{
	int	server;
	char	*message;

	if (argc != 3 || !check_pid(argv[1]))
	{
		printf("Incorrect format\n %%usage :\n \t./client (PID) (message)\n PID : Valid server pid.\n message : String to be sent if it contains white spaces please add double quotes.\n");
		return (-1);
	}
	server = ft_atoi(argv[1]);
	printf("hello server %d nice to meet you\n",server);
	kill(SIGUSR1, server);
	return (0);
}

