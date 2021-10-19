/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:49:32 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/18 02:31:42 by oipadeol         ###   ########.fr       */
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

char	*ft_uxtoa(unsigned int n, int x)
{
	unsigned int	numlen;
	char			*chardigits;
	char			*hex_digits[2];
	int				i;

	i = 0;
	hex_digits[0] = "0123456789abcdef";
	hex_digits[1] = "0123456789ABCDEF";
	if (n == 0)
		return (ft_strdup("0"));
	numlen = getnumlen(n);
	chardigits = (char *) malloc(numlen + 1);
	if (chardigits == NULL)
		return (NULL);
	chardigits[numlen--] = '\0';
	while (n > 0)
	{
		chardigits[numlen--] = hex_digits[x][n % 16];
		n = n / 16;
	}
	while (chardigits[numlen + 1])
		chardigits[i++] = chardigits[(numlen++) + 1];
	chardigits[i] = '\0';
	return (chardigits);
}
