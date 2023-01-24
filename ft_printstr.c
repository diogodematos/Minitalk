/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:32:37 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/12/09 11:32:39 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	int	i;
	int	len;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_printchar(str[i]);
		i++;
	}
	return (len);
}
