/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:27:47 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/14 01:09:22 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void bin_to_dec(char *bin_str)
{
	int dec_val;
	char c;
	int help;

	help = 128; //TODO: think of a different name.
	dec_val = 0;
	while (*bin_str)
	{
		if (*bin_str == '1')
			dec_val += help;
		help /= 2;
		bin_str++;
	}
	c = dec_val;
	write(1, &c, 1);
	return ;
}

void create_bin_str(int sig, siginfo_t *info, void *context)
{
	static char bin_str[9];
	static int i;

	(void)	context;
	if (sig == SIGUSR1)
		bin_str[i++] = '0';
	else if (sig == SIGUSR2)
		bin_str[i++] = '1';
	if (i == 8)
	{
		bin_to_dec(bin_str);
		i = 0;
		*bin_str = 0;
	}
	usleep(500);
	kill(SIGUSR1, info->si_pid);
}

int main(void)
{
	int pid;
	struct sigaction sa;

	pid = getpid();
	sa.sa_sigaction = &create_bin_str;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}