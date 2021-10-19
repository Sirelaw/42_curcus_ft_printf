/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writep_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 03:55:44 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/19 19:47:43 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*write_p(unsigned long num, t_flag **flag, int ***len)
{
	char	*ns;
	int		x;

	x = 0;
	ns = ft_ulxtoa(num);
	if (!ns)
		return (NULL);
	if ((*flag)->pres)
		format_presnum(&ns, (*flag)->pres);
	format_hash(&ns, 'x');
	if ((*flag)->digit)
		format_width(&ns, (*flag)->digit);
	if (((*flag)->zero) && (!((*flag)->minus)) && (!((*flag)->pres)))
		format_zero(&ns, 'x');
	(((*flag)->minus) && format_minus(&ns, 0));
	(***len) += write(1, ns, ft_strlen(ns));
	free(ns);
	return (0);
}

int	return_sign(char **s, int num, int plus)
{
	char	*ns;
	char	*temp;
	char	sign;
	int		len;

	if (num >= 0)
		sign = '+';
	else
		sign = '-';
	if ((num < 0) || plus)
	{
		len = ft_strlen(*s);
		temp = *s;
		ns = malloc(len + 2);
		ns[0] = sign;
		ns[len + 1] = '\0';
		while (len--)
			ns[len + 1] = (*s)[len];
		*s = ns;
		free(temp);
	}
	return (0);
}

void	remove_sign(char **s)
{
	int		i;

	i = 0;
	if (((*s)[0]) == '-')
	{
		while ((*s)[i++])
			(*s)[i - 1] = (*s)[i];
		(*s)[i] = '\0';
	}
}

void	*format_hash(char **s, char x)
{
	int		len;
	char	*new_s;
	char	*temp;
	int		i;

	i = 2;
	len = ft_strlen(*s);
	temp = *s;
	new_s = malloc(len + 3);
	if (!new_s)
		return (NULL);
	new_s[0] = '0';
	new_s[1] = x;
	new_s[len + 2] = '\0';
	while (*((*s)++))
		new_s[(i++)] = *((*s) - 1);
	*s = new_s;
	free(temp);
	return (0);
}
