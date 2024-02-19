/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:56:05 by olamrabt          #+#    #+#             */
/*   Updated: 2024/02/18 17:56:09 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	ft_check_flow(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num > (9223372036854775807ULL - (*str - '0')) / 10)
			return (ft_check_flow(sign));
		num = num * 10 + *str - 48;
		str++;
	}
	return ((int)(num * sign));
}
