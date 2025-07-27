/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_wrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:24:47 by joamiran          #+#    #+#             */
/*   Updated: 2024/05/07 20:49:27 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_wrapper(t_data *data)
{
	ft_parse_flags(data);
	ft_parse_width(data);
	ft_parse_precision(data);
	ft_parse_type(data);
	ft_parse_base(data);
}
