/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:36:55 by gbourson          #+#    #+#             */
/*   Updated: 2015/12/15 18:05:55 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		r;
	int		si;

	i = 0;
	r = 0;
	si = 1;
	while (*str != '\0' && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\f' || *str == '\v'))
		str++;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[i] == '-')
			si = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * si);
}