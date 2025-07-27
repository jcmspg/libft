/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:27:28 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/11 17:39:06 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen_base(unsigned long nbr, int base)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long value, int base)
{
	char		*str;
	char		*base_string;
	long long	nbr;
	int			len;

	base_string = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	nbr = (long)value;
	len = ft_nbrlen_base(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[--len] = base_string[nbr % base];
		nbr /= base;
	}
	return (str);
}
