/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:44:16 by gbourson          #+#    #+#             */
/*   Updated: 2015/12/15 11:52:58 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*p;
	const char		*o;
	char			l;

	i = 0;
	p = (char *)dst;
	o = (const char *)src;
	l = (char)c;
	while (n--)
	{
		p[i] = o[i];
		if (o[i] == l)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
