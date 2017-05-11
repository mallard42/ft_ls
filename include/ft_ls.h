/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:39:44 by mallard           #+#    #+#             */
/*   Updated: 2017/05/11 10:59:47 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include "../libft/include/libft.h"
# include <sys/stat.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <pwd.h>
# include <errno.h>
# include <sys/xattr.h>

# include <stdio.h>

typedef struct	s_opt
{
	int				opt_a;
	int				opt_maj_a;
	int				opt_d;
	int				opt_maj_r;
	int				opt_r;
	int				opt_t;
	int				opt_l;
	int				opt_maj_u;
	int				opt_u;
	int				opt_c;
}				t_opt;

typedef struct	s_dir
{
	char			*path;
	char			**file;
	struct s_dir	*next;
	struct s_dir	*prev;
}				t_dir;

t_dir			*dirnew(char *path, char **file);
void			diradd(t_dir **file, t_dir *new);
int				size_dir(char *str, int a);
void			multi_option(char **tab);
t_opt			rec_option(char *str);
void			option_add(t_opt env, char **tab);
void			option_sort(t_opt env, t_dir *lst, int print, char **tab);
void			check_option(char *str, char *option);
void			error_file(char *str);
void			error_mod(char *str);
void			error_option(char option);
char			**newtab(int size);
void			print_tab(char **tab);
char			**add_str_to_tab(char **tab, char *str);
int				tablen(char **tab);
char			**del_str_to_tab(char **tab, int j);
char			*double_path(char *s1, char *s2);
void			ft_single_path(char *s1, int i);
char			**maj_r(char **tab);
void			default_sort(char **file);
void			dir_default(char **tab, t_opt env, t_dir **lst);
char			**opt_a(DIR *dir, char *str, t_opt env);
void			rev_sort(char **lst);
char			*info_file(struct stat buf, struct dirent *sd);
void			modification_sort(char *path, char **tab);
char			*tabtostr(char **tab);
void			ini_opt(t_opt *env);
void			add_space(char **tab);
void			startdir(t_dir **file);
void			opt_l(char *str, char **tab, t_opt env, int t);
void			info_link(char *str, char **tab, char ***info);
char			**info_time(char *str, char **tab, t_opt env);
void			info_user(char *str, char **tab, char ***info);
void			recursive_file(char *str, t_opt env);
void			creation_sort(char *path, char **tab);
void			access_sort(char *path, char **tab);
void			status_sort(char *path, char **tab);
int				sizelst(t_dir **file);
void			option_print(t_opt env, t_dir *lst, int size, int i);
void			ft_default(char *str, t_opt env);
void			l_total(char *str, char **tab);
void			info_time_bonus(char *str, char **tab, t_opt env, char **tmp);
void			mode_file(char *str);
void			check_mode(char **tab);
void			error(char *str);
char			**check_file(char **tab);
void			char_del(char **tab, int i);
void			dirfree_end(t_dir **lst);
void			tabdel(char **tab);
void			opt_d(t_opt env, char **tab, t_dir *lst);

#endif
