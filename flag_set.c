/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:31:51 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/19 19:41:26 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bchar(void *dest, char c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = dest;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
}

static void	reset_flags(t_flag **flag)
{
	(*flag)->minus = false;
	(*flag)->plus = false;
	(*flag)->wspace = false;
	(*flag)->hash = false;
	(*flag)->zero = false;
	(*flag)->digit = 0;
	(*flag)->pres = 0;
	(*flag)->var_width = false;
	(*flag)->var_pres = false;
	(*flag)->leading_space = 0;
	(*flag)->dot = false;
}

static void	set_pres_digit(char *s, t_flag **flag)
{
	int		i;
	char	*dot;

	i = 0;
	dot = ft_strrchr(s, '.');
	if (dot)
	{
		(*flag)->dot = true;
		while (ft_isdigit(dot[i + 1]))
			((*flag)->pres) = (((*flag)->pres) * 10) + (dot[++i] - 48);
	}
	i = 0;
	while ((s[i]) && (!(ft_isdigit(s[i]))) && (s[i] != '.'))
		i++;
	if ((s[i]) && (s[i] == '0'))
		(*flag)->zero = true;
	while ((s[i]) && (ft_isdigit(s[i])))
		((*flag)->digit) = (((*flag)->digit) * 10) + (s[i++] - '0');
}

void	set_flags(char *s, t_flag *flag)
{
	reset_flags(&flag);
	set_pres_digit(s, &flag);
	while (*s)
	{
		if (*s == '-')
			flag->minus = true;
		else if (*s == '+')
			flag->plus = true;
		else if (*s == '#')
			flag->hash = true;
		else if ((*s == '*') && (*(s - 1) == '.'))
			flag->var_pres = true;
		else if ((*s == '*') && (!(flag->digit)))
			flag->var_width = true;
		else if ((*s == '0') && (!(flag->digit)) && (!(flag->pres)))
			flag->zero = true;
		else if ((*s == ' ') || (flag->plus))
			flag->wspace = (!(flag->plus));
		s++;
	}
}
