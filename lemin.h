#ifndef LEMIN_H
#define LEMIN_H
# define BUFF_SIZE 1024
# define BLOCK 100000
# define F_BUFF_SIZE 500
# define F_MAX_FD 999
# define F_DELIMITER '\n'
# include "./libft/libft.h"

typedef struct		s_room
{
    char            *name;
    int             x;
    int             y;
    int             fl;
    int             lvl;
}                   t_room;

typedef struct      s_lem
{
    int             n;
	int				vld;
    int             start;
    int             end;
    int             ants;
    int             count_rooms;
    int             links;
}                   t_lem;

typedef struct      s_valid
{
    int             name;
    int             sp;
    int             hyp;
    int             count_x;
    int             count_y;
}                   t_valid;

typedef struct      s_path
{
    int             i;
    int             j;
    int             res;
    int             count_paths;
    int             **path;
}                   t_path;

void	ft_init(void *data, size_t size);
void	ft_leave(void);
void	ft_read_map(char ***map);

int		ft_validation(char **map, t_lem *lem);
int		ft_valid_sharp(char *map, t_lem *lem);
int		ft_valid_ants(char **map, t_lem *lem);

int		ft_valid_str(char *map);

void	ft_helper_1(char map_i, t_valid *val, int *i, int *fl);
void	ft_helper_2(t_valid *val, int *i, int *fl);
int		ft_helper_3(char *map, t_valid *val, int *i);
int		ft_helper_4(char *map, t_valid *val, int *i);
int		ft_helper_5(char *map, t_valid *val, int *i, int *fl);

void	ft_free_str(int **sets, int *path);
void	ft_free_map(char ***map);
void    ft_nul_fl(t_room **room, t_lem *lem);
int		ft_check_empty(int *tmp, t_lem *lem);
void	ft_add_neighbors(int **sets, t_room **room, int *tmp);
void	ft_del_left(int *tmp);
int		*ft_alloc_qu(int len);
void	ft_bfs2(int **sets, t_lem *lem, t_room **room, int *tmp);
void	ft_leave(void);
void	ft_initialization_lem(t_lem *lem);
void	ft_initialization_room(t_room *room);
void	ft_initialization_path(t_path *path);
int		ft_valid_str(char *map);
int		ft_valid_resh(char *map, t_lem *lem);
int		ft_valid_ants(char **map, t_lem *lem);
int		ft_validation(char **map, t_lem *lem);
void	ft_free_room(t_room ***room, int i);
t_room	**ft_allocate_memory(t_lem *lem);
void 	ft_write(char *map, t_room **room, int k);
char	**ft_allocate_matrix_char(int dim);
int		**ft_allocate_matrix_int(int dim);
void	ft_create_str(char *matrix, t_lem *lem, int ***tmp, int k);
void	ft_find(int ***tmp, int i, int j, int k);
int     ft_check_repeat(t_room **room, t_lem *lem);
int		ft_no_start_end(t_room **room, t_lem *lem);
t_room 	**ft_record(char **map, t_lem *lem);
// char	**ft_read_map();
int		ft_search_name(char **map, t_room **room, char end);
void	ft_write_links(char *map, t_room **room, int **set);
void	ft_count_iter(t_path *path, t_lem *lem);
void	ft_del_link(int **sets, int i, int j);
int     ft_units_present(int *str);
int		ft_next_link_2(int *str, t_lem *lem, t_room **room);
void	ft_block_link(int **sets, int i, int j);
void    ft_path_overwrite(int i, t_path *path);
int     ft_check_path_2(t_room **room, int **sets, t_lem *lem, t_path *path);
void	ft_free_path(int count, t_path **path, int i);
t_path	**ft_allocate_memory_path(int len, int count_rooms);
void	ft_unblock_all(int **sets);
void	ft_print_path(int *path);
int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, int **sets, int *tmp);
void	ft_unblock_link(int **sets, char sign);
void	ft_del_info_path(t_path *path, t_lem *lem);
int		choose_set_of_paths(t_path **path);
void	ft_clear_matrix_int(int **matrix, int len);
int		ft_all_paths(t_path **path, t_room **room, t_lem *lem, int **sets, int *first, int *temp);
void	ft_reverse_path(t_path *path);
void	ft_put_ants_in_path(t_lem *lem, t_path *path);
void	add_path_in_matrix(t_path *path, int index, int **matrix_res);
int		**ft_allocate_matrix_int_new(int x, int y);
int		**ft_create_res_matrix(t_lem *lem, t_path *path, int iter);
int     path_present(int *str, int ants);
void	ft_print_res(int **matrix_res, t_lem *lem, t_room **room, char **map);
int		**ft_make_sets(char **map, t_room **room, t_lem *lem);


# endif
