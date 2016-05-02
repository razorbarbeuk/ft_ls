/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:40 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 17:58:42 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lst_new(t_data **alst, t_data *new, t_ls *ls)
{
	t_data *tmp;

	if (ls->is_first && !ls->options.opt_a && new->data->name[0] == '.')
		return ;
	tmp = *alst;
	if (tmp == NULL)
		*alst = new;
	else if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	*ft_name_join(char *name, char *path)
{
	char *tmp;

	if (ft_strcmp(path, "/") != 0)
		path = ft_strjoin(path, "/");
	tmp = ft_strjoin(path, name);
	return (tmp);
}

void	ft_mount_lstat(t_data *data_c, struct stat *infos)
{
	struct passwd	*infos_sup;
	struct group	*infos_gr;

	infos_sup = NULL;
	infos_gr = NULL;
	data_c->data->user = getpwuid(infos->st_uid) ? \
	getpwuid(infos->st_uid)->pw_name : ft_itoa(infos->st_uid);
	data_c->data->group_name = getgrgid(infos->st_gid) ? \
	getgrgid(infos->st_gid)->gr_name : ft_itoa(infos->st_gid);
	data_c->data->infos = *infos;
	data_c->data->octet = infos->st_size;
	data_c->data->blocks = infos->st_blocks;
	data_c->data->nlinks = infos->st_nlink;
	ft_protect(data_c->data->infos.st_mode, data_c->data->protection);
	data_c->data->type = data_c->data->protection[0];
	data_c->data->c_time = ft_strsplit(ctime(&infos->st_mtime), ' ');
	data_c->data->hour = ft_strsplit(data_c->data->c_time[3], ':');
	data_c->data->space = ft_count_number(data_c->data->octet);
}

t_data	*ft_stat(t_ls *ls, char *name, char *path)
{
	t_data			*data_c;
	struct stat		infos;

	data_c = NULL;
	path = (!ls->is_first) ? name : ft_name_join(name, path);
	if (lstat(path, &infos) == -1)
		ft_error(name);
	data_c = (t_data *)malloc(sizeof(t_data));
	data_c->data = (t_fich *)malloc(sizeof(t_fich));
	if (data_c->data)
	{
		data_c->data->name = name;
		data_c->data->path = path;
		ft_mount_lstat(data_c, &infos);
	}
	data_c->next = NULL;
	ls->count_file++;
	return (data_c);
}
