/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:30:45 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:24:52 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//malloc, free, write,
//va_start, va_arg, va_copy, va_end
//cspdiuxX%

int	print_chr(int letter)
{
	write(1, &letter, 1);
	return (1);
}

int	print_str(char *str)
{
	int		count;
	char	*a;

	a = "(null)";
	count = 0;
	if (str == NULL)
	{
		while (a[count] != '\0')
		{
			print_chr(a[count]);
			count++;
		}
		return (6);
	}
	while (str[count] != '\0')
	{
		print_chr(str[count]);
		count++;
	}
	return (count);
}

static int	print_num_dec(int num)
{
	size_t	digit;

	digit = 1;
	ft_putnbr_fd(num, 1);
	if (num < 0)
	{
		num = -num;
		digit++;
	}
	while (num / 10)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

static int	ft_format(va_list *args, const char designator)
{
	int	result_size;

	result_size = 0;
	if (designator == 'c')
		result_size += print_chr(va_arg(*args, int));
	else if (designator == 's')
		result_size += print_str(va_arg(*args, char *));
	else if (designator == 'p')
		result_size += print_void_hex(va_arg(*args, unsigned long));
	else if (designator == 'd' || designator == 'i')
		result_size += print_num_dec(va_arg(*args, int));
	else if (designator == 'u')
		result_size += print_us_num_dec(va_arg(*args, unsigned int));
	else if (designator == 'x' || designator == 'X')
		result_size += print_num_hex(va_arg(*args, unsigned int), designator);
	else if (designator == '%')
		result_size += print_chr('%');
	return (result_size);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		return_size;
	va_list	args;

	count = 0;
	return_size = 0;
	va_start(args, format);
	while (format[count])
	{
		if (format[count] == '%')
		{
			return_size += ft_format(&args, format[count + 1]);
			count++;
		}
		else
			return_size += print_chr(format[count]);
		count++;
	}
	va_end(args);
	return (return_size);
}
