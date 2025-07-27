/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:48:48 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:39:37 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(int c)
{
	char	ch;

	ch = (char)c;
	return (write(1, &ch, 1));
}

int	ft_write_fd(int c, int fd)
{
	char	ch;

	ch = (char)c;
	return (write(fd, &ch, 1));
}
