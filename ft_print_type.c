/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:45:29 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/10 21:10:52 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_type(t_data *data)
{
	if (data->format.type == 'c')
		ft_print_char(data, (va_arg(data->ap, int)));
	else if (data->format.type == 's')
		ft_print_str(data, va_arg(data->ap, char *));
	else if (data->format.type == 'd' || data->format.type == 'i')
		ft_print_id(data, va_arg(data->ap, int));
	else if (data->format.type == 'p')
		ft_print_ptr(data, (void *)va_arg(data->ap, unsigned long));
	else if (data->format.type == 'u')
		ft_print_u(data, va_arg(data->ap, unsigned int));
	else if (data->format.type == 'x')
		ft_print_xx(data, va_arg(data->ap, unsigned int), 0);
	else if (data->format.type == 'X')
		ft_print_xx(data, va_arg(data->ap, unsigned int), 1);
	else if (data->format.type == '%')
		ft_print_percent(data);
}

void	ft_print_type_fd(t_data *data, int fd)
{
	if (data->format.type == 'c')
		ft_print_char_fd(data, (va_arg(data->ap, int)), fd);
	else if (data->format.type == 's')
		ft_print_str_fd(data, va_arg(data->ap, char *), fd);
	else if (data->format.type == 'd' || data->format.type == 'i')
		ft_print_id_fd(data, va_arg(data->ap, int), fd);
	else if (data->format.type == '%')
		ft_print_percent_fd(data, fd);
}
