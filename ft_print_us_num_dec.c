/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_us_num_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:35:39 by miyazawa.ka       #+#    #+#             */
/*   Updated: 2023/12/18 15:24:28 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_digit(unsigned long n)
{
	size_t	digit;

	digit = 1;
	while (n / 10)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	make_char(int size, unsigned long n, char *result)
{
	while (n / 10)
	{
		result[size] = n % 10 + 48;
		size--;
		n /= 10;
	}
	result[size] = n % 10 + 48;
}

static char	*ft_uitoa(unsigned int n)
{
	char			*result;
	size_t			size;
	unsigned long	n_us_long;

	n_us_long = (unsigned long)n;
	size = (get_digit(n_us_long) + 1) * sizeof(char);
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	result[--size] = '\0';
	make_char(--size, n_us_long, result);
	return (result);
}

int	print_us_num_dec(unsigned int num)
{
	char	*us_num;

	us_num = ft_uitoa(num);
	ft_putstr_fd(us_num, 1);
	free(us_num);
	return (get_digit(num));
}
