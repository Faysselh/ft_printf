/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:54:09 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 17:50:30 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_accu(t_stock *flags, int n, int count)
{
	int i;

	i = 0;
	n = check_w(flags->width) - flags->accuracy;
	if (count < flags->accuracy)
	{
		while (i < n)
		{
			ft_putchar(flags, ' ');
			i++;
		}
		i = count;
		while (i < flags->accuracy)
		{
			ft_putchar(flags, '0');
			i++;
		}
		ft_putnbru(flags, flags->numberu);
	}
	else if (check_w(flags->width) >= count && flags->width > 0)
		ft_accu1(flags, n, count);
	else if (count > flags->accuracy)
		ft_putnbru(flags, flags->numberu);
}

void	ft_accu1(t_stock *flags, int n, int count)
{
	int i;

	i = 0;
	n = check_w(flags->width) - count;
	while (i < n)
	{
		ft_putchar(flags, ' ');
		i++;
	}
	if (flags->numberu == 0 && flags->accuracy == 0)
		ft_putchar(flags, ' ');
	else
		ft_putnbru(flags, flags->numberu);
}

void	ft_accu2(t_stock *flags, int count)
{
	int i;

	i = 0;
	if (flags->numberu == 0)
		i--;
	if (count <= flags->accuracy)
	{
		while (i < flags->accuracy - count)
		{
			ft_putchar(flags, '0');
			i++;
		}
	}
	if (flags->numberu != 0)
		ft_putnbru(flags, flags->numberu);
}

void	ft_accun(t_stock *flags, int count)
{
	int i;

	i = 0;
	while (i < flags->accuracy - count)
	{
		ft_putchar(flags, '0');
		i++;
	}
	ft_putnbru(flags, flags->numberu);
	i = 0;
	while (i < check_w(flags->width) - flags->accuracy)
	{
		ft_putchar(flags, ' ');
		i++;
	}
}

void	ft_uneg(t_stock *flags, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar(flags, '0');
		i++;
	}
}
