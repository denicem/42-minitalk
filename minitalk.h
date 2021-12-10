/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:34 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/10 18:52:35 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "libft.h"

void createBin(int sig);
void bin_to_dec(char *bin);

void str_to_char(char *input, int pid);
void dec_to_bin(int val, int pid);
void sendChar(char *str, int pid);
