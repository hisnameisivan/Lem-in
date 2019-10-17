/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:08:30 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 20:10:35 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define BUFF_SIZE 1024
# define BLOCK 100000
# include "./libft/libft.h"

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			fl;
	int			lvl;
}				t_room;

typedef struct	s_lem
{
	int			i;
	int			n;
	int			k;
	int			vld;
	int			start;
	int			end;
	int			ants;
	int			count_rooms;
	int			links;
	int			fl;
	int			**sets;
	int			*tmp;
	int			len;
	int			str;
	int			*qu;
}				t_lem;

typedef struct	s_valid
{
	int			name;
	int			sp;
	int			hyp;
	int			count_x;
	int			count_y;
}				t_valid;

typedef struct	s_path
{
	int			i;
	int			j;
	int			res;
	int			count_paths;
	int			**path;
}				t_path;

void			ft_init(void *data, size_t size);
void			ft_leave(void);
void			ft_read_map(char ***map, t_lem *lem);

int				ft_validation(char **map, t_lem *lem);
int				ft_valid_sharp(char *map, t_lem *lem);
int				ft_valid_ants(char **map, t_lem *lem);

int				ft_valid_str(char *map);

void			ft_helper_1(char map_i, t_valid *val, int *i, int *fl);
void			ft_helper_2(t_valid *val, int *i, int *fl);
int				ft_helper_3(char *map, t_valid *val, int *i);
int				ft_helper_4(char *map, t_valid *val, int *i);
int				ft_helper_5(char *map, t_valid *val, int *i, int *fl);

t_room			**ft_record(char **map, t_lem *lem);

void			ft_make_sets(char **map, t_room **room, t_lem *lem);

int				*ft_alloc_qu(int len, t_lem *lem);
t_room			**ft_alloc_rooms(t_lem *lem);
int				**ft_alloc_matrix(int x, int y);
t_path			**ft_alloc_path(int len, int count_rooms);

void			ft_free_rooms(t_room **room, t_lem *lem);
void			ft_free_sets(int **sets, t_lem *lem);
void			ft_free_res_matrix(int **matrix, int iter);
void			ft_free_map(char ***map);
void			ft_res(t_path **path, t_lem *lem, t_room **room, char **map);

void			ft_free_room(t_room ***room, int i);
void			ft_free_matrix(int ***matrix, int i);
void			ft_free_matrix_i(int **matrix, int len);
void			ft_free_path(int count, t_path **path, int i);

void			ft_print_map(char **map);
void			ft_print_res(int **matrix_res, t_lem *lem,
				t_room **room, char **map);
int				**ft_create_res_matrix(t_lem *lem, t_path *path, int iter);
int				path_present(int *str, int ants);
void			add_path_in_matrix(t_path *path, int index, int **matrix_res);

void			ft_put_ants_in_path(t_lem *lem, t_path *path);
void			ft_reverse_path(t_path *path);
void			ft_count_iter(t_path *path, t_lem *lem);
int				choose_set_of_paths(t_path **path);

void			ft_nul_fl(t_room **room, t_lem *lem);
int				ft_check_empty(int *tmp, t_lem *lem);
void			ft_add_neighbors(int **sets, t_room **room, int *tmp);
void			ft_del_left(int *tmp);
void			ft_bfs2(int **sets, t_lem *lem, t_room **room, int *tmp);

void			ft_block_link(int **sets, int i, int j);
void			ft_del_link(int **sets, int i, int j);
void			ft_del_info_path(t_path *path, t_lem *lem);
void			ft_all_flag(int *flag, t_lem *lem, t_path **path, int *i);
void			ft_unblock_all(int **sets);

void			ft_write(char *map, t_room **room, int k);
void			ft_find(int ***tmp, int i, int j, int k);
void			ft_create_str(char *matrix, t_lem *lem, int ***tmp, int k);
void			ft_unblock_link(int **sets, char sign);

int				ft_check_len_path(t_path *path);
void			ft_start_check_path(t_path *path, t_lem *lem);
void			ft_check_2(t_lem *lem, int **sets, t_path *path, t_room **room);
void			ft_check_3(t_lem *lem, int **sets, t_path *path);
int				ft_check_path_2(t_room **room, int **sets,
				t_lem *lem, t_path *path);

void			ft_path_overwrite(int i, t_path *path);
int				ft_check_1(int **sets, t_lem *lem, t_path *path);
int				ft_next_link_2(int *str, t_lem *lem, t_room **room);
int				ft_units_present(int *str);
int				*ft_first_path(t_path *path, t_room **room,
				t_lem *lem, int **sets);

void			ft_cycle(t_room **room, t_lem *lem, t_path **path, int *qu);
void			ft_apply_bfs(t_lem *lem, int *first, t_room **room, int *qu);
void			ft_all_start(t_lem *lem);
void			ft_all_paths(t_path **path, t_room **room, t_lem *lem, int *qu);

#endif
