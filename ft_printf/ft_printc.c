/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:29:16 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/20 16:53:56 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagneg(t_stock *flags, va_list arg)
{
	int i;

	i = 0;
	if (flags->width < 0 && flags->type == 'c')
		ft_putchar(flags, va_arg(arg, int));
	else if (flags->width < 0 && flags->type == '%')
		ft_putchar(flags, '%');
	if (check_w(flags->width) > 0 && flags->flag == '0')
		ft_fneg(flags);
	if (check_w(flags->width) > 0 && flags->flag != '0')
	{
		while (i < check_w(flags->width) - 1)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
	if (flags->width >= 0 && flags->type == '%')
		ft_putchar(flags, '%');
	else if (flags->width >= 0 && flags->type == 'c')
		ft_putchar(flags, va_arg(arg, int));
}

void	ft_fneg(t_stock *flags)
{
	int i;

	i = 0;
	while (i < check_w(flags->width) - 1)
	{
		ft_putchar(flags, '0');
		i++;
	}
}

void	ft_flagpos(t_stock *flags, va_list arg)
{
	int i;

	i = 0;
	if (flags->type == '%')
		ft_putchar(flags, '%');
	else
		ft_putchar(flags, va_arg(arg, int));
	while (i < check_w(flags->width) - 1)
	{
		ft_putchar(flags, ' ');
		i++;
	}
}

void	ft_printc(t_stock *flags, va_list arg)
{
	if (flags->flag != '-')
		ft_flagneg(flags, arg);
	else if (flags->flag == '-')
		ft_flagpos(flags, arg);
}
