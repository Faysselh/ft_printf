/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:31:43 by fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 13:10:26 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(t_stock *flags)
{
	if (flags->type == 'c' || flags->type == 's' || flags->type == 'p' || \
			flags->type == 'd' || flags->type == 'i' || \
			flags->type == 'u' || flags->type == 'x' || \
			flags->type == 'X' || flags->type == '%')
		return (1);
	else
		return (0);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list arg;
	t_stock *flags;

	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			flags = fill_struct(&str[i], arg);
			if (is_flag(flags) == 1)
				ft_makestr(flags, arg);
			i = i + flags->fsize + 1;
			ret += flags->lensize;
			free(flags);
			continue ;
		}
		write(1, &str[i++], 1);
		ret++;
	}
	va_end(arg);
	return (ret);
}
