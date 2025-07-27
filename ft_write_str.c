/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:52:20 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:38:34 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(char *str, int len)
{
	return (write(1, str, len));
}

int	ft_write_str_fd(char *str, int len, int fd)
{
	return (write(fd, str, len));
}
