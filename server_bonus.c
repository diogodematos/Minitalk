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

static void	rcvmsg(int sig, siginfo_t *info, void *ucontext)
{
	static int	c;
	static int	bit;

	(void)ucontext;
	if (sig == SIGUSR1)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				pid;

	act.sa_sigaction = rcvmsg;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	(void)argv;
	if (argc != 1)
		return (ft_printf("Try again, because some error occured"));
	pid = getpid();
	ft_printf("My pid is: %d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
