/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:51 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 17:58:52 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_space_char(char i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putchar(' ');
		j++;
	}
}

void	ft_minor_major_space(t_data *data_c, int *tab_space)
{
	if (data_c->data->type == 'c' || data_c->data->type == 'b')
	{
		if ((int)ft_strlen(ft_itoa(MAJOR(data_c->data->infos.st_rdev))) \
			> tab_space[5])
			tab_space[5] = \
			(int)ft_strlen(ft_itoa(MAJOR(data_c->data->infos.st_rdev)));
		if ((int)ft_strlen(ft_itoa(MINOR(data_c->data->infos.st_rdev))) \
			> tab_space[6])
			tab_space[6] = \
			(int)ft_strlen(ft_itoa(MINOR(data_c->data->infos.st_rdev)));
	}
	else
	{
		if ((int)ft_strlen(ft_itoa(data_c->data->octet)) > tab_space[3])
			tab_space[3] = (int)ft_strlen(ft_itoa(data_c->data->octet));
	}
}

int		*ft_space_count(t_data *data_c)
{
	t_data		*start;
	int			*tab_space;

	start = data_c;
	if (data_c)
	{
		tab_space = (int *)malloc(7 * sizeof(int));
		ft_memset(tab_space, 0, 7 * sizeof(int));
	}
	while (data_c)
	{
		if ((int)ft_strlen(ft_itoa(data_c->data->nlinks)) > tab_space[0])
			tab_space[0] = (int)ft_strlen(ft_itoa(data_c->data->nlinks));
		if ((int)ft_strlen(data_c->data->user) > tab_space[1])
			tab_space[1] = (int)ft_strlen(data_c->data->user);
		if ((int)ft_strlen(data_c->data->group_name) > tab_space[2])
			tab_space[2] = (int)ft_strlen(data_c->data->group_name);
		ft_minor_major_space(data_c, tab_space);
		if ((int)ft_strlen(data_c->data->c_time[2]) > tab_space[4])
			tab_space[4] = (int)ft_strlen(data_c->data->c_time[2]);
		data_c = data_c->next;
	}
	return (tab_space);
}

void	ft_block_count(t_ls *ls, t_data *data_c)
{
	if (data_c)
	{
		while (data_c)
		{
			ls->total_blocks = ls->total_blocks + data_c->data->blocks;
			data_c = data_c->next;
		}
		ft_print_elem("total", " ", 0, 0);
		ft_putnbr(ls->total_blocks);
		ft_putchar('\n');
	}
}
