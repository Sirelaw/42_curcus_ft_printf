/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 06:59:22 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/19 19:46:12 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*write_x(unsigned int num, t_flag **flag, int ***len, char c)
{
	char	*ns;
	int		x;

	x = 0;
	if (c == 'X')
		x = 1;
	if ((num == 0) && ((*flag)->dot) && (!(*flag)->pres))
	{
		while ((((*flag)->digit)--) && (((*flag)->digit) > -1))
			(***len) += write(1, " ", 1);
		return (0);
	}
	ns = ft_uxtoa(num, x);
	if (!ns)
		return (NULL);
	((((*flag)->pres) > 0) && format_presnum(&ns, (*flag)->pres));
	((((*flag)->hash) > 0) && (num != 0) && format_hash(&ns, c));
	if ((*flag)->digit)
		format_width(&ns, (*flag)->digit);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pres)))
		format_zero(&ns, c);
	(((*flag)->minus) && format_minus(&ns, 0));
	(***len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

void	*write_u(unsigned int num, t_flag **flag, int ***len)
{
	char	*ns;

	if ((num == 0) && ((*flag)->dot) && (!(*flag)->pres))
	{
		while ((((*flag)->digit)--) && (((*flag)->digit) > -1))
			(***len) += write(1, " ", 1);
		return (0);
	}
	ns = ft_uitoa(num);
	if ((*flag)->pres)
		format_presnum(&ns, (*flag)->pres);
	if ((*flag)->digit)
		format_width(&ns, (*flag)->digit);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pres)))
		format_zero(&ns, 's');
	(((*flag)->minus) && format_minus(&ns, 0));
	(***len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

void	*write_di(int num, t_flag **flag, int ***len)
{
	char	*ns;

	if ((num == 0) && ((*flag)->dot) && (!(*flag)->pres))
	{
		while ((((*flag)->digit)--) && (((*flag)->digit) > -1))
			(***len) += write(1, " ", 1);
		return (0);
	}
	ns = ft_itoa(num);
	remove_sign(&ns);
	if (((*flag)->wspace) && (num >= 0))
	{
		(***len) += write(1, " ", 1);
		((*flag)->digit)--;
	}
	((((*flag)->pres) > 0) && format_presnum(&ns, (*flag)->pres));
	return_sign(&ns, num, (*flag)->plus);
	if ((*flag)->digit > 0)
		format_width(&ns, (*flag)->digit);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pres)))
		format_zero(&ns, 'd');
	(((*flag)->minus) && format_minus(&ns, 0));
	(***len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

void	*write_char(char c, t_flag **flag, int ***len)
{
	if (((*flag)->dot) && (!(*flag)->pres))
		return (0);
	if ((*flag)->minus)
	{
		(***len) += write(1, &c, 1);
		while ((((*flag)->digit)--) && (((*flag)->digit) > 0))
			(***len) += write(1, " ", 1);
	}
	else
	{
		while ((((*flag)->digit)--) && (((*flag)->digit) > 0))
			(***len) += write(1, " ", 1);
		(***len) += write(1, &c, 1);
	}
	return (0);
}

void	*write_s(char *s, t_flag **flag, int ***len)
{
	char	*ns;

	if (s == NULL)
		s = "(null)";
	ns = ft_strdup(s);
	if (!ns)
		return (NULL);
	while (s[(*flag)->leading_space] == ' ')
		((*flag)->leading_space)++;
	if (((*flag)->pres) || ((*flag)->dot))
		format_pres(&ns, (*flag)->pres);
	if ((*flag)->digit)
		format_width(&ns, (*flag)->digit);
	if ((*flag)->minus)
		format_minus(&ns, (*flag)->leading_space);
	if ((*flag)->zero)
		format_zero(&ns, 's');
	(***len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}
