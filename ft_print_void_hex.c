/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:27:41 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/12/18 15:24:39 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(uintptr_t num)
{
	if (num >= 16)
	{
		print_hex(num / 16);
		print_hex(num % 16);
	}
	else
	{
		if (num > 9)
			print_chr(num - 10 + 'a');
		else
			print_chr(num + '0');
	}
}

static int	count_hex(uintptr_t num)
{
	int	count;

	count = 1;
	while (num / 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	print_void_hex(unsigned long p_arg)
{
	int	result;

	result = 0;
	result += print_str("0x");
	if (!p_arg)
		result += write(1, "0", 1);
	else
	{
		print_hex(p_arg);
		result += count_hex(p_arg);
	}
	return (result);
}
