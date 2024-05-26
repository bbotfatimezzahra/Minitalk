/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:53:01 by fbbot             #+#    #+#             */
/*   Updated: 2024/05/26 12:05:09 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>

int		ft_isdigit(int c);
int		check_pid(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
int		check_arg(int argc, char *argv[]);

#endif
