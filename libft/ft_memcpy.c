/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:54:52 by gbourson          #+#    #+#             */
/*   Updated: 2015/12/14 19:16:04 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p;
	const char	*o;

	p = dst;
	o = src;
	i = 0;
	while (n--)
	{
		p[i] = o[i];
		i++;
	}
	return (dst);
}
