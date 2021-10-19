/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:25:50 by oipadeol          #+#    #+#             */
/*   Updated: 2021/10/19 19:11:33 by oipadeol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct flags
{
	bool	minus;
	bool	plus;
	bool	wspace;
	bool	hash;
	bool	zero;
	int		digit;
	int		pres;
	bool	var_width;
	bool	var_pres;
	int		leading_space;
	bool	dot;
}t_flag;

void	ft_bchar(void *dest, char c, size_t len);
void	set_flags(char *s, t_flag *flag);
void	*write_p(unsigned long num, t_flag **flag, int ***len);
void	*write_x(unsigned int num, t_flag **flag, int ***len, char c);
void	*write_u(unsigned int num, t_flag **flag, int ***len);
void	*write_di(int num, t_flag **flag, int ***len);
void	*write_char(char c, t_flag **flag, int ***len);
void	*write_s(char *s, t_flag **flag, int ***len);
void	format_zero(char **s, char c);
void	*format_width(char **s, int width);
void	format_pres(char **s, int pres);
void	*format_presnum(char **s, int pres);
int		format_minus(char **s, int leading_space);
int		return_sign(char **s, int num, int plus);
void	remove_sign(char **s);
void	*format_hash(char **s, char x);
int		ft_printf(const char *s, ...);

#endif