/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:17:14 by eushin            #+#    #+#             */
/*   Updated: 2023/06/25 21:40:29 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
void	find_format(va_list ap, int *cnt, char format);
void	print_char(int var, int *cnt);
void	print_str(char *var, int *cnt);
void	print_int(int nb, int *cnt);
void	print_unsignedint(unsigned int nb, int *cnt);
void	print_ptr(size_t var, int *cnt);
void	print_hex(size_t nb, int *cnt, char format);

#endif
