/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:39:11 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/10 01:53:53 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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
	res = calloc(8 + 1, sizeof(char));
	while (i < 8)
	{
		if ((128 & (val<<i)))
			// write (1, "1", 1);
			res[i] = '1';
		else
			// write(1, "0", 1);
			res[i] = '0';
		i++;
	}
	sendChar(res, pid);
	// printf("%s\n", res);
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
	if (argc == 3)
	{
		int pid = atoi(argv[1]);
		str_to_char(argv[2], pid);
		printf("finished\n");
		// if (atoi(argv[2]) == 0)
		// 	kill(pid, SIGUSR1);
		// else
		// 	kill(pid, SIGUSR2);
		// usleep(500);
	}
}
