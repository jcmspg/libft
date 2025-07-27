/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:40:26 by joamiran          #+#    #+#             */
/*   Updated: 2024/05/07 20:49:59 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	init_data(&data, format);
	if (!format)
		return (-1);
	while (*data.str)
	{
		if (*data.str == '%')
		{
			if (++data.str)
			{
				ft_parse_wrapper(&data);
				ft_print_type(&data);
				init_flags(&data);
			}
		}
		else
		{
			ft_write(*data.str++);
			data.chars_printed++;
		}
	}
	va_end(data.ap);
	return (data.chars_printed);
}

void	init_data(t_data *data, const char *format)
{
	data->str = format;
	data->chars_printed = 0;
	init_flags(data);
}

void	init_flags(t_data *data)
{
	data->format.minus_sign = 0;
	data->format.zero_padding = 0;
	data->format.width = 0;
	data->format.precision = -1;
	data->format.hashtag = 0;
	data->format.space_inb4 = 0;
	data->format.plus_sign = 0;
	data->format.type = '\0';
	data->format.upper_case_flag = 0;
	data->format.base = 0;
	data->format.unsigned_flag = 0;
	data->format.percent_flag = 0;
}
