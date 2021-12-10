/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:39:11 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/10 18:52:29 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sendChar(char *str, int pid)
{
	while (*str)
	{
		if (*str == '0')
			kill(pid, SIGUSR1);
		else if (*str == '1')
			kill(pid, SIGUSR2);
		str++;
		usleep(100);
	}
}

void dec_to_bin(int val, int pid)
{
	char *res;
	int i;

	i = 0;
	res = ft_calloc(8 + 1, sizeof(char));
	while (i < 8)
	{
		if ((128 & (val<<i)))
			res[i] = '1';
		else
			res[i] = '0';
		i++;
	}
	sendChar(res, pid);
	free(res);
}

void str_to_char(char *input, int pid)
{
	while (*input)
	{
		dec_to_bin(*input, pid);
		input++;
	}
}

int main(int argc, char **argv)
{
	int pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str_to_char(argv[2], pid);
		printf("finished\n");
	}
	return (0);
}
