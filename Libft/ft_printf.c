/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:04:41 by dcarrilh          #+#    #+#             */
/*   Updated: 2022/12/07 15:12:18 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findtype(char c, va_list arg)
{
	if (c == 'c')
		return (ft_printchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_printstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_printpnt(va_arg(arg, void *)));
	if (c == 'd' || c == 'i')
		return (ft_printnmb(va_arg(arg, int)));
	if (c == 'u')
		return (ft_printunmb(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(arg, unsigned int), c));
	return (ft_printchar(c));
}

int	ft_printf(char const *tyle, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, tyle);
	i = 0;
	count = 0;
	while (tyle[i])
	{
		if (tyle[i] == '%' && ft_strchr("cspdiuxX%", tyle[i + 1]))
		{
			i++;
			count += ft_findtype(tyle[i], arg);
		}
		else
			count += ft_printchar(tyle[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

/*int		main(void)
{
	char	a;
	char	*str;
	char	*str2;
	char	percent;
	int		i;
	unsigned int	b;
	unsigned int	hex;

	a = 'a';
	str = "ugdygd";
	str2 = "10";
	i = -42174612;
	b = -42174612;
	hex = -10;
	percent = '%';

	// %c
	write(1, "ft_c\n", 5);
	printf("%d\n", printf("%c\n", a));
	printf("%d\n", ft_printf("%c\n", a));
	printf("\n\n");

	// %s
	write(1, "ft_s\n", 5);
	printf("%d\n", printf("%s\n", str));
	printf("%d\n", ft_printf("%s\n", str));
	printf("\n\n");

	// %p
	write(1, "ft_p\n", 5);
	printf("%d\n", printf("%p\n", str2));
	printf("%d\n", ft_printf("%p\n", str2));
	printf("\n\n");
	// %d
	write(1, "ft_d\n", 5);
	printf("%d\n", printf("%d\n", i));
	printf("%d\n", ft_printf("%d\n", i));
	printf("\n\n");

	// %i
	write(1, "ft_i\n", 5);
	printf("%d\n", printf("%i\n", i));
	printf("%d\n", ft_printf("%i\n", i));
	printf("\n\n");

	// %u
	write(1, "ft_u\n", 5);
	printf("%d\n", printf("%u\n", b));
	printf("%d\n", ft_printf("%u\n", b));
	printf("\n\n");

	// %x
	write(1, "ft_x\n", 5);
	printf("%d\n", printf("%x\n", hex));
	printf("%d\n", ft_printf("%x\n", hex));
	printf("\n\n");

	// %X
	write(1, "ft_X\n", 5);
	printf("%d\n", printf("%X\n", hex));
	printf("%d\n", ft_printf("%X\n", hex));
	printf("\n\n");

	// %%
	write(1, "ft_percent\n", 12);
	printf("%d\n", printf("%%\n"));
	printf("%d\n", ft_printf("%%\n", percent));
	printf("\n\n");
}*/
