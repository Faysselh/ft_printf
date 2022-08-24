/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:51:26 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 12:29:05 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printneg(t_stock *flags, va_list arg)
{
	int i;
	int count;

	i = 0;
	count = check_w(flags->width) - ft_strlen(ft_itoa(flags, va_arg(arg, int)));
	if (flags->number < 0 && (flags->width < 0 || flags->flag == '0'))
		ft_intmax(flags);
	if (flags->width < 0)
		ft_putnbr(flags, flags->number);
	if (check_w(flags->width) > 0 && flags->accuracy < 0 && flags->flag == '0')
		ft_intneg(flags, count);
	if (check_w(flags->width) > 0 && flags->accuracy < 0 && flags->flag != '0')
	{
		while (i < count)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
	if (flags->number < 0 && flags->width >= 0 && flags->flag != '0')
		ft_intmax(flags);
	if (flags->width >= 0)
		ft_putnbr(flags, flags->number);
}

void	ft_printpos(t_stock *flags, va_list arg)
{
	int i;
	int count;

	i = 0;
	count = check_w(flags->width) - ft_strlen(ft_itoa(flags, va_arg(arg, int)));
	ft_putnbr(flags, flags->number);
	while (i < count)
	{
		ft_putchar(flags, ' ');
		i++;
	}
}

void	ft_printacc(t_stock *flags, va_list arg)
{
	int i;
	int count;
	int n;

	i = 0;
	count = ft_strlen(ft_itoa(flags, va_arg(arg, int)));
	n = count;
	if (flags->number < 0)
		count--;
	if (flags->flag != '-' && check_w(flags->width) <= flags->accuracy)
		ft_accint2(flags, count);
	else if (flags->flag != '-' && flags->width > flags->accuracy)
		ft_accint(flags, n, count);
	else if (flags->flag == '-' || flags->width < 0)
		ft_printaccn(flags, count);
}

void	ft_printaccn(t_stock *flags, int count)
{
	int i;

	i = 0;
	if (flags->number < 0)
		count++;
	if (flags->number == 0)
		count--;
	if (flags->accuracy >= count)
		ft_accintn(flags, count);
	else if (flags->accuracy < count)
	{
		ft_putnbr(flags, flags->number);
		if (check_w(flags->width) > count)
		{
			while (i < check_w(flags->width) - count)
			{
				ft_putchar(flags, ' ');
				i++;
			}
		}
	}
}

void	ft_printint(t_stock *flags, va_list arg)
{
	if (flags->width < 0 && flags->flag == '0')
		flags->flag = '-';
	if (flags->sizehere == 1 && flags->accuracy >= 0)
		ft_printacc(flags, arg);
	else if (flags->flag != '-')
		ft_printneg(flags, arg);
	else if (flags->flag == '-')
		ft_printpos(flags, arg);
}
