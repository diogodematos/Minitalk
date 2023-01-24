/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnmb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:28:45 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/12/12 13:28:48 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnmb(int n)
{
	int		count;
	long	l;

	count = 0;
	l = n;
	if (n < 0)
	{
		count += write (1, "-", 1);
		l = -l;
	}
	if (l < 10)
		count += ft_printchar(l + 48);
	if (l > 9)
	{
		count += ft_printnmb(l / 10);
		count += ft_printnmb(l % 10);
	}
	return (count);
}
