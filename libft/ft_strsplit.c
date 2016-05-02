/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:16:42 by gbourson          #+#    #+#             */
/*   Updated: 2015/12/15 18:07:11 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_word(char const *w, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (w[i] != '\0')
	{
		while (w[i] == c)
			i++;
		if (w[i] != c && w[i - 1] == c)
			j++;
		i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		start;
	int		j;
	char	**str;

	i = 0;
	start = 0;
	j = 0;
	if (!(str = (char **)malloc((ft_c_word(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (i > 1 && s[i - 1] == c)
			start = i;
		while (s[i] && s[i] != c)
			i++;
		if (s[start])
			str[j] = ft_strsub(s, start, i - start);
		if (s[start])
			j++;
	}
	str[j] = 0;
	return (str);
}
