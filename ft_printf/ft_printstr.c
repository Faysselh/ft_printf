/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:33:21 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/20 18:10:36 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr2(t_stock *flags, char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (ft_strlen(str) >= check_w(flags->width))
		ft_putstr(flags, str);
	else if (ft_strlen(str) < check_w(flags->width))
	{
		n = check_w(flags->width) - ft_strlen(str);
		ft_putstr(flags, str);
		while (i < n)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
}

void	ft_printprec1(t_stock *flags, char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (check_w(flags->width) > flags->accuracy)
	{
		n = check_w(flags->width) - flags->accuracy;
		while (i < n)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
	i = 0;
	while (i < flags->accuracy)
		ft_putchar(flags, str[i++]);
}

void	ft_printprec2(t_stock *flags, char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < flags->accuracy)
		ft_putchar(flags, str[i++]);
	i = 0;
	if (check_w(flags->width) > flags->accuracy)
	{
		n = check_w(flags->width) - flags->accuracy;
		while (i < n)
		{
			ft_putchar(flags, ' ');
			i++;
		}
	}
}

void	ft_printprec(t_stock *flags, char *str)
{
	if (flags->accuracy >= ft_strlen(str) && flags->flag != '-')
		ft_printfstr(flags, str);
	if (flags->accuracy >= ft_strlen(str) && flags->flag == '-')
		ft_printstr2(flags, str);
	if (flags->accuracy < ft_strlen(str) && flags->flag != '-')
		ft_printprec1(flags, str);
	if (flags->accuracy < ft_strlen(str) && flags->flag == '-')
		ft_printprec2(flags, str);
}

void	ft_printstr(t_stock *flags, va_list arg)
{
	char	*str;
	int		has_malloc;

	has_malloc = 0;
	str = va_arg(arg, char *);
	if (str == NULL && (has_malloc = 1))
		str = ft_strdup("(null)");
	if (flags->width < 0)
		flags->flag = '-';
	if (flags->sizehere == 1 && flags->accuracy >= 0)
		ft_printprec(flags, str);
	else if (flags->flag != '-')
		ft_printfstr(flags, str);
	else if (flags->flag == '-')
		ft_printstr2(flags, str);
	if (has_malloc)
		free(str);
}
