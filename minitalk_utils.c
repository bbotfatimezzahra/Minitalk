/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:52:31 by fbbot             #+#    #+#             */
/*   Updated: 2024/05/27 19:21:11 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	lnb;

	if (fd < 0)
		return ;
	lnb = n;
	if (lnb < 0)
	{
		ft_putchar_fd('-', fd);
		lnb *= -1;
	}
	if (lnb < 10)
		ft_putchar_fd(lnb + '0', fd);
	else
	{
		ft_putnbr_fd(lnb / 10, fd);
		ft_putnbr_fd(lnb % 10, fd);
	}
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Incorrect PID\n", 14);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			i;

	result = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i++] - '0');
		if (result > INT_MAX || result == 0)
			return (-1);
	}
	return (result);
}

int	check_arg(int argc, char *argv[])
{
	if (argc != 3 || !check_pid(argv[1]))
	{
		write(1, "%usage :\n \t./client (PID) (message)\n", 36);
		return (-1);
	}
	return (0);
}
