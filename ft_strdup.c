/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:37:51 by joamiran          #+#    #+#             */
/*   Updated: 2024/11/22 17:23:56 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_copy(const char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		len;

	len = ft_strlen(src);
	copy = malloc(sizeof(char) * len + 1);
	if (copy)
	{
		str_copy(src, copy);
		copy[len] = '\0';
	}
	else
		return (NULL);
	return (copy);
}
