/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:51:50 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/10 01:32:57 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

// void handle_sigint(int sig)
// {
// 	if (sig == SIGUSR1)
// 		printf("Signal 1 received!\n");
// 	else if (sig == SIGUSR2)
// 		printf("Signal 2 received!\n");
// }

void bin_to_dec(char *bin)
{
	int res;
	int help;
	char c;

	help = 128;
	res = 0;
	// printf("res bf:%d\n", res);
	while (*bin)
	{
		if (*bin == '1')
			res += help;
		help /= 2;
		bin++;
	}
	c = res;
	// printf("OK\n");
	// printf("res af:%c\n", res);
	// printf("%c ", res);
	write(1, &c, 1);
	return ;
	// printf("%c", res);
}
void createBin(int sig)
{
	static char res[9];
	static int i;
	// printf("call, i=%d\n", i);

	if (sig == SIGUSR1)
		res[i++] = '0';
	else if (sig == SIGUSR2)
		res[i++] = '1';
	// printf("%s %d\n", res, i);
	if (i == 8)
	{
		// res[i] = 0;
		i = 0;
		bin_to_dec(res);
		*res = 0;
		// printf("vals after print: i=%d, res=%s", i, res);
	}
}

int main(void)
{
	// str_to_char("Hallo 42Heilbronn!");
	int pid = getpid();
	// struct sigaction sa;
	printf("PID: %d\n", pid);
	// sa.sa_handler= &handle_sigint;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	signal(SIGUSR1, &createBin);
	signal(SIGUSR2, &createBin);
	while (1)
	{
		pause();
	}

	// printf("PID: %d\n", pid);
	// signal(SIGINT, handle_sigint);
	// while (1)
	// {
	// 	printf("waiting for signal ...\n");
	// 	sleep(1);
	// }
	return (0);
}
