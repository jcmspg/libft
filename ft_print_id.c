/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:53:26 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:38:43 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_negative(int *n, int *abs_n)
{
	if (*n < 0)
		*abs_n = -*n;
}

static void	handle_zero_padding(t_data *data, int n, int padding, int pre_p)
{
	if (data->format.zero_padding && data->format.precision == -1)
	{
		print_sign(data, n);
		print_padding(data, padding, '0');
	}
	else
	{
		print_padding(data, padding - pre_p, ' ');
		print_sign(data, n);
		print_padding(data, pre_p, '0');
	}
}

static int	handle_padding(t_data *data, t_padding_data *pd)
{
	if (data->format.minus_sign)
	{
		print_sign(data, pd->n);
		print_padding(data, pd->pre_p, '0');
		if (!(pd->n == 0 && data->format.precision == 0))
			data->chars_printed += ft_write_nbr(pd->abs_n);
		if (pd->padding > pd->pre_p)
			print_padding(data, pd->padding - pd->pre_p, ' ');
		return (1);
	}
	if (pd->padding < 0)
	{
		print_sign(data, pd->n);
		print_padding(data, pd->pre_p, '0');
		if (!(pd->n == 0 && data->format.precision == 0))
			data->chars_printed += ft_write_nbr(pd->abs_n);
		return (1);
	}
	handle_zero_padding(data, pd->n, pd->padding, pd->pre_p);
	return (0);
}

void	ft_print_id(t_data *data, int n)
{
	int	padding;
	int	abs_n;
	int	pre_p;
	int	printd;

	abs_n = n;
	padding = calculate_padding(data, n);
	handle_negative(&n, &abs_n);
	pre_p = data->format.precision - ft_nbrlen(abs_n);
	if (pre_p < 0)
		pre_p = 0;
	if (n == 0 && data->format.precision == 0)
	{
		print_padding(data, padding + 1, ' ');
		return ;
	}
	if (n >= 0 && data->format.space_inb4)
	{
		data->chars_printed += ft_write(' ');
		padding--;
	}
	printd = handle_padding(data, &(t_padding_data){n, abs_n, padding, pre_p});
	if (!printd)
		data->chars_printed += ft_write_nbr(abs_n);
}

void	ft_print_id_fd(t_data *data, int n, int fd)
{
	int	padding;
	int	abs_n;
	int	pre_p;
	int	printd;

	abs_n = n;
	padding = calculate_padding(data, n);
	handle_negative(&n, &abs_n);
	pre_p = data->format.precision - ft_nbrlen(abs_n);
	if (pre_p < 0)
		pre_p = 0;
	if (n == 0 && data->format.precision == 0)
	{
		ft_print_padding_fd(data, padding + 1, ' ', fd);
		return ;
	}
	if (n >= 0 && data->format.space_inb4)
	{
		data->chars_printed += ft_write_fd(' ', fd);
		padding--;
	}
	printd = handle_padding(data, &(t_padding_data){n, abs_n, padding, pre_p});
	if (!printd)
		data->chars_printed += ft_write_nbr_fd(abs_n, fd);
}
