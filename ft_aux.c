/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:08:07 by joamiran          #+#    #+#             */
/*   Updated: 2024/05/08 18:19:22 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

char	*set_hex_str(t_data *data, unsigned int arg)
{
	char	*hex_str;

	if (!arg && data->format.precision != 0)
		hex_str = ft_strdup("0");
	else if (!arg && data->format.precision == 0)
		hex_str = ft_strdup("");
	else
		hex_str = ft_itoa_base(arg, 16);
	return (hex_str);
}

int	set_prpad(t_data *data, char *hex_str)
{
	int	prpad;

	prpad = data->format.precision - ft_strlen(hex_str);
	if (prpad < 0)
		prpad = 0;
	return (prpad);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
