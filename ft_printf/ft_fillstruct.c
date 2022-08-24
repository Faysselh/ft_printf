/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 11:59:56 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 13:10:56 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stock		*end_sct(t_stock *flags, const char *str, int i, va_list arg)
{
	if (str[i] == '*')
	{
		flags->width = va_arg(arg, int);
		i++;
	}
	if (str[i] == '.')
	{
		flags->sizehere = 1;
		i++;
	}
	else
		flags->accuracy = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		flags->accuracy = flags->accuracy * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '*')
	{
		flags->accuracy = va_arg(arg, int);
		i++;
	}
	flags->type = str[i];
	flags->fsize = i;
	return (flags);
}

t_stock		*fill_struct(const char *str, va_list arg)
{
	int		i;
	t_stock *flags;

	i = 1;
	if (!(flags = malloc(sizeof(t_stock))))
		return (NULL);
	flags->flag = 1;
	flags->sizehere = -1;
	while (str[i] == '0' || str[i] == '-')
	{
		if (flags->flag != '-')
			flags->flag = str[i];
		i++;
	}
	flags->width = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		flags->width = flags->width * 10 + (str[i] - 48);
		i++;
	}
	flags->lensize = 0;
	flags->accuracy = 0;
	return (end_sct(flags, str, i, arg));
}
