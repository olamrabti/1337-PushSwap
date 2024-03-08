/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:56:05 by olamrabt          #+#    #+#             */
/*   Updated: 2024/03/01 20:19:37 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_flow(int sign, long long num, int *checker, char c)
{
	if (num > (INT_MAX - (c - '0')) / 10)
	{
		if (sign == -1 && -(num * 10 + c - 48) == INT_MIN)
		{
			*checker = 0;
			return (0);
		}
		*checker = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, int *checker)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ft_check_flow(sign, num, checker, *str))
			return (-1);
		num = num * 10 + *str - 48;
		str++;
		*checker = 0;
	}
	if ((!*checker && *str))
		*checker = 1;
	return ((int)(num * sign));
}
