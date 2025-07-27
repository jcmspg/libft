/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:16:52 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:40:15 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_padding(t_data *data, int padding)
{
	while (padding > 0)
	{
		if (data->format.zero_padding)
			ft_write('0');
		else
			ft_write(' ');
		data->chars_printed++;
		padding--;
	}
}

void	print_sign(t_data *data, int n)
{
	if (n < 0)
		data->chars_printed += ft_write('-');
	else if (data->format.plus_sign)
		data->chars_printed += ft_write('+');
}

void	print_padding(t_data *data, int padding, char c)
{
	while (padding-- > 0)
		data->chars_printed += ft_write(c);
}

int	calculate_padding(t_data *data, int n)
{
	int	len;
	int	padding;

	len = ft_nbrlen(n);
	padding = data->format.width - len;
	if (data->format.plus_sign || n < 0)
		padding--;
	return (padding);
}

void	ft_print_padding_fd(t_data *data, int padding, char c, int fd)
{
	while (padding-- > 0)
		data->chars_printed += ft_write_fd(c, fd);
}
