/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:14:39 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:39:49 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_null_and_precision(t_data *data, char **str)
{
	char	*null_str;

	null_str = "(null)";
	if (*str == NULL)
		*str = null_str;
	if (*str == null_str && data->format.precision >= 0
		&& data->format.precision <= 5)
	{
		*str = "";
	}
}

void	ft_print_str(t_data *data, char *str)
{
	int	len;
	int	chars_printed;
	int	padding;

	chars_printed = 0;
	handle_null_and_precision(data, &str);
	len = ft_strlen(str);
	if (data->format.precision != -1 && data->format.precision < len)
		len = data->format.precision;
	padding = data->format.width - len;
	if (!data->format.minus_sign && padding > 0)
		ft_print_padding(data, padding);
	chars_printed += ft_write_str(str, len);
	if (data->format.minus_sign && padding > 0)
		ft_print_padding(data, padding);
	data->chars_printed += chars_printed;
}

void	ft_print_str_fd(t_data *data, char *str, int fd)
{
	int	len;
	int	chars_printed;
	int	padding;

	chars_printed = 0;
	handle_null_and_precision(data, &str);
	len = ft_strlen(str);
	if (data->format.precision != -1 && data->format.precision < len)
		len = data->format.precision;
	padding = data->format.width - len;
	if (!data->format.minus_sign && padding > 0)
		ft_print_padding_fd(data, padding, ' ', fd);
	chars_printed += ft_write_str_fd(str, len, fd);
	if (data->format.minus_sign && padding > 0)
		ft_print_padding_fd(data, padding, ' ', fd);
	data->chars_printed += chars_printed;
}
