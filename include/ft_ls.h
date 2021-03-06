/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:39:44 by mallard           #+#    #+#             */
/*   Updated: 2017/06/21 15:59:31 by mallard          ###   ########.fr       */
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

typedef struct	s_size
{
	int				user;
	int				group;
	int				size_file;
	int				link;
}				t_size;

typedef struct	s_dir
{
	char			*path;
	char			*first;
	char			**file;
	int				rank;
	struct s_dir	*next;
	struct s_dir	*prev;
}				t_dir;

t_dir			*dirnew(char *path, char **file, int rank);
void			diradd(t_dir **file, t_dir *new);
void			multi_option(char **tab, t_opt env, int i);
t_opt			rec_option(char *str);
void			option_add(t_opt env, char **tab, int size, int rank);
void			option_sort(t_opt env, t_dir *lst, int print, int size);
void			check_option(char *str, char *option);
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
void			dir_default(char **tab, t_opt env, t_dir **lst, int rank);
char			**opt_a(DIR *dir, char *str, t_opt env);
void			rev_sort(char **lst);
char			*info_file(struct stat buf, struct dirent *sd);
void			modification_sort(char *path, char **tab);
char			*tabtostr(char **tab);
void			ini_opt(t_opt *env);
void			add_space(char **tab);
void			startdir(t_dir **file);
void			opt_l(char *str, char **tab, t_opt env, int t);
char			**recursive_file(char *str, t_opt env, int size, int rank);
void			creation_sort(char *path, char **tab);
void			access_sort(char *path, char **tab);
void			status_sort(char *path, char **tab);
int				sizelst(t_dir **file);
void			option_print(t_opt env, t_dir *lst, int size, int i);
void			ft_default(char **tab, t_opt env, int size, int rank);
void			l_total(char *str, char **tab);
void			mode_file(char *str, struct stat buf);
int				check_mode(char *str, t_opt env);
char			**error(char *str);
char			**check_file(char **tab);
void			char_del(char **tab, int i);
void			dirfree_end(t_dir **lst);
void			tabdel(char **tab);
void			opt_d(t_opt env, char **tab, t_dir *lst, int size);
void			type_file(char *str, struct stat buf);
char			*info_time(t_opt env, struct stat buf);
void			print_space(char *str, int size, int free);
t_size			t_size_null(void);
t_size			ini_size(char **tab, char *str);
void			ini_user(struct stat buf, t_size *size);
void			print_l(char *str, t_opt env, t_size size, struct stat buf);
void			maj_min(dev_t dev);
void			print_multi_str(int i, int size, t_dir **lst, int file);
void			error_comp(char *str, char **tab, int *i);
void			print_rank(t_opt env, t_dir *lst, int size);
char			*path_sup(char *str);
char			*last_dir(char *path);
void			single_error(char *str);
int				if_dir(char *str);
int				check_tab(char **tab);
char			*check_lnk(char *str);
int				rec(char *str, DIR *dir);

#endif
