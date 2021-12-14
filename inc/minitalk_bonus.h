/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:28:17 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/14 18:50:16 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "libft.h"

void create_bin_str(int sig, siginfo_t *info, void *context);
void bin_to_dec(char *bin_str, int pid);

void convert_n_send_msg(char *input, int pid);
void dec_to_bin(int val, int pid);
void send_msg(char *str, int pid);