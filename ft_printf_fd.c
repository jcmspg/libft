/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:52:11 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:38:53 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *format, ...)
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
				ft_print_type_fd(&data, fd);
				init_flags(&data);
			}
		}
		else
		{
			ft_write_fd(*data.str++, fd);
			data.chars_printed++;
		}
	}
	va_end(data.ap);
	return (data.chars_printed);
}
