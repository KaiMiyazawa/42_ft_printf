/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmiyazaw <kmiyazaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:03:46 by kmiyazaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:25:00 by kmiyazaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		n_long *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n_long > 9)
		ft_putnbr_fd((int)(n_long / 10), fd);
	c = (n_long % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (s)
	{
		while (s[count] != '\0')
		{
			ft_putchar_fd(s[count], fd);
			count++;
		}
	}
}
