/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:54:09 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 14:57:56 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_accint(t_stock *flags, int n, int count)
{
	int i;

	i = 0;
	n = check_w(flags->width) - flags->accuracy;
	if (count < flags->accuracy)
		ft_accintutil(flags, i, n, count);
	else if (check_w(flags->width) >= count && flags->width > 0)
		ft_accint1(flags, n, count);
	else if (flags->number == -2147483648)
		ft_putnbr(flags, -2147483648);
	else if (check_w(flags->width) == 1 && flags->accuracy == 0)
		ft_putnbr(flags, flags->number);
	else if (count > flags->accuracy)
		ft_putnbr(flags, flags->number);
}

void	ft_accint1(t_stock *flags, int n, int count)
{
	int i;

	i = 0;
	n = check_w(flags->width) - count;
	if (flags->number < 0)
		i++;
	while (i < n)
	{
		ft_putchar(flags, ' ');
		i++;
	}
	if (flags->number == 0 && flags->accuracy == 0)
		ft_putchar(flags, ' ');
	else
		ft_putnbr(flags, flags->number);
}

void	ft_accint2(t_stock *flags, int count)
{
	int i;

	i = 0;
	if (flags->number < 0 && flags->number != -2147483648)
		ft_putchar(flags, '-');
	if (flags->number == 0)
		i--;
	if (count <= flags->accuracy)
	{
		while (i < flags->accuracy - count)
		{
			ft_putchar(flags, '0');
			i++;
		}
	}
	if (flags->number != 0)
		ft_putnbr(flags, check_w(flags->number));
}

void	ft_accintn(t_stock *flags, int count)
{
	int i;

	i = 0;
	if (flags->number < 0)
	{
		ft_putchar(flags, '-');
		count--;
	}
	while (i < flags->accuracy - count)
	{
		ft_putchar(flags, '0');
		i++;
	}
	if (flags->number != 0)
		ft_putnbr(flags, check_w(flags->number));
	i = 0;
	if (flags->number < 0)
		i++;
	while (i < check_w(flags->width) - flags->accuracy)
	{
		ft_putchar(flags, ' ');
		i++;
	}
}

void	ft_intneg(t_stock *flags, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar(flags, '0');
		i++;
	}
}
