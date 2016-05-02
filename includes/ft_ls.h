/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:59:26 by gbourson          #+#    #+#             */
/*   Updated: 2016/05/02 18:16:38 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <time.h>
# include <errno.h>

# include "../libft/includes/libft.h"

# define MAJOR(x)((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define MINOR(x)((int32_t)((x) & 0xffffff))

# define C_BL  "\e[38;5;4m"
# define C_R  "\e[38;5;9m"
# define C_CY "\e[38;5;14m"
# define C_B  "\e[38;5;12m"
# define C_G  "\e[38;5;10m"
# define C_Y  "\e[38;5;11m"
# define C_N  "\e[38;5;15m"

typedef struct			s_data
{
	struct s_fich		*data;
	struct s_data		*next;
}						t_data;

typedef struct			s_opt
{
	int					opt_up_r;
	int					opt_l;
	int					opt_a;
	int					opt_r;
	int					opt_t;
	int					opt_u;
	int					opt_f;
	int					opt_g;
	int					opt_d;
	int					opt_h;
	int					opt_1;
	int					opt_e;
}						t_opt;

typedef struct			s_fich
{
	char				*name;
	char				link[2048];
	char				*path;
	char				*user;
	char				*group_name;
	char				protection[11];
	char				type;
	int					blocks;
	int					nlinks;
	int					octet;
	int					space;
	char				**c_time;
	char				**hour;
	struct stat			infos;
}						t_fich;

typedef struct			s_ls
{
	t_opt				options;
	int					start;
	int					rec;
	int					count_file;
	int					is_first;
	int					total_blocks;
	ssize_t				len;
}						t_ls;

void					ft_parse_option(t_ls *ls, char **av);
void					ft_check_file(t_ls *ls, int i, char **av, int ac);
void					ft_open_lst(t_ls *ls, t_data *list_folder);
void					ft_open_dir(t_ls *ls, t_data *list_folder, \
	t_data *start);
t_data					*ft_opt_a(t_ls *ls, t_data *list_folder);
void					ft_create_lst_file(t_ls *ls, t_data *file);
void					ft_create_lst(t_ls *ls, t_data *data_c);
void					ft_lst_new(t_data **alst, t_data *new, t_ls *ls);
void					*ft_name_join(char *name, char *path);
t_data					*ft_stat(t_ls *ls, char *name, char *path);
void					ft_mount_lstat(t_data *data_c, struct stat *infos);
char					ft_opt(t_ls *ls, char *str);
void					ft_opt_error(char *str, int i);
void					ft_init_option(t_ls *ls);
char					ft_type(mode_t mode, char str);
void					ft_protect(mode_t mode, char *str);
void					ft_swap_char(char **str);
t_data					*ft_print_lst(t_ls *ls, t_data *data_c, int *t);
void					ft_show_detail(t_ls *ls, char *path);
void					ft_print_model(t_ls *ls, t_data *data_c, int *t);
void					ft_print_time(t_data *data_c, int *t);
void					ft_sym_link(t_ls *ls, t_data *data_c);
void					ft_print_elem(char *print, char *c, int j, int t);
void					ft_hour_split(char **str, char **hour);
int						*ft_space_count(t_data *data_c);
int						ft_calc_space(int a, char *b);
void					ft_minor_major_space(t_data *data_c, int *tab_space);
void					ft_block_count(t_ls *ls, t_data *data_c);
void					ft_print_space_char(char i);
t_data					*ft_sort(t_ls *ls, t_data *data_c);
int						ft_strcmp_time(int s1, int s2);
t_data					*ft_reverse(t_data *data_c);
char					ft_is_in(char *str, char c);
char					*ft_strcat_ls(char *s1, const char *s2);
void					ft_color(mode_t mode);
int						ft_error(char *str);
void					ft_not_found_exit(char *str);
void					ft_show_help(void);

#endif
