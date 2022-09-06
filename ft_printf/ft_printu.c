/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:51:26 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 19:21:08 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnegu(t_stock *flags)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	tmp = ft_utoa(flags->numberu);
	count = check_w(flags->width) - ft_strlen(tmp);
	free(tmp);
	if (flags->width < 0)
		ft_putnbru(flags, flags->numberu);
	if (check_w(flags->width) > 0 && flags->accuracy < 0 && flags->flag == '0')
		ft_uneg(flags, count);
	if (check_w(flags->width) > 0 && flags->accuracy < 0 && flags->flag != '0')
	{
		while (i < count)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
	if (flags->width >= 0)
		ft_putnbru(flags, flags->numberu);
}

void	ft_printposu(t_stock *flags)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	tmp = ft_utoa(flags->numberu);
	count = check_w(flags->width) - ft_strlen(tmp);
	free(tmp);
	ft_putnbru(flags, flags->numberu);
	while (i < count)
	{
		ft_putchar(flags, ' ');
		i++;
	}
}

void	ft_printaccu(t_stock *flags)
{
	int		count;
	int		n;
	char	*tmp;

	tmp = ft_utoa(flags->numberu);
	count = ft_strlen(tmp);
	free(tmp);
	n = count;
	if (flags->flag != '-' && check_w(flags->width) <= flags->accuracy)
		ft_accu2(flags, count);
	else if (flags->flag != '-' && flags->width > flags->accuracy)
		ft_accu(flags, n, count);
	else if (flags->flag == '-' || flags->width < 0)
		ft_printaccnu(flags, count);
}

void	ft_printaccnu(t_stock *flags, int count)
{
	int i;

	i = 0;
	if (flags->accuracy >= count)
		ft_accun(flags, count);
	if (flags->accuracy < count)
	{
		if (flags->numberu == 0)
			count--;
		if (flags->numberu != 0)
			ft_putnbru(flags, flags->numberu);
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

void	ft_printu(t_stock *flags, va_list arg)
{
	flags->numberu = va_arg(arg, unsigned int);
	if (flags->width < 0 && flags->flag == '0')
		flags->flag = '-';
	if (flags->sizehere == 1 && flags->accuracy >= 0)
		ft_printaccu(flags);
	else if (flags->flag != '-')
		ft_printnegu(flags);
	else if (flags->flag == '-')
		ft_printposu(flags);
}
