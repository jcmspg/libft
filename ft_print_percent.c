/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:47:00 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:38:21 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_data *data)
{
	ft_write('%');
	data->chars_printed++;
}

void	ft_print_percent_fd(t_data *data, int fd)
{
	ft_write_fd('%', fd);
	data->chars_printed++;
}
