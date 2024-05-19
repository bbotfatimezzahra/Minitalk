#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>

int	ft_isdigit(int c);
int	check_pid(char *str);
int	ft_atoi(const char *str);
int	check_arg(int argc, char *argv[]);

#endif
