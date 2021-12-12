/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:27:49 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/12 22:30:46 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handle_confirmation(int sig)
{
	printf("CONFIRMD!%d\n", sig);
	exit(0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int pid = atoi(argv[1]);
		if (atoi(argv[2]) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		// usleep(5000);
		signal(SIGUSR1, &handle_confirmation);
		struct sigaction sa;
		sa.sa_handler = &handle_confirmation;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL);
		while (1)
			pause();
	}
}