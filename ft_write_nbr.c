/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:57:35 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:37:49 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_nbr(int n)
{
	int	chars_printed;

	if (n == -2147483648)
	{
		chars_printed = ft_write_nbr(n / 10);
		chars_printed += ft_write('8');
		return (chars_printed);
	}
	chars_printed = 0;
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		chars_printed += ft_write_nbr(n / 10);
	}
	chars_printed += ft_write(n % 10 + '0');
	return (chars_printed);
}

int	ft_write_nbr_fd(int n, int fd)
{
	int	chars_printed;

	if (n == -2147483648)
	{
		chars_printed = ft_write_nbr_fd(n / 10, fd);
		chars_printed += ft_write_fd('8', fd);
		return (chars_printed);
	}
	chars_printed = 0;
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		chars_printed += ft_write_nbr_fd(n / 10, fd);
	}
	chars_printed += ft_write_fd(n % 10 + '0', fd);
	return (chars_printed);
}
