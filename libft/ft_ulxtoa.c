/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:49:32 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/18 12:18:37 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulxtoa(unsigned long n)
{
	char	*chardigits;
	char	*hex_digits;
	int		i;
	int		blksize;

	i = 0;
	blksize = 20;
	hex_digits = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	chardigits = (char *) malloc(blksize + 1);
	if (chardigits == NULL)
		return (NULL);
	chardigits[blksize--] = '\0';
	while (n > 0)
	{
		chardigits[blksize--] = hex_digits[n % 16];
		n = n / 16;
	}
	while (chardigits[blksize + 1])
		chardigits[i++] = chardigits[(blksize++) + 1];
	chardigits[i] = '\0';
	return (chardigits);
}
