/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:11 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 18:00:38 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_color(mode_t mode)
{
	S_ISBLK(mode) ? ft_putstr(C_R) : NULL;
	S_ISCHR(mode) ? ft_putstr(C_BL) : NULL;
	S_ISDIR(mode) ? ft_putstr(C_CY) : NULL;
	S_ISFIFO(mode) ? ft_putstr(C_B) : NULL;
	S_ISLNK(mode) ? ft_putstr(C_G) : NULL;
	S_ISSOCK(mode) ? ft_putstr(C_Y) : NULL;
	S_ISREG(mode) ? ft_putstr(C_N) : NULL;
}

void	ft_open_dir(t_ls *ls, t_data *list_folder, t_data *start)
{
	DIR				*entry;
	struct dirent	*dir;

	start = NULL;
	free(start);
	ls->count_file = 0;
	if (list_folder->data->type == 'd')
	{
		ft_show_detail(ls, list_folder->data->path);
		ls->is_first = 1;
		if ((entry = opendir(list_folder->data->path)))
		{
			while ((dir = readdir(entry)))
				ft_lst_new(&start, ft_stat(ls, \
				ft_strdup(dir->d_name), list_folder->data->path), ls);
			(ls->options.opt_l) ? ft_block_count(ls, start) : start;
			ft_create_lst(ls, start);
			closedir(entry);
		}
		else
			ft_not_found_exit(list_folder->data->name);
	}
}
