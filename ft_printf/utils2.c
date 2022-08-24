/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Fayel-ha <Fayel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:30:56 by Fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 17:32:49 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru(t_stock *flags, unsigned int n)
{
	if (n == 4147483647)
	{
		ft_putstr(flags, "41");
		n = 47483647;
	}
	if (n > 9)
	{
		ft_putnbru(flags, n / 10);
		ft_putchar(flags, (n % 10) + 48);
	}
	else
		ft_putchar(flags, n + 48);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	nb;
	unsigned int	size;
	int				i;
	char			*str;

	nb = (n < 0) ? (unsigned int)(n * -1) : (unsigned int)n;
	size = (n < 0) ? ft_size(nb) + 1 : ft_size(nb);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
		str[0] = '-';
	i = size - 1;
	str[size] = '\0';
	while (nb >= 10)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[i] = (nb % 10) + '0';
	return (str);
}

void	ft_printfstr(t_stock *flags, char *str)
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
		while (i < n)
		{
			ft_putchar(flags, ' ');
			i++;
		}
		ft_putstr(flags, str);
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(*dest) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
