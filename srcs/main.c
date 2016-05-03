/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:34 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/03 13:16:45 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_open_lst(t_ls *ls, t_data *list_folder)
{
	t_data			*start;
	t_data			*data_c;

	data_c = NULL;
	ls->total_blocks = 0;
	start = data_c;
	if (ls->is_first && ls->options.opt_a)
		list_folder = ft_opt_a(ls, list_folder);
	while (list_folder)
	{
		start = NULL;
		free(start);
		ls->count_file = 0;
		ft_open_dir(ls, list_folder, start);
		list_folder = list_folder->next;
	}
	free(list_folder);
}

void	ft_check_file(t_ls *ls, int i, char **av, int ac)
{
	t_data	*file;

	file = NULL;
	if (i == ac)
		ft_lst_new(&file, ft_stat(ls, ft_strdup("."), ft_strdup(".")), ls);
	while (i < ac)
	{
		ft_lst_new(&file, ft_stat(ls, ft_strdup(av[i]), ft_strdup(av[i])), ls);
		i++;
	}
	ls->count_file = i;
	ft_sort(ls, file);
	ft_create_lst_file(ls, file);
}

void	ft_parse_option(t_ls *ls, char **av)
{
	int i;

	i = 1;
	while (av[i] && av[i] != '\0')
	{
		if (av[i][0] == '-' && ft_strcmp(av[i], "--") != 0 && \
		ft_strcmp(av[i], "-") != 0)
		{
			if (!ft_opt(ls, av[i]))
			{
				ft_putendl_fd("usage: ls [-Rlartufhgd1] [file ...]", 2);
				exit(0);
			}
		}
		else
			break ;
		i++;
	}
	if (av[i] && ft_strcmp(av[i], "--") == 0)
		i++;
	ls->start = i;
}

int		main(int ac, char **av)
{
	t_ls ls;

	ls.rec = ac;
	ls.is_first = 0;
	ls.is_first_a = 0;
	ft_init_option(&ls);
	ft_parse_option(&ls, av);
	if (ls.options.opt_h)
		ft_show_help();
	ft_check_file(&ls, ls.start, av, ac);
	return (0);
}
