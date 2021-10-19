/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 05:20:33 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/19 18:08:35 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_zero(char **s, char c)
{
	int	i;

	i = 0;
	while ((*s)[i++] == ' ')
		(*s)[i - 1] = '0';
	if (((((*s)[i - 1] == '+') || ((*s)[i - 1] == '-'))) && (c == 'd') && (i - 1 != 0))
	{
		(*s)[0] = (*s)[i - 1];
		(*s)[i - 1] = '0';
	}
}

void	*format_width(char **s, int width)
{
	int		len;
	char	*new_s;
	char	*temp;

	len = ft_strlen(*s);
	if (width > len)
	{
		temp = *s;
		new_s = malloc(width + 1);
		if (!new_s)
			return (NULL);
		ft_bchar(new_s, ' ', (width - len));
		new_s[width] = '\0';
		while(*((*s)++))
			new_s[width - (len--)] = *((*s) - 1);
		*s = new_s;
		free(temp);
	}
	return (0);
}

void	format_pres(char **s, int pres)
{
	int	len;

	len = ft_strlen(*s);
	if (pres < len)
		(*s)[pres] = '\0';
}

void	*format_presnum(char **s, int pres)
{
	int		len;
	char	*new_s;
	char	*temp;

	len = ft_strlen(*s);
	if (pres > len)
	{
		temp = *s;
		new_s = malloc(pres + 1);
		if (!new_s)
			return (NULL);
		ft_bchar(new_s, '0', (pres - len));
		new_s[pres] = '\0';
		while(*((*s)++))
			new_s[pres - (len--)] = *((*s) - 1);
		*s = new_s;
		free(temp);
	}
	return (0);
}

 int	format_minus(char **s, int ls)
 {
	int	i;
	int	j;

	i = ls;
	j = ls;
	while ((*s)[i] == ' ')
		i++;
	if (i == j)
		return (0);
	while (((*s)[i]) && (i > 0))
	{
		(*s)[j++] = (*s)[i++];
		(*s)[i - 1] = ' ';
	}
	return (0);
}
