/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:36:49 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/12/18 15:24:18 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_us_hex_digit(unsigned int num)
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

static void	print_num_hex_rec_part(unsigned int num, char designator)
{
	if (num >= 16)
	{
		print_num_hex_rec_part(num / 16, designator);
		print_num_hex_rec_part(num % 16, designator);
	}
	else
	{
		if (num > 9)
		{
			if (designator == 'x')
				print_chr(num - 10 + 'a');
			if (designator == 'X')
				print_chr(num - 10 + 'A');
		}
		else
			print_chr(num + '0');
	}
}

int	print_num_hex(unsigned int num, char designator)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		print_num_hex_rec_part(num, designator);
	return (count_us_hex_digit(num));
}
