/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:17:41 by gbourson          #+#    #+#             */
/*   Updated: 2015/12/14 19:04:47 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	if (!(s = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (s)
	{
		i = 0;
		while (i != size + 1)
		{
			s[i] = '\0';
			i++;
		}
	}
	return (s);
}
