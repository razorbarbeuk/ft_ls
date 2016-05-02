/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:07:05 by gbourson          #+#    #+#             */
/*   Updated: 2015/12/14 19:14:39 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *p;
	unsigned const char *o;

	p = s1;
	o = s2;
	while (n > 0)
	{
		if (*p != *o)
			return (*p - *o);
		p++;
		o++;
		n--;
	}
	return (0);
}
