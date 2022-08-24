/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:56:41 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/16 01:44:45 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_w(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i = n;
		n = -i;
	}
	return (n);
}

void	ft_makestr(t_stock *flags, va_list arg)
{
	if (flags->type == 'c' || flags->type == '%')
		ft_printc(flags, arg);
	if (flags->type == 'd' || flags->type == 'i')
		ft_printint(flags, arg);
	if (flags->type == 'u')
		ft_printu(flags, arg);
	if (flags->type == 's')
		ft_printstr(flags, arg);
	if (flags->type == 'x')
		ft_printx(flags, arg);
	if (flags->type == 'X')
		ft_print_x(flags, arg);
	if (flags->type == 'p')
		ft_printp(flags, arg);
}
