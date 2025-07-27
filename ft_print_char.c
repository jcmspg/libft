/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:56:07 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:39:59 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* print char
wrapper function to print char
prints a character and increments the number of characters printed

needs to handle the width and flags

if there is a width, it will print the padding before or after the character
no preicision for characters, nor zeros, nor space inb4,
nor plus sign, nor hashtag
just width and minus sign */

void	ft_print_char(t_data *data, int c)
{
	int	padding;

	padding = 0;
	data->format.zero_padding = 0;
	if (data->format.width > 1)
		padding = data->format.width - 1;
	if (padding > 0)
	{
		if (!data->format.minus_sign)
			ft_print_padding(data, padding);
		if (ft_write(c) >= 0)
			data->chars_printed++;
		if (data->format.minus_sign)
			ft_print_padding(data, padding);
	}
	else
	{
		if (ft_write(c) >= 0)
			data->chars_printed++;
	}
}

void	ft_print_char_fd(t_data *data, int c, int fd)
{
	int	padding;

	padding = 0;
	data->format.zero_padding = 0;
	if (data->format.width > 1)
		padding = data->format.width - 1;
	if (padding > 0)
	{
		if (!data->format.minus_sign)
			ft_print_padding_fd(data, padding, ' ', fd);
		if (ft_write_fd(c, fd) >= 0)
			data->chars_printed++;
		if (data->format.minus_sign)
			ft_print_padding_fd(data, padding, ' ', fd);
	}
	else
	{
		if (ft_write_fd(c, fd) >= 0)
			data->chars_printed++;
	}
}
