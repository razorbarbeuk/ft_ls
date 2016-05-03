/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:03 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/03 13:27:09 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*ft_print_lst(t_ls *ls, t_data *data_c, int *t)
{
	t_data	*start;

	start = NULL;
	start = data_c;
	ls->is_first = 1;
	while (data_c)
	{
		if (ls->options.opt_l || ls->options.opt_g)
			ft_print_model(ls, data_c, t);
		else if (ls->options.opt_1)
			ft_print_elem(data_c->data->name, "\n", 0, 0);
		else if (data_c->next)
			ft_print_elem(data_c->data->name, "\n", 0, 0);
		else
			ft_print_elem(data_c->data->name, "\n", 0, 0);
		data_c = data_c->next;
	}
	data_c = start;
	return (start);
}

void	ft_create_lst(t_ls *ls, t_data *data_c)
{
	t_data	*start;

	start = NULL;
	!ls->options.opt_f ? ft_sort(ls, data_c) : data_c;
	ls->options.opt_r ? data_c = ft_reverse(data_c) : data_c;
	start = ft_print_lst(ls, data_c, ft_space_count(data_c));
	(ls->is_first && ls->options.opt_up_r) ? ft_open_lst(ls, start) : start;
}

t_data	*ft_opt_a(t_ls *ls, t_data *list_folder)
{
	if (ls->is_first_a && !ls->options.opt_r)
	{
		while (list_folder && list_folder->data->name[0] != '.')
			list_folder = list_folder->next;
		while (list_folder && list_folder->data->name[0] == '.')
			list_folder = list_folder->next;
	}
	else if (ls->is_first_a && ls->options.opt_r)
	{
		while (list_folder && list_folder->data->name[0] == '.')
			list_folder = list_folder->next;
	}
	return (list_folder);
}

void	ft_create_lst_file(t_ls *ls, t_data *file)
{
	t_data	*tmp;
	t_data	*list_folder;
	t_data	*list_files;

	list_folder = NULL;
	list_files = NULL;
	if (ls->options.opt_d)
		ft_create_lst(ls, file);
	else
	{
		while (file)
		{
			tmp = file->next;
			file->next = NULL;
			if (file->data->type == 'd')
				ft_lst_new(&list_folder, file, ls);
			else
				ft_lst_new(&list_files, file, ls);
			file = tmp;
		}
		if (list_files)
			ft_create_lst(ls, list_files);
		if (list_folder)
			ft_open_lst(ls, list_folder);
	}
}
