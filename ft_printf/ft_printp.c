/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:10:36 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/19 11:16:59 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnegp(t_stock *flags, char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (ft_strlen(str) + 2 >= check_w(flags->width))
	{
		ft_putstr(flags, "0x");
		ft_putstr(flags, str);
	}
	else if (ft_strlen(str) + 2 < check_w(flags->width))
	{
		n = check_w(flags->width) - (ft_strlen(str) + 2);
		while (i < n)
		{
			ft_putchar(flags, ' ');
			i++;
		}
		ft_putstr(flags, "0x");
		ft_putstr(flags, str);
	}
}

void	ft_printp2(t_stock *flags, char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	ft_putstr(flags, "0x");
	if (ft_strlen(str) + 2 >= check_w(flags->width))
		ft_putstr(flags, str);
	else if (ft_strlen(str) + 2 < check_w(flags->width))
	{
		n = check_w(flags->width) - (ft_strlen(str) + 2);
		ft_putstr(flags, str);
		while (i < n)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
}

void	ft_printp(t_stock *flags, va_list arg)
{
	char *str;
	void *ptr;

	ptr = va_arg(arg, void *);
	flags->adr = (intptr_t)ptr;
	str = ft_putnbr_basep(flags->adr, "0123456789abcdef");
	if (flags->width < 0)
		flags->flag = '-';
	if (flags->flag != '-')
		ft_printnegp(flags, str);
	if (flags->flag == '-')
		ft_printp2(flags, str);
	free(str);
}
