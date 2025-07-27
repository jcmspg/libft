/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:47:01 by joao              #+#    #+#             */
/*   Updated: 2024/05/07 20:49:22 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
parse flags (0, -, ', #, +, ' ')
*/

void	ft_parse_flags(t_data *data)
{
	while (ft_strchr(FLAGS, *data->str))
	{
		if (*data->str == '-')
			data->format.minus_sign = 1;
		else if (*data->str == '0')
			data->format.zero_padding = 1;
		else if (*data->str == '#')
			data->format.hashtag = 1;
		else if (*data->str == ' ')
			data->format.space_inb4 = 1;
		else if (*data->str == '+')
			data->format.plus_sign = 1;
		++data->str;
	}
}

// parse width (number or *)
void	ft_parse_width(t_data *data)
{
	if (*data->str == '*')
	{
		data->format.width = va_arg(data->ap, int);
		++data->str;
	}
	else
	{
		data->format.width = ft_atoi(data->str);
		while (ft_isdigit(*data->str))
			++data->str;
	}
}

// parse precision (.number or .* or .)
void	ft_parse_precision(t_data *data)
{
	if (*data->str == '.')
	{
		++data->str;
		if (*data->str == '*')
		{
			data->format.precision = va_arg(data->ap, int);
			++data->str;
		}
		else
		{
			data->format.precision = ft_atoi(data->str);
			while (ft_isdigit(*data->str))
				++data->str;
		}
	}
}

// parse type (c, s, p, d, i, u, x, X, %)
void	ft_parse_type(t_data *data)
{
	if (ft_strchr(TYPES, *data->str))
	{
		data->format.type = *data->str;
		++data->str;
	}
}

void	ft_parse_base(t_data *data)
{
	if (data->format.type == 'x' || data->format.type == 'X')
	{
		data->format.base = 16;
		if (data->format.type == 'X')
			data->format.upper_case_flag = 1;
	}
	else if (data->format.type == 'u')
		data->format.unsigned_flag = 1;
	else if (data->format.type == 'p')
	{
		data->format.base = 16;
		data->format.hashtag = 1;
		data->format.unsigned_flag = 1;
	}
	else
		data->format.base = 10;
}
