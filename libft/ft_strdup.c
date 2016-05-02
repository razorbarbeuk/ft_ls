/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:56:16 by gbourson          #+#    #+#             */
/*   Updated: 2015/12/14 18:47:49 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;
	int		n;

	i = ft_strlen(s1);
	n = 0;
	if ((str = (char *)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	if (s1)
	{
		while (n < i)
		{
			str[n] = s1[n];
			n++;
		}
		str[n] = '\0';
	}
	return (str);
}
