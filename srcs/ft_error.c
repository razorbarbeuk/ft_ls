/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:26 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 17:58:27 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_opt_error(char *str, int i)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar(str[i]);
	ft_putchar('\n');
}

char	ft_opt(t_ls *ls, char *str)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_is_in("Rlartuhfgd1", str[i]))
		{
			ft_opt_error(str, i);
			return (0);
		}
		str[i] == ('R') ? ls->options.opt_up_r = 1 : str[i];
		str[i] == ('l') ? ls->options.opt_l = 1 : str[i];
		str[i] == ('a') ? ls->options.opt_a = 1 : str[i];
		str[i] == ('r') ? ls->options.opt_r = 1 : str[i];
		str[i] == ('t') ? ls->options.opt_t = 1 : str[i];
		str[i] == ('u') ? ls->options.opt_u = 1 : str[i];
		str[i] == ('f') ? ls->options.opt_f = 1 : str[i];
		str[i] == ('g') ? ls->options.opt_g = 1 : str[i];
		str[i] == ('d') ? ls->options.opt_d = 1 : str[i];
		str[i] == ('h') ? ls->options.opt_h = 1 : str[i];
		str[i] == ('1') ? ls->options.opt_1 = 1 : str[i];
		i++;
	}
	return (1);
}

int		ft_error(char *str)
{
	if (errno)
	{
		perror(ft_strcat_ls("ls: ", str));
		return (1);
	}
	return (0);
}

void	ft_not_found_exit(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	if (errno != 0)
		ft_putstr(strerror(errno));
	else
		ft_putstr("No such file or directory");
	ft_putchar('\n');
}

void	ft_show_help(void)
{
	ft_putendl("-R  -- list subdirectories recursively");
	ft_putendl("-a  -- list entries starting with .");
	ft_putendl("-l  -- long listing");
	ft_putendl("-r  -- reverse sort order");
	ft_putendl("-t  -- sort by modification time");
	ft_putendl("-c  -- add colors to output");
	ft_putendl("-i  -- show inode number");
	ft_putendl("-n  -- show uid and gid");
	ft_putendl("-h  -- print information about command");
	exit(0);
}
