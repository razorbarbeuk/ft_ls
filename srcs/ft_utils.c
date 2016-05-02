/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:17 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 18:00:41 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strcat_ls(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(s1);
	j = 0;
	tmp = (char *)malloc((i + ft_strlen(s2) + 1) * sizeof(char));
	ft_strcpy(tmp, s1);
	while (s2[j] != '\0')
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return (tmp);
}

char	ft_is_in(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_strcmp_time(int s1, int s2)
{
	int result;

	result = s2 - s1;
	if (result > 0)
		return (1);
	return (0);
}

t_data	*ft_reverse(t_data *data_c)
{
	t_data *tmp;
	t_data *tmp_start_new;

	tmp_start_new = NULL;
	while (data_c != NULL)
	{
		tmp = data_c->next;
		data_c->next = tmp_start_new;
		tmp_start_new = data_c;
		data_c = tmp;
	}
	return (tmp_start_new);
}

int		ft_calc_space(int a, char *b)
{
	return (a - ft_strlen(b));
}
