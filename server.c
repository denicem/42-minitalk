/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:51:50 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/10 19:41:51 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void create_bin_str(int sig)
{
	static char bin_str[9];
	static int i;

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
}

int main(void)
{
	int pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1, &create_bin_str);
	signal(SIGUSR2, &create_bin_str);
	while (1)
		pause();
	return (0);
}
