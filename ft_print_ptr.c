/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:17:37 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/10 21:13:58 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(t_data *data, void *p)
{
	char	*hex;
	char	*original_hex;
	int		padding;

	if (p == NULL)
	{
		ft_print_padding(data, data->format.width - 5);
		data->chars_printed += (ft_write_str("(nil)", 5));
		return ;
	}
	hex = ft_itoa_base((unsigned long)p, 16);
	original_hex = hex;
	padding = data->format.width - ft_strlen(hex) - 2;
	if (padding > 0 && !data->format.minus_sign)
		ft_print_padding(data, padding);
	data->chars_printed += ft_write('0');
	data->chars_printed += ft_write('x');
	while (*hex)
	{
		data->chars_printed += ft_write(*hex);
		hex++;
	}
	if (padding > 0 && data->format.minus_sign)
		ft_print_padding(data, padding);
	free(original_hex);
}
