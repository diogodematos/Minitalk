/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:13:09 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/12/12 16:13:11 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(unsigned long n, char c)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_printchar(n + 48);
	if (n > 9 && n < 16)
	{
		if (c == 'x')
			count += ft_printchar(n + 87);
		else
			count += ft_printchar(n + 55);
	}
	if (n > 15)
	{
		count += ft_printhex((n / 16), c);
		count += ft_printhex((n % 16), c);
	}
	return (count);
}
