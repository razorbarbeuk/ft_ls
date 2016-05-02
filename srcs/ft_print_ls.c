/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:16 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 17:58:20 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_elem(char *print, char *c, int j, int t)
{
	int space;

	space = 0;
	if (t)
		space = ft_calc_space(t, print);
	if (j)
	{
		ft_putstr(print);
		ft_print_space_char(space);
	}
	else
	{
		ft_print_space_char(space);
		ft_putstr(print);
	}
	if (c != 0)
		ft_putstr(c);
}

void	ft_sym_link(t_ls *ls, t_data *data_c)
{
	ls->len = readlink(data_c->data->path, data_c->data->link, \
		sizeof(data_c->data->link) - 1);
	data_c->data->link[ls->len] = '\0';
	data_c->data->name = ft_strjoin(data_c->data->name, " -> ");
	data_c->data->name = ft_strjoin(data_c->data->name, data_c->data->link);
}

void	ft_print_time(t_data *data_c, int *t)
{
	ft_print_elem(data_c->data->c_time[1], " ", 0, 0);
	ft_print_elem(data_c->data->c_time[2], " ", 0, t[4]);
	if ((time(NULL) - (data_c->data->infos.st_mtime)) > 15548400 \
		|| (data_c->data->infos.st_mtime) > (time(NULL) + 15548400))
	{
		ft_putchar(' ');
		ft_print_elem(ft_strtrim(data_c->data->c_time[4]), " ", 0, 0);
	}
	else
	{
		ft_print_elem(data_c->data->hour[0], ":", 0, 0);
		ft_print_elem(data_c->data->hour[1], " ", 0, 0);
	}
}

void	ft_show_detail(t_ls *ls, char *path)
{
	if (ls->is_first)
		ft_putchar('\n');
	if (ls->is_first || ls->rec > 3)
		ft_print_elem(path, ":\n", 0, 0);
	return ;
}

void	ft_print_model(t_ls *ls, t_data *data_c, int *t)
{
	ft_print_elem(data_c->data->protection, "  ", 0, 0);
	ft_print_elem(ft_itoa(data_c->data->nlinks), " ", 0, t[0]);
	!ls->options.opt_g ? ft_print_elem(data_c->data->user, "  ", 1, t[1]) \
		: data_c;
	ft_print_elem(data_c->data->group_name, "  ", 1, t[2]);
	if (data_c->data->type == 'c' || data_c->data->type == 'b')
	{
		ft_print_elem(ft_itoa(MAJOR(data_c->data->infos.st_rdev)), ", " \
			, 0, t[5]);
		ft_print_elem(ft_itoa(MINOR(data_c->data->infos.st_rdev)), " ", 0 \
			, t[6]);
	}
	else
		ft_print_elem(ft_itoa(data_c->data->octet), " ", 0, t[3] + t[6]);
	ft_print_time(data_c, t);
	if (data_c->data->type == 'l')
		ft_sym_link(ls, data_c);
	ft_color(data_c->data->infos.st_mode);
	ft_print_elem(data_c->data->name, "\n", 0, 0);
	ft_putstr("\e[0m");
}
