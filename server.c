/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:12:40 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/01/23 18:09:51 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rcvmsg(int sig)
{
	static int	c;
	static int	bit;

	if (sig == SIGUSR1)
	{
		c += 1 << (7 - bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
		return (ft_printf("Try again, because some error occured"));
	pid = getpid();
	ft_printf("My pid is: %d\n", pid);
	signal(SIGUSR1, rcvmsg);
	signal(SIGUSR2, rcvmsg);
	while (1)
		pause();
	return (0);
}
