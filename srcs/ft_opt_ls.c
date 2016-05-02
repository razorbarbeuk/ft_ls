/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:58:46 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 17:58:47 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_protect_sticky(mode_t mode, char *str)
{
	if (str[3] == 'x' && (mode & S_ISUID))
		str[3] = 's';
	else if (mode & S_ISUID)
		str[3] = 'S';
	if (str[6] == 'x' && (mode & S_ISGID))
		str[6] = 's';
	else if (mode & S_ISGID)
		str[6] = 'S';
	if (str[9] == 'x' && (mode & S_ISVTX))
		str[9] = 't';
	else if (str[9] == '-' && (mode & S_ISVTX))
		str[9] = 'T';
}

char	ft_type(mode_t mode, char str)
{
	str = (S_ISREG(mode)) ? '-' : str;
	str = (S_ISDIR(mode)) ? 'd' : str;
	str = (S_ISCHR(mode)) ? 'c' : str;
	str = (S_ISBLK(mode)) ? 'b' : str;
	str = (S_ISFIFO(mode)) ? 'o' : str;
	str = (S_ISSOCK(mode)) ? 's' : str;
	str = (S_ISLNK(mode)) ? 'l' : str;
	return (str);
}

void	ft_protect(mode_t mode, char *str)
{
	ft_strcpy(str, "----------");
	str[0] = ft_type(mode, str[0]);
	str[1] = (mode & S_IRUSR) ? 'r' : '-';
	str[2] = (mode & S_IWUSR) ? 'w' : '-';
	str[3] = (mode & S_IXUSR) ? 'x' : '-';
	str[4] = (mode & S_IRGRP) ? 'r' : '-';
	str[5] = (mode & S_IWGRP) ? 'w' : '-';
	str[6] = (mode & S_IXGRP) ? 'x' : '-';
	str[7] = (mode & S_IROTH) ? 'r' : '-';
	str[8] = (mode & S_IWOTH) ? 'w' : '-';
	str[9] = (mode & S_IXOTH) ? 'x' : '-';
	ft_protect_sticky(mode, str);
}

void	ft_init_option(t_ls *ls)
{
	ls->options.opt_up_r = 0;
	ls->options.opt_l = 0;
	ls->options.opt_a = 0;
	ls->options.opt_r = 0;
	ls->options.opt_t = 0;
	ls->options.opt_u = 0;
	ls->options.opt_f = 0;
	ls->options.opt_g = 0;
	ls->options.opt_d = 0;
	ls->options.opt_h = 0;
	ls->options.opt_1 = 0;
}
