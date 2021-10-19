/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:54:30 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/19 19:42:32 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*write_arg(char c, va_list **ap, int **len, t_flag *flag)
{
	if ((flag)->var_width)
		((flag)->digit) = va_arg(**ap, int);
	if ((flag)->var_pres)
		((flag)->pres) = va_arg(**ap, int);
	else if (c == 's')
		write_s((va_arg(**ap, char *)), &flag, &len);
	else if (c == 'c')
		return (write_char(va_arg(**ap, int), &flag, &len));
	else if ((c == 'i') || (c == 'd'))
		write_di(va_arg(**ap, int), &flag, &len);
	else if (c == 'u')
		write_u(va_arg(**ap, unsigned int), &flag, &len);
	else if ((c == 'x') || (c == 'X'))
		write_x(va_arg(**ap, unsigned int), &flag, &len, c);
	else if (c == 'p')
		write_p(((unsigned long)va_arg(**ap, void *)), &flag, &len);
	else
		return (write_char(c, &flag, &len));
	return (0);
}

int	go_print(const char *s, int i, int *len, va_list *ap)
{
	char	*arg_type;
	char	*pos_flag;
	int		j;
	t_flag	f;
	char	flag[16];

	ft_bzero(flag, 16);
	arg_type = "cspdiuxX";
	pos_flag = "-+ #.*0123456789\n";
	j = 0;
	while (ft_strchr(pos_flag, s[j]))
		j++;
	arg_type = (char *)&s[j];
	i = i + j + 1;
	flag[j] = '\0';
	while (j--)
		flag[j] = s[j];
	set_flags(flag, &f);
	write_arg(*arg_type, &ap, &len, &f);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			len;
	va_list		ap;

	len = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == '%')
			i = go_print(&s[i + 1], i + 1, &len, &ap);
		if (s[i] != '\0')
			len += write(1, &s[i++], 1);
	}
	va_end(ap);
	return (len);
}
