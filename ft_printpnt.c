/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:23:42 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/12/12 17:24:08 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printpnt(void *str)
{
	int				count;
	unsigned long	*pnt;

	count = 0;
	pnt = (unsigned long *)str;
	if (!str)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		count += 2;
		count += ft_printhex((unsigned long)pnt, 'x');
	}
	return (count);
}
