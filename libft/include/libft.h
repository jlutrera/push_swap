/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:57:33 by jutrera-          #+#    #+#             */
/*   Updated: 2022/12/18 18:57:33 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_flags{
	int		dot;
	bool	sharp;
	bool	add;
	bool	minus;
	bool	space;
	bool	zero;
	int		width;
	int		prec;
	char	type;
}	t_flags;

//ft_printf_utils_1.c
int		char_in_str(char c, char const *s);
int		len_number(long n, int len_base);
int		ulen_number(unsigned long n, int len_base);

//ft_printf_utils_2.c
int		putdigit(char *s, t_flags flags, char c, int len);

//ft_printf_utils_3.c
t_flags	read_flags(char *s, va_list ap);

// functions
int		ft_atoi(const char *str, int *num);
char	*ft_itoa(long n);
int		ft_printf(char const *format, ...);
int		ft_putchar_bonus(char c, t_flags flags);
int		ft_putchar(char c);
int		ft_putdigit(long n, t_flags flags);
int		ft_puthex(unsigned int nb, t_flags flags);
int		ft_putpointer(void *pointer, t_flags flags);
int		ft_putstr(char *s);
int		ft_putstr_bonus(char *s, t_flags flags);
int		ft_putunsigned(unsigned long n, t_flags flags);
char	**ft_split(char *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *s);
char	*ft_uitoa(unsigned long n);

#endif