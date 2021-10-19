/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:37:13 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/18 05:11:22 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	getnumlen(unsigned int n)
{
	unsigned int	numlen;

	numlen = 0;
	while (n > 0)
	{
		n = n / 10;
		numlen++;
	}
	return (numlen);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	numlen;
	char			*chardigits;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	numlen = getnumlen(n);
	chardigits = (char *) malloc(numlen + 1);
	if (chardigits == NULL)
		return (NULL);
	chardigits[numlen--] = '\0';
	while (n > 0)
	{
		chardigits[numlen--] = '0' + (n % 10);
		n = n / 10;
	}
	return (chardigits);
}
