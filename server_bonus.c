/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:27:47 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/12 19:06:57 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigint(int sig)
{
	if (sig == SIGUSR1)
		printf("Signal 1 received!\n");
	else if (sig == SIGUSR2)
		printf("Signal 2 received!\n");
}

// void dec_to_bin(int val)
// {
// 	int i;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		if ((128 & (val<<i)))
// 			write (1, "1", 1);
// 		else
// 			write(1, "0", 1);
// 		i++;
// 	}
// 	printf("\n");
// }

int main(void)
{
	// dec_to_bin('0');
	int pid = getpid();
	printf("PID: %d\n", pid);

	struct sigaction sa;
	sa.sa_handler= &handle_sigint;
	// sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}