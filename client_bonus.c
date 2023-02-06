/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:29:03 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/02/02 17:29:19 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sendmsg(int svr_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit & 1) == 1)
			kill(svr_pid, SIGUSR1);
		else
			kill(svr_pid, SIGUSR2);
		usleep(400);
		bit--;
	}
}

int	main(int argc, char **argv)
{	
	int	svr_pid;
	int	a;

	if (argc != 3)
		return (ft_printf("error"));
	svr_pid = ft_atoi(argv[1]);
	a = 0;
	while (argv[2][a])
	{
		sendmsg(svr_pid, argv[2][a]);
		a++;
	}
	sendmsg(svr_pid, '\n');
	ft_printf("message received\n");
	return (0);
}
