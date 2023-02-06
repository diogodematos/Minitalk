/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:27:03 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/02/02 17:27:29 by dcarrilh         ###   ########.fr       */
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
