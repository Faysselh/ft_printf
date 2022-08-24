/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:55:08 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 12:25:16 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_basep(unsigned long long int nbr, char *base)
{
	unsigned long long int	n;
	char					*str;
	int						i;
	int						len;

	if (nbr == 0)
		return (ft_strdup("0"));
	n = nbr;
	len = 0;
	i = 0;
	while (n != 0 && (++len) > -1)
		n /= 16;
	str = malloc(sizeof(char) * (len + 1));
	while (nbr != 0)
	{
		str[len - 1 - i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned long long	n;
	char				*str;
	int					i;
	int					len;

	if (nbr == 0)
		return (ft_strdup("0"));
	n = (unsigned long long)nbr;
	len = 0;
	i = 0;
	while (n != 0 && (++len) > -1)
		n /= 16;
	str = malloc(sizeof(char) * (len + 1));
	while (nbr != 0)
	{
		str[len - 1 - i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	ft_accintutil(t_stock *flags, int i, int n, int count)
{
	if (flags->number < 0)
		i++;
	while (i < n)
	{
		ft_putchar(flags, ' ');
		i++;
	}
	i = count;
	if (flags->number < 0)
		ft_putchar(flags, '-');
	while (i < flags->accuracy)
	{
		ft_putchar(flags, '0');
		i++;
	}
	ft_putnbr(flags, check_w(flags->number));
}

void	ft_intmax(t_stock *flags)
{
	ft_putchar(flags, '-');
	flags->number = flags->number * (-1);
	if (flags->number == -2147483648)
	{
		ft_putchar(flags, '2');
		flags->number = 147483648;
	}
}
