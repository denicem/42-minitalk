/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:51:50 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/09 21:35:18 by dmontema         ###   ########.fr       */
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

void dec_to_bin(int val)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if ((128 & (val<<i)))
			write (1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
	printf("\n");
}

int main(void)
{
	dec_to_bin('0');
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
