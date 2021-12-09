/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:51:50 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/09 22:12:52 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

// void handle_sigint(int sig)
// {
// 	if (sig == 30)
// 		printf("Signal 1 received!\n", sig);
// 	else if (sig == 31)
// 		printf("Signal 2 received!\n", sig);
// }

int bin_to_dec(char *bin)
{
	int res;
	int help;

	help = 128;
	res = 0;
	while (*bin)
	{
		if (*bin == '1')
			res += help;
		help /= 2;
		bin++;
	}
	return (res);
}

void dec_to_bin(int val)
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
	res[i] = 0;

	printf("%s: %c\n", res, bin_to_dec(res));
}

void str_to_char(char *input)
{
	while (*input)
	{
		dec_to_bin(*input);
		input++;
	}
}

int main(void)
{
	str_to_char("Hallo 42Heilbronn!");
	// int pid = getpid();
	// struct sigaction sa;
	// printf("PID: %d\n", pid);
	// sa.sa_handler= &handle_sigint;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	// while (1)
	// {
	// 	pause();
	// }

	// printf("PID: %d\n", pid);
	// signal(SIGINT, handle_sigint);
	// while (1)
	// {
	// 	printf("waiting for signal ...\n");
	// 	sleep(1);
	// }
	return (0);
}
