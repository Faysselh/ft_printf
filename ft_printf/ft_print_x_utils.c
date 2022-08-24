/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:54:09 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 17:59:15 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_acc_x(t_stock *flags, int n, int count, char *str)
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
		ft_putstr(flags, str);
	}
	else if (check_w(flags->width) >= count && flags->width > 0)
		ft_acc_x1(flags, n, count, str);
	else if (count > flags->accuracy)
		ft_putstr(flags, str);
}

void	ft_acc_x1(t_stock *flags, int n, int count, char *str)
{
	int i;

	i = 0;
	n = check_w(flags->width) - count;
	while (i < n)
	{
		ft_putchar(flags, ' ');
		i++;
	}
	if (flags->unumber == 0 && flags->accuracy == 0)
		ft_putchar(flags, ' ');
	else
		ft_putstr(flags, str);
}

void	ft_acc_x2(t_stock *flags, int count, char *str)
{
	int i;

	i = 0;
	if (flags->unumber == 0)
		i--;
	if (count <= flags->accuracy)
	{
		while (i < flags->accuracy - count)
		{
			ft_putchar(flags, '0');
			i++;
		}
	}
	if (flags->unumber != 0)
		ft_putstr(flags, str);
}

void	ft_acc_xn(t_stock *flags, int count, char *str)
{
	int i;

	i = 0;
	while (i < flags->accuracy - count)
	{
		ft_putchar(flags, '0');
		i++;
	}
	ft_putstr(flags, str);
	i = 0;
	while (i < check_w(flags->width) - flags->accuracy)
	{
		ft_putchar(flags, ' ');
		i++;
	}
}

void	ft_x_neg(t_stock *flags, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar(flags, '0');
		i++;
	}
}
