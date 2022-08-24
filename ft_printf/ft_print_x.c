/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:51:26 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 17:21:00 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printneg_x(t_stock *flags)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	str = ft_putnbr_base(flags->unumber, "0123456789ABCDEF");
	count = check_w(flags->width) - ft_strlen(str);
	if (flags->width < 0)
		ft_putstr(flags, str);
	if (check_w(flags->width) > 0 && flags->accuracy < 0 && flags->flag == '0')
		ft_x_neg(flags, count);
	if (check_w(flags->width) > 0 && flags->accuracy < 0 && flags->flag != '0')
	{
		while (i < count)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
	if (flags->width >= 0)
		ft_putstr(flags, str);
	free(str);
}

void	ft_printpos_x(t_stock *flags)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	str = ft_putnbr_base(flags->unumber, "0123456789ABCDEF");
	count = check_w(flags->width) - ft_strlen(str);
	ft_putstr(flags, str);
	free(str);
	while (i < count)
	{
		ft_putchar(flags, ' ');
		i++;
	}
}

void	ft_printacc_x(t_stock *flags)
{
	int		i;
	int		count;
	int		n;
	char	*str;

	i = 0;
	str = ft_putnbr_base(flags->unumber, "0123456789ABCDEF");
	count = ft_strlen(str);
	n = count;
	if (flags->flag != '-' && check_w(flags->width) <= flags->accuracy)
		ft_acc_x2(flags, count, str);
	else if (flags->flag != '-' && flags->width > flags->accuracy)
		ft_acc_x(flags, n, count, str);
	else if (flags->flag == '-' || flags->width < 0)
		ft_printaccn_x(flags, count, str);
	free(str);
}

void	ft_printaccn_x(t_stock *flags, int count, char *str)
{
	int i;

	i = 0;
	if (flags->accuracy >= count)
		ft_acc_xn(flags, count, str);
	if (flags->accuracy < count)
	{
		if (flags->unumber == 0)
			count--;
		if (flags->unumber != 0)
			ft_putstr(flags, str);
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

void	ft_print_x(t_stock *flags, va_list arg)
{
	flags->unumber = va_arg(arg, unsigned int);
	if (flags->width < 0 && flags->flag == '0')
		flags->flag = '-';
	if (flags->sizehere == 1 && flags->accuracy >= 0)
		ft_printacc_x(flags);
	else if (flags->flag != '-')
		ft_printneg_x(flags);
	else if (flags->flag == '-')
		ft_printpos_x(flags);
}
