#include "minitalk.h"

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
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

int	check_arg(int argc, char *argv[])
{
	if (argc != 3 || !check_pid(argv[1]))
	{
		printf("Incorrect format\n %%usage :\n \t./client (PID) (message)\n PID : Valid server pid.\n message : String to be sent if it contains white spaces please add double quotes.\n");
		return (-1);
	}
	return (0);
}
