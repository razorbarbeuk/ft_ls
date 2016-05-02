/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:56 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 17:58:57 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_swap(t_data *data_c)
{
	t_fich *tmp;

	tmp = data_c->data;
	data_c->data = data_c->next->data;
	data_c->next->data = tmp;
}

int			ft_sort_by_time(t_data *a, t_data *b)
{
	if (a->data->infos.st_mtime == b->data->infos.st_mtime)
	{
		if (a->data->infos.st_mtimespec.tv_nsec \
			== b->data->infos.st_mtimespec.tv_nsec \
			&& ft_strcmp(a->data->name, b->data->name) > 0)
			return (1);
		else if (a->data->infos.st_mtimespec.tv_nsec \
			< b->data->infos.st_mtimespec.tv_nsec)
			return (1);
		else
			return (0);
	}
	else if (a->data->infos.st_mtime < b->data->infos.st_mtime)
		return (1);
	else
		return (0);
}

int			ft_sort_control(t_ls *ls, t_data *a, t_data *b)
{
	if (a && b)
	{
		if (ls->options.opt_t)
		{
			return (ft_sort_by_time(a, b));
		}
		else if (ls->options.opt_u)
			return (ft_strcmp_time(a->data->infos.st_atime, \
				b->data->infos.st_atime));
	}
	return (ft_strcmp(a->data->name, b->data->name));
}

t_data		*ft_sort(t_ls *ls, t_data *data_c)
{
	int		i;
	t_data	*start;

	i = 1;
	start = NULL;
	while (i)
	{
		i = 0;
		start = data_c;
		while (data_c && data_c->next)
		{
			if (ft_sort_control(ls, data_c, data_c->next) > 0)
			{
				ft_swap(data_c);
				i = 1;
			}
			data_c = data_c->next;
		}
		data_c = start;
	}
	return (data_c);
}
