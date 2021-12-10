/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:51:50 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/10 18:55:02 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bin_to_dec(char *bin)
{
	int res;
	int help;
	char c;

	help = 128;
	res = 0;
	while (*bin)
	{
		if (*bin == '1')
			res += help;
		help /= 2;
		bin++;
	}
	c = res;
	write(1, &c, 1);
	return ;
}
void createBin(int sig)
{
	static char res[9];
	static int i;

	if (sig == SIGUSR1)
		res[i++] = '0';
	else if (sig == SIGUSR2)
		res[i++] = '1';
	if (i == 8)
	{
		bin_to_dec(res);
		i = 0;
		*res = 0;
	}
}

int main(void)
{
	int pid = getpid();
	printf("PID: %d\n", pid); //TODO: add ft_printf
	signal(SIGUSR1, &createBin);
	signal(SIGUSR2, &createBin);
	while (1)
		pause();

	return (0);
}
