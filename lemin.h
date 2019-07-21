#ifndef LEMIN_H
#define LEMIN_H
# define BUFF_SIZE 1024

typedef struct      s_room
{
    char            *name;
    int             empty_fl;
    int             x;
    int             y;
    int             fl;
    int             lvl;
    struct s_room   **links; // массив, содержащий сслыки на связные элементы
    // struct  s_room   *next;
}                   t_room;

typedef struct      s_lem
{
    int             i;
    int             j; /* убрать */
    int             k;
    int             l;
    int             n;
    int             ants;
    int             count_rooms;
    int             start;
    int             end;
    int             len;
    //int             max;
    //int             i_path;
    //int             j_path;
    //int             fl;
    //int             fl1;
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
    int             **path;
    int             count_paths;
    //struct  s_path  *next;
}                   t_path;

typedef struct      s_res
{
    int             i;
    int             j;
    int             res;
    int             **path;
    int             count_paths;
    //struct  s_path  *next;
}                   t_res;

char	**ft_read_map();
int		ft_validation(char **map, t_lem *lem);
int		ft_valid_str(char *map);
int		ft_valid_resh(char *map, t_lem *lem);
void	ft_initialization_lem(t_lem *lem);
void	ft_leave(void);
void	ft_free(t_room ***room, int i);
void 	ft_write(char *map, t_room **room, int k);
t_room	**ft_record(char **map, t_lem *lem);
void	ft_write_lvl_in_room(t_room **room, int **tmp);


# endif
