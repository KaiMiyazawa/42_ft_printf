/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:37:33 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/06/25 16:04:57 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		print_chr(int letter);
int		print_str(char *str);
int		print_void_hex(unsigned long p_arg);
int		print_num_hex(unsigned int num, char designator);
int		print_us_num_dec(unsigned int num);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif