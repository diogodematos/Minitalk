/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunmb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:57:04 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/12/12 14:57:06 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunmb(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_printchar(n + 48);
	if (n > 9)
	{
		count += ft_printunmb(n / 10);
		count += ft_printunmb(n % 10);
	}
	return (count);
}
