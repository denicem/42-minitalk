/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:39:11 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/14 17:20:55 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	msg_confirmd(int sig)
{
	(void) sig;
	write(1, "Everything received!\n", 22);
}

void send_msg(char *msg, int pid)
{
	while (*msg)
	{
		if (*msg == '0')
			kill(pid, SIGUSR1);
		else if (*msg == '1')
			kill(pid, SIGUSR2);
		msg++;
		usleep(100);
	}
}

void dec_to_bin(int val, int pid)
{
	char *bin_str;
	int i;

	i = 0;
	bin_str = ft_calloc(8 + 1, sizeof(char));
	while (i < 8)
	{
		if ((128 & (val<<i)))
			bin_str[i] = '1';
		else
			bin_str[i] = '0';
		i++;
	}
	send_msg(bin_str, pid);
	free(bin_str);
}

void convert_n_send_msg(char *input, int pid)
{
	while (*input)
	{
		dec_to_bin(*input, pid);
		input++;
	}
	dec_to_bin(*input, pid);
}

static int	is_only_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			write(1, "The PID should only contain digits.\n", 37);
			return (0);
		}
		str++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		if (!is_only_digits(argv[1]))
			return (0);
		pid = ft_atoi(argv[1]);
		convert_n_send_msg(argv[2], pid);
		signal(SIGUSR1, &msg_confirmd);
		while (1)
			pause();
	}
	else
		write(1, "Only three arguments please.\n", 30);
	return (0);
}
