/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:49:35 by fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/20 17:03:36 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putchar(t_stock *flags, char c)
{
	flags->lensize = flags->lensize + 1;
	write(1, &c, 1);
}

void			ft_putstr(t_stock *flags, char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(flags, str[i]);
		i++;
	}
}

void			ft_putnbr(t_stock *flags, int n)
{
	if (n == -2147483648)
	{
		ft_putstr(flags, "-2");
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar(flags, '-');
		n = n * (-1);
	}
	if (n > 9)
	{
		ft_putnbr(flags, n / 10);
		ft_putchar(flags, (n % 10) + 48);
	}
	else
		ft_putchar(flags, n + 48);
}

unsigned int	ft_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char			*ft_itoa(t_stock *flags, int n)
{
	unsigned int	nb;
	unsigned int	size;
	int				i;
	char			*str;

	flags->number = n;
	nb = (n < 0) ? (unsigned int)(n * -1) : (unsigned int)n;
	size = (n < 0) ? ft_size(nb) + 1 : ft_size(nb);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
		str[0] = '-';
	i = size - 1;
	str[size] = '\0';
	while (nb >= 10)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[i] = (nb % 10) + '0';
	return (str);
}
