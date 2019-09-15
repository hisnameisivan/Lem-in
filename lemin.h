#ifndef LEMIN_H
#define LEMIN_H
# define BUFF_SIZE 1024
# define BLOCK 100000
#include <stdio.h>
 // block сделать maxint или что-то в этом роде
 // нельзя умножать на -1 (ибо 0 и 1)
typedef struct      s_room
{
    char            *name;
    int             x;
    int             y;
    int             fl;
    int             lvl;
}                   t_room;

typedef struct      s_lem
{
    int             i;
    int             j;
    int             k;
    int             l;
    int             n;
    int             ants;
    int             count_rooms;
    int             start;
    int             end;
    int             len;
    int             debug;
}                   t_lem;

typedef struct      s_valid
{
    int             name;
    int             space;
    int             defice;
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

void    bfs(t_room **room);
void	ft_leave(void);
void	ft_initialization_lem(t_lem *lem);
void	ft_initialization_room(t_room *room);
void	ft_initialization_path(t_path *path);
void	ft_print_matrix(char **matrix, t_lem *lem);
void	ft_print_name_lvl(t_lem *lem, t_room **room); // Печатаем имя, level, count_rooms
void	ft_print_path_index(t_path *path); // Печатаем путь по индексу
void	ft_print_path_name(t_path *path, t_room **room); // Печатаем путь по имени
int		ft_valid_str(char *map);
int		ft_valid_resh(char *map, t_lem *lem);
int		ft_valid_ants(char **map, t_lem *lem);
int		ft_validation(char **map, t_lem *lem);
void	ft_free_room(t_room ***room, int i);
t_room	**ft_allocate_memory(t_lem *lem);
void 	ft_write(char *map, t_room **room, int k); // Записывает Name x y
char	**ft_allocate_matrix_char(int dim);
int		**ft_allocate_matrix_int(int dim);
void	ft_create_str(char *matrix, t_lem *lem, int ***tmp, int k);
void	ft_find(int ***tmp, int i, int j, int k);
int		ft_del_repeat(int ***tmp, int k);
int		**ft_count_levels(char **matrix, t_lem *lem, int **tmp);
t_room 	**ft_record(char **map, t_lem *lem);
char	**ft_read_map();
int		ft_search_name(char **map, t_room **room, char end);
// void	ft_write_links(char *map, t_room **room, char **matrix);
void	ft_write_lvl_in_room(t_room **room, int **tmp);
char	**ft_make_matrix(char **map, t_room **room, t_lem *lem);
void	ft_bfc(char **matrix, t_lem *lem, t_room **room, int **tmp);
void	ft_count_iter(t_path *path, t_lem *lem);
// void	ft_del_link(char **matrix, int i, int j);
void	ft_del_link(int **sets, int i, int j);
// int     ft_units_present(char *str);
int     ft_units_present(int *str);
// int		ft_next_link_2(char *matrix, t_lem *lem, t_room **room);
int		ft_next_link_2(int *str, t_lem *lem, t_room **room);
void	ft_block_link(int **set, int i, int j);
// void	ft_block_link(char **matrix, int i, int j);
void    ft_path_overwrite(int i, t_path *path);
// int     ft_check_path_2(t_room **room, char **matrix, t_lem *lem, t_path *path);
int     ft_check_path_2(t_room **room, int **matrix, t_lem *lem, t_path *path);
void	ft_free_path(t_path ***path, int i);
t_path	**ft_allocate_memory_path(int len, int count_rooms);
// void	ft_free_str(char **matrix, int *path);
void	ft_free_str(int **sets, int *path);
void	ft_free_matrix(char ***matrix);
// void	ft_unblock_all(char **matrix);
void	ft_unblock_all(int **sets);
// int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, char **matrix, int *tmp);
int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, int **sets, int *tmp);
// void	ft_unblock_link(char **matrix, char num);
void	ft_unblock_link(int **matrix, char num);
void	ft_del_info_path(t_path *path, t_lem *lem);
int		choose_set_of_paths(t_path **path);
void	ft_clear_matrix_int(int **matrix, int len);
void	ft_clear_lvl(t_room **room, t_lem *lem);
int		ft_all_paths(t_path **path, t_room **room, t_lem *lem, int **sets, int *first, int *tmp);
void	ft_reverse_path(t_path *path);
void	ft_put_ants_in_path(t_lem *lem, t_path *path);
void	add_path_in_matrix(t_path *path, int index, int **matrix_res);
int		**ft_allocate_matrix_int_new(int x, int y);
// int		**ft_create_res_matrix(t_lem *lem, t_path *path);
int     path_present(int *str, int ants);
void	ft_print_res(int **matrix_res, t_lem *lem, t_room **room);
void	ft_print_path(int *path);




# endif
