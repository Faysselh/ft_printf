/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:12:48 by fayel-ha          #+#    #+#             */
/*   Updated: 2020/10/21 12:25:43 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stock
{
	int						width;
	int						accuracy;
	int						fsize;
	int						sizehere;
	int						number;
	unsigned int			unumber;
	unsigned int			numberu;
	unsigned long long int	adr;
	char					type;
	char					flag;
	int						lensize;
}				t_stock;

void			ft_putstr(t_stock *flags, char *str);
void			ft_putchar(t_stock *flags, char c);
void			ft_putnbr(t_stock *flags, int n);
void			ft_putnbru(t_stock *flags, unsigned int n);
char			*ft_putnbr_base(unsigned int nbr, char *base);
char			*ft_putnbr_basep(unsigned long long int nbr, char *base);
int				is_flag(t_stock *flags);
int				ft_printf(const char *str, ...);
void			ft_printc(t_stock *flags, va_list arg);
void			ft_flagneg(t_stock *flags, va_list arg);
void			ft_flagpos(t_stock *flags, va_list arg);
void			ft_makestr(t_stock *flags, va_list arg);
void			ft_printint(t_stock *flags, va_list arg);
void			ft_printneg(t_stock *flags, va_list arg);
void			ft_printpos(t_stock *flags, va_list arg);
void			ft_printacc(t_stock *flags, va_list arg);
void			ft_printaccn(t_stock *flags, int count);
void			ft_printu(t_stock *flags, va_list arg);
void			ft_printnegu(t_stock *flags);
void			ft_printposu(t_stock *flags);
void			ft_printaccu(t_stock *flags);
void			ft_printaccnu(t_stock *flags, int count);
void			ft_printu(t_stock *flags, va_list arg);
void			ft_printstr(t_stock *flags, va_list arg);
void			ft_printfstr(t_stock *flags, char *str);
void			ft_printstr2(t_stock *flags, char *str);
void			ft_printprec(t_stock *flags, char *str);
void			ft_printprec1(t_stock *flags, char *str);
void			ft_printprec2(t_stock *flags, char *str);
void			ft_accint(t_stock *flags, int n, int count);
void			ft_accintutil(t_stock *flags, int i, int n, int count);
void			ft_accint1(t_stock *flags, int n, int count);
void			ft_accint2(t_stock *flags, int count);
void			ft_accintn(t_stock *flags, int count);
void			ft_accu(t_stock *flags, int n, int count);
void			ft_accu1(t_stock *flags, int n, int count);
void			ft_accu2(t_stock *flags, int count);
void			ft_accun(t_stock *flags, int count);
void			ft_printx(t_stock *flags, va_list arg);
void			ft_printaccnx(t_stock *flags, int count, char *str);
void			ft_printaccx(t_stock *flags);
void			ft_printnegx(t_stock *flags);
void			ft_printposx(t_stock *flags);
void			ft_accx(t_stock *flags, int n, int count, char *str);
void			ft_accx1(t_stock *flags, int n, int count, char *str);
void			ft_accx2(t_stock *flags, int count, char *str);
void			ft_accxn(t_stock *flags, int count, char *str);
void			ft_print_x(t_stock *flags, va_list arg);
void			ft_printaccn_x(t_stock *flags, int count, char *str);
void			ft_printacc_x(t_stock *flags);
void			ft_printneg_x(t_stock *flags);
void			ft_printpos_x(t_stock *flags);
void			ft_acc_x(t_stock *flags, int n, int count, char *str);
void			ft_acc_x1(t_stock *flags, int n, int count, char *str);
void			ft_acc_x2(t_stock *flags, int count, char *str);
void			ft_acc_xn(t_stock *flags, int count, char *str);
void			ft_printp(t_stock *flags, va_list arg);
void			ft_printp2(t_stock *flags, char *str);
void			ft_printnegp(t_stock *flags, char *str);
void			ft_intneg(t_stock *flags, int count);
void			ft_xneg(t_stock *flags, int count);
void			ft_x_neg(t_stock *flags, int count);
void			ft_uneg(t_stock *flags, int count);
unsigned int	ft_size(unsigned int n);
char			*ft_itoa(t_stock *flags, int n);
char			*ft_utoa(unsigned int n);
int				ft_strlen(char *str);
int				check_w(int n);
char			*ft_strdup(char *s1);
void			ft_fneg(t_stock *flags);
void			ft_intmax(t_stock *flags);
t_stock			*end_sct(t_stock *flags, const char *str, int i, va_list arg);
t_stock			*fill_struct(const char *str, va_list arg);

#endif
