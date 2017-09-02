/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <sbogar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:26:15 by sbogar            #+#    #+#             */
/*   Updated: 2017/08/27 16:44:34 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define HARD_LINKS 0
# define USER 1
# define GROUP 2
# define SIZE 3
# define FILE_NAMES 4

# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdbool.h>
# include "../libft/ft_printf.h"

enum				e_ft_ls_flags
{
	CAP_R = 0b1,
	LOW_L = 0b10,
	LOW_A = 0b100,
	LOW_R = 0b1000,
	LOW_T = 0b10000,\

	ILLEGAL_OPTION = 1 << 30
};

typedef struct		s_files
{
	struct s_files	*next;
	struct s_files	*prev;
	struct s_files	*files;
	struct s_files	*contained;
	struct stat		stats;
	char			*path;
	char			*name;
}					t_files;

typedef struct		s_env
{
	unsigned int	flags;
	char			**args;
	t_files			*dirs;
	t_files			*files;
}					t_env;

int					populate_struct(int ac, char **av, t_env *env);
void				get_files(t_env *env, int last_flag_arg, int ac, char **av);
void				get_directory_contents(t_files *tbf,
									unsigned int f, char *p);
void				get_dir_info(t_files *new_dir,
									unsigned int flags, char *path);
t_files				*append_file(char *p_n, struct stat st,
									t_files *head);
void				append_directory(char *arg, struct stat st,
									t_files **to_affect);
void				loop_through_args(t_env *env, int arg_num,
									int ac, char **av);

int					by_time(t_files *first, t_files *second);
int					alphabetical(t_files *first, t_files *second);
int					get_next_res_node(t_files **g1, t_files **g2, t_files **res,
									int (*cmp)(t_files *f, t_files *s));
void				append_remainder(int iter, int g_s,
									t_files **res, t_files **tmp);
t_files				*handle_null_input(t_files *tmp, int g_s);

void				free_files_list(t_files *head, bool free_all);
void				print_out_list(t_env *env);
t_files				*sort_list(t_files *head, unsigned int flags);

void				print_selves(t_files *dir, t_files **tmp,
									unsigned int flags, int field_widths[5]);
void				print_dir(unsigned int flags, t_files *dir,
									bool *nl, char **args);
void				print_block_size(t_files *dir, unsigned int flags,
									char **args);
void				print_one(t_files *dir, unsigned int flags,
									int field_widths[5]);
bool				print_preceding_info(int print_multiple, unsigned int flags,
									t_files *dir, char **args);

char				*get_format_string(int field_widths[5]);
void				populate_permissions(char permissions[11], t_files *dir);
void				get_field_widths(t_files *head, int field_widths[5]);

void				long_format(t_files *dir, int field_widths[5], char p[11]);
void				instantiate_widths(int field_widths[5]);

bool				is_not_self(t_files *dir);
bool				is_hidden(t_files *dir);
bool				was_specified(t_files *dir, char **args);
bool				are_multiple_dirs(t_files *dir, char **args,
									unsigned int flags);

#endif
