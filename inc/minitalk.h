/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:34 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/14 19:03:30 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define	MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# include "libft.h"
# include "ft_printf.h"

void	create_bin_str(int sig);
void	bin_to_dec(char *bin_str);

void	convert_n_send_msg(char *input, int pid);
void	dec_to_bin(int val, int pid);
void	send_msg(char *str, int pid);

#	endif