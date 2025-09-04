/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:05:08 by joamiran          #+#    #+#             */
/*   Updated: 2025/09/04 20:05:51 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

long	ft_labs(long n)
{
    if (n < 0)
        return (-n);
    return (n);
}

double	ft_dabs(double n)
{
    if (n < 0)
        return (-n);
    return (n);
}

float	ft_fabs(float n)
{
    if (n < 0)
        return (-n);
    return (n);
}


