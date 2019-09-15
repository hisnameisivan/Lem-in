/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:24:10 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/15 23:55:27 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>
# include "./libft/libft.h"

void	ft_nul_fl(t_room **room, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		room[i]->fl = 0;
		room[i]->lvl = 0;
		i++;
	}
}

/*
** Проверяем, что очередь непустая. 1 - есть элементы в очереди, 0 - нет
*/

int		ft_check_empty(int *tmp, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		if (tmp[i] != -1)
			return (1);
		i++;
	}
	return (0);
}

/*
** второе И наша 9
*/

void	ft_add_neighbors(int **sets, t_room **room, int *tmp)
{
	int i;
	int j;
	int k;
	int lvl;

	j = 0;
	k = 0;
	while (tmp[k] == -1)
		k++;
	i = tmp[k];
	lvl = room[i]->lvl + 1;
	while (tmp[k] != -1)
		k++;
	while (sets[i][j] != -1)
	{
		if (sets[i][j] >= 0 && sets[i][j] < BLOCK && room[sets[i][j]]->fl == 0)
		{
			room[sets[i][j]]->fl = 1;
			tmp[k] = sets[i][j];
			room[tmp[k]]->lvl = lvl;
			ft_block_link(sets, i, j);
			k++;
		}
		j++;
	}
}

void	ft_del_left(int *tmp)
{
	int i;

	i = 0;
	while (tmp[i] == -1)
		i++;
	tmp[i] = -1;
}

int		*ft_alloc_qu(int len)
{
	int *tmp;

	tmp = (int *)malloc(sizeof(int) * len);
	ft_memset(tmp, -1, len * 4);
	return (tmp);
}

void	ft_bfs2(int **sets, t_lem *lem, t_room **room, int *tmp)
{
	int i;

	i = 0;
	tmp[0] = 0;
	while (ft_check_empty(tmp, lem) != 0)
	{
		ft_add_neighbors(sets, room, tmp);
		ft_del_left(tmp);
		i++;
	}
}

// Удаление тупиков
// void	ft_del(char **matrix, int i)
// {
// 	int j = 0;

// 	while (matrix[i][j] != '\0')
// 	{
// 		if (matrix[i][j] == '1')
// 		{
// 			matrix[i][j] = '0';
// 			matrix[j][i] = '0';
// 			printf("Удалили тупик\n");
// 		}
// 		j++;
// 	}

// }

// void	ft_check_no_path(char **matrix)
// {
// 	int i;
// 	int j;
// 	int	count_units = 0;
// 	int fl;

// 	while (1)
// 	{
// 		fl = 0;
// 		i = 0;
// 		while (matrix[i] != NULL)
// 		{
// 			j = 0;
// 			count_units = 0;
// 			while (matrix[i][j] != '\0')
// 			{
// 				if(matrix[i][j] == '1')
// 					count_units++;
// 				j++;
// 			}
// 			if (count_units == 1)
// 			{
// 				fl = 1;
// 				ft_del(matrix, i);
// 			}
// 			i++;

// 		}
// 		if (fl == 0)
// 		{
// 			break ;
// 		}
// 	}
// }

/*
** Количество уже имеющихся в массиве соседних с текущим звеном графа звеньев.
*/

// int		ft_count_nodes(t_room **room)
// {
// 	int		len;

// 	len = 0;
// 	while (*room != NULL)
// 	{
// 		room++;
// 		len++;
// 	}
// 	return (len);
// }


void	ft_leave(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	ft_initialization_lem(t_lem *lem)
{
	ft_bzero(lem, sizeof(t_lem));
}

void	ft_initialization_room(t_room *room)
{
	ft_bzero(room, sizeof(t_room));
}

void	ft_initialization_path(t_path *path)
{
	ft_bzero(path, sizeof(t_path));
}

// Печатаем матрицу смежности
// void	ft_print_matrix(char **matrix, t_lem *lem)
// {
// 	int i;

// 	i = 0;
// 	while (i < lem->count_rooms)
// 	{
// 		printf("%s\n", matrix[i]);
// 		i++;
// 	}
// 	printf("\n\n");
// }

// Печатаем имя, level, count_rooms
// void	ft_print_name_lvl(t_lem *lem, t_room **room)
// {
// 	int i;

// 	i = 0;
// 	printf("\nCOUNT_ROOMS = %d\n", lem->count_rooms);
// 	printf("\nCOUNT_ANTS = %d\n", lem->ants);
// 	while (i < lem->count_rooms)
// 	{
// 		printf("name = %s, lvl = %d\n", room[i]->name, room[i]->lvl);
// 		i++;
// 	}
// }

// Печатаем путь по индексу
// void		ft_print_path_index(t_path *path)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (path->path[i][0] >= 0)
// 	{
// 		j = 0;
// 		while (path->path[i][j] >= 0)
// 		{
// 			printf("path %d:  %d \n", i, path->path[i][j]);
// 			j++;
// 		}
// 		printf("\nLEN_PATH = %d \n", j - 1);
// 		printf("\n");
// 		i++;
// 	}
// }

// Печатаем путь по имени
// void		ft_print_path_name(t_path *path, t_room **room)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	if (path->path[0][0] == -1)
// 	{
// 		printf("Пустой набор путей\n"); /* ПРОВЕРКА УБРАТЬ */
// 		return ;
// 	}
// 	while (path->path[i][0] >= 0)
// 	{
// 		j = 0;
// 		while (path->path[i][j] >= 0)
// 		{
// 			printf("path %d:  %s \n", i, room[path->path[i][j]]->name);
// 			j++;
// 		}
// 		printf("\nLEN_PATH = %d \n", j);
// 		printf("\n");
// 		i++;
// 	}
// }

int		ft_valid_str(char *map)
{
	int		i;
	int		fl;
	t_valid	val;

	i = 0;
	fl = 0;

	val.name = 0;
	val.count_x = 0;
	val.count_y = 0;
	val.defice = 0;
	val.space = 0;
	if (map[0] == 'L')
		return (0);
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '-')
		{
			map[i] == ' ' ? val.space++ : val.defice++;
			fl = 0;
			i++;
		}
		else if ((map[i] != ' ' && fl == 0 && val.name < 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != '-' && fl == 0 && val.name < 2 && val.defice == 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 1) /* для валидации координаты x */
		{
			while(map[i] != ' ')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else if (map[i] == '\0' || ft_isdigit(map[i]) == 0)
					return (0);
			}
			val.count_x++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 2)
		{
			while(map[i] != '\0')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else
					return (0);
			}
			val.count_y++;
		}
		else if (val.name == 1 && fl == 0 && (map[i] != ' ' && map[i] != '-') && val.defice == 1) /* валидируем name2 */
		{
			if (map[i] == '#' || map[i] == 'L')
				return (0);
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 1) /* находимся в name */
			i++;
		else
		    return (0);
	}
	if (val.space == 2 && val.name == 1 && val.count_x == 1 && val.count_y == 1)
		return (4);
	else if (val.defice == 1 && val.name == 2)
		return (5);
	else
		return (0);
}

int		ft_valid_resh(char *map, t_lem *lem) /* проверяем start, end и comment*/
{
	int i;

	i = 0;
	if (ft_strcmp(map, "##start") == 0)
	{
		lem->start++;
		return (1);
	}
	else if (ft_strcmp(map, "##end") == 0)
	{
		lem->end++;
		return (2);
	}
	else if (map[0] == '#' && map[1] != '\0')
	{
		//if (map[1] != '#')
			return (3);
	}
	return (0);
}

int		ft_valid_ants(char **map, t_lem *lem)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0] == '#')
		i++;
	if (map[i][0] >= '1' && map[i][0] <= '9')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_isdigit(map[i][j]) == 1)
				j++;
			else
			{
				printf("not valid ants\n"); /* ПРОВЕРКА УБРАТЬ */
				ft_leave();
			}
		}
		lem->ants = ft_atoi(map[i]);
		i++;
		return (i);
	}
	else
	{
		ft_leave();
		return (0);
	}
}

int		ft_validation(char **map, t_lem *lem)
{
	int i;
	int	valid_resh;

	i = ft_valid_ants(map, lem);
	while (map[i])
	{
		if (map[i][0] == '#')
		{
			valid_resh = ft_valid_resh(map[i], lem);
			if (((valid_resh == 1 || valid_resh == 2) && (map[i + 1] != NULL)
			&& (ft_valid_str(map[i + 1]) == 4)) || valid_resh == 3) /* проверяем что после start или end идет строка с координатами комнаты (4) */
				i++;
			else
			{
				printf("2\n");
				ft_leave();
			}
		}
		else if (ft_valid_str(map[i]) == 4)
		{
			lem->count_rooms++;
			i++;
		}
		else if (ft_valid_str(map[i]) == 5)
			i++;
		else
		{
			printf("3\n");
			ft_leave();
		}
	}
	if (lem->start == 1 && lem->end == 1)
		return (1);
	else
		return (0);
}

void	ft_free_room(t_room ***room, int i)
{
	while (--i >= 0)
	{
		free((*room)[i]);
		(*room)[i] = NULL;
	}
	free(*room);
	*room = NULL;
}

t_room	**ft_allocate_memory(t_lem *lem)
{
	int		i;
	t_room	**room;

	i = 0;
	if (!(room = (t_room**)malloc(sizeof(t_room*) * (lem->count_rooms + 1))))
		ft_leave();
	while (i < lem->count_rooms)
	{
		if (!(room[i] = (t_room *)malloc(sizeof(t_room))))
		{
			ft_free_room(&room, i);
			return (NULL);
		}
		ft_initialization_room(room[i]);
		i++;
	}
	return (room);
}

// Записывает Name x y
void 	ft_write(char *map, t_room **room, int k)
{
    int co;

    co = 0;
    while (map[co] != ' ')
        co++;
    room[k]->name = ft_strnew(co);
    ft_strncpy(room[k]->name, map, co);
    room[k]->x = ft_atoi(&map[co]);
    co++;
    while (map[co] != ' ')
        co++;
    room[k]->y = ft_atoi(&map[co]);
}

char	**ft_allocate_matrix_char(int dim)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = NULL;
	matrix = (char **)malloc(sizeof(char *) * (dim + 1));
	while (i < dim)
	{
		matrix[i] = ft_strnew(dim);
		ft_memset(matrix[i], '0', dim);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int		**ft_allocate_matrix_int(int dim)
{
	int		i;
	int		**matrix;

	i = 0;
	dim++; // 15.09
	matrix = (int **)malloc(sizeof(int *) * dim);
	while (i < dim)
	{
		matrix[i] = (int *)malloc(sizeof(int) * dim); // 02.09 удалил дополнительное умножение на dim
		ft_memset(matrix[i], -1, dim * 4);
		i++;
	}
	return (matrix);
}

void	ft_create_str(char *matrix, t_lem *lem, int ***tmp, int k)
{
	int j;

	j = 0;
	while (matrix[j])
	{
		if (matrix[j] == '1')
		{
			(*tmp)[k + 1][lem->n] = j;
			lem->n++;
		}
		j++;
	}
}

void	ft_find(int ***tmp, int i, int j, int k)
{
	int		l;
	int		m;
	int		num;

	l = 0;
	num = (*tmp)[i][j];
	while (l < k + 1)
	{
		m = 0;
		while ((*tmp)[l][m] >= 0)
		{
			if (((*tmp)[l][m] == num) && !(i == l && j == m))
			{
				while ((*tmp)[l][m] >= 0)
				{
					(*tmp)[l][m] = (*tmp)[l][m + 1];
					m++;
				}
				m = 0;
			}
			m++;
		}
		l++;
	}
}

int		ft_del_repeat(int ***tmp, int k) /* возвращает длину последней строки */
{
	int		i;
	int		j;

	i = 0;
	while (i < k + 1)
	{
		j = 0;
		while ((*tmp)[i][j] >= 0)
		{
			ft_find(tmp, i, j, k);
			j++;
		}
		i++;
	}
	j = 0;
	i--;
	while ((*tmp)[i][j] >= 0)
		j++;
	return (j); /* если не зашли в while => строка пустая (все удалили), в противном случае человеческая длина (+1) */
}

int		**ft_count_levels(char **matrix, t_lem *lem, int **tmp)
{
	int		k;
	int		l;
	//int		**tmp; /* списки смежности */

	lem->len = 1; /* {0} - 1 элемент */
	k = 0;
	//tmp = ft_allocate_matrix_int(lem->count_rooms);
	tmp[0][0] = 0;
	while (lem->len)
	{
		l = 0;
		while (lem->len)
		{
			ft_create_str(matrix[tmp[k][l]], lem, &tmp, k);
			l++;
			lem->len--;
		}
		k++;
		lem->len = ft_del_repeat(&tmp, k); /* возвращает длину последней строчки */
		lem->n = 0;
	}
	lem->n = 0; /* для последующего использования */
	return (tmp);
}

t_room 	**ft_record(char **map, t_lem *lem) /* записываем name и координаты (без связей) */
{
	int			i;
	int			k;
	int			valid_resh;
	t_room		**room;

	i = 0; /* 0 строка - это кол-во муравьев - ИСПРАВИТЬ! - там может быть коммент */
	k = 1; /* индекс для массива структур room */
	room = ft_allocate_memory(lem);
	while (map[i])
	{
		valid_resh = ft_valid_resh(map[i], lem);
		// if (map[i][0] == '#' && valid_resh == 3)
		// 	/*i++*/;
		if (map[i][0] == '#' && valid_resh == 1)
		{
			i++;
		    ft_write(map[i], room, 0); /* записать старт на 0 место */
		}
		else if ((map[i][0] == '#' && valid_resh == 2))
		{
			i++;
			ft_write(map[i], room, lem->count_rooms - 1); /*записать end на *room[lem->count_rooms - 1] */
		}
		else if (ft_valid_str(map[i]) == 4)
		{
			ft_write(map[i], room, k);
            k++;
		}
		i++;
	}
	return (room);
}

char	**ft_read_map()
{
	int		ret;
    char	buff[BUFF_SIZE + 1];
	char	*del;
	char	*temp;
	int 	fl;
	char	**map;

	fl = 0;
	temp = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		del = temp;
		temp = ft_strjoin(temp, buff);
		free(del);
		fl = 1;
	}
	if (fl == 0)
		exit(0); /* если пустая карта */
	map = ft_strsplit(temp, '\n');
	return (map);
}

int		ft_search_name(char **map, t_room **room, char end)
{
	int		len_name;
	int		index;
	char	*name;
	char	*temp;

	len_name = 0;
	index = 0;
	temp = *map;
	name = NULL;
	while (**map != end)
	{
		(*map)++;
		len_name++;
	}
	name = ft_strnew(len_name);
	ft_strncpy(name, temp, len_name);
	while (room[index])
	{
		if (ft_strcmp(name, room[index]->name) == 0)
			break ;
		index++;
	}
	return (index);
}

// Записываем линки между комнатами на соответствующие позиции матрицы смежности
void	ft_write_links(char *map, t_room **room, int **set)
// void	ft_write_links(char *map, t_room **room, char **matrix)
{
	int		name1_ind;
	int		name2_ind;
	int		i;

	name1_ind = ft_search_name(&map, room, '-');
	map++;
	name2_ind = ft_search_name(&map, room, '\0');
	// matrix[name1_ind][name2_ind] = '1';
	// matrix[name2_ind][name1_ind] = '1';
	i = 0;
	while (set[name1_ind][i] != -1)
		i++;
	set[name1_ind][i] = name2_ind;
	i = 0;
	while (set[name2_ind][i] != -1)
		i++;
	set[name2_ind][i] = name1_ind;
}

// Функция записывает в каждую комнату level, который получили в результате bfc обхода

void	ft_write_lvl_in_room(t_room **room, int **tmp)
{
	int i;
	int k;
	int index;

	i = 0;
	while (tmp[i][0] >= 0) /* в пустой строке на 0 месте находится -1 */
	{
		k = 0;
		while (tmp[i][k] >= 0)
		{
			index = tmp[i][k];
			room[index]->lvl = i;
			k++;
		}
		i++;
	}
}

/* Функция создает матрицу смежности */
// char	**ft_make_matrix(char **map, t_room **room, t_lem *lem)
// {
// 	int		i;
// 	char	**matrix;

// 	i = 0;
// 	matrix = ft_allocate_matrix_char(lem->count_rooms);
// 	while (map[i])
// 	{
// 		if (ft_valid_str(map[i]) == 5)
// 			ft_write_links(map[i], room, matrix);
// 		i++;
// 	}
// 	return (matrix);
// }

void	ft_bfc(char **matrix, t_lem *lem, t_room **room, int **tmp)
{
	tmp = ft_count_levels(matrix, lem, tmp);
	ft_write_lvl_in_room(room, tmp);
}

/* Функция считает кол-во итераций для каждого набора из путей и записывает в res.
Исходя их наименьшего 'res' затем выберем лучший набор путей.
Считаем res по формуле:
Кол-во итераций = (кол-во шагов по всем путям + (кол-во муравьев - кол-во путей))/кол-во путей */

void	ft_count_iter(t_path *path, t_lem *lem) /* кол-во строк = кол-ву путей, кол-во символов в строке - 1 = кол-во шагов в пути */
{
	int i;
	int j;
	int count_iter;
	int	count_steps;
	int	count_paths;

	i = 0;
	j = 0;
	count_iter = 0;
	count_steps = 0;
	count_paths = 0;
	if (path->path[0][0] == -1) /* защита */
		return ;
	while (path->path[i][0] >= 0)
	{
		j = 0;
		//count_steps--;
		while (path->path[i][j] >= 0)
		{
			count_steps++;
			j++;
		}
		count_paths++;
		i++;
	}
	count_steps = count_steps - count_paths;
	path->res = ((count_steps + (lem->ants - count_paths)) / count_paths);
	path->count_paths = count_paths;
	//printf("COUNT_ITER = %d\n\n", path->res);
}

// void	ft_del_link(char **matrix, int i, int j)
// {
// 	matrix[i][j] = '9';
// 	matrix[j][i] = '9';
// }

void	ft_del_link(int **sets, int i, int j)
{
	int		k;

	k = 0;
	while (sets[i][k] != j)
	{
		if (sets[i][k] == -1)
			return;
		k++;
	}
	sets[i][k] = j + BLOCK;
	// sets[j][i] = '7';
	k = 0;
	while (sets[j][k] != i)
	{
		if (sets[j][k] == -1)
			return;
		k++;
	}
	sets[j][k] = sets[j][k] + BLOCK;
}

// int ft_units_present(char *str) // наличие связей у вершины
// {
//     int i;

//     i = 0;
//     while (str[i] != '\0')
//     {
//         if (str[i] == '1')
//             return(1);
//         else
//             i++;
//     }
//     return (0);
// }

int ft_units_present(int *str) // наличие связей у вершины
{
    int i;

    i = 0;
    while (str[i] != -1)
    {
        if (str[i] >= 0 && str[i] < BLOCK / 2) // просто BLOCK
            return(1);
        else
            i++;
    }
    return (0);
}

int		ft_next_link_2(int *str, t_lem *lem, t_room **room)
{
	int j;
	int tmp;
	int lvl;
	int fl;

	j = 0;
	fl = 0;
	lem->count_rooms = lem->count_rooms;
	while (str[j] != -1)
	{
		if (str[j] >= 0  && str[j] <= BLOCK / 2 /*&& j != lem->count_rooms - 1*/)
		{
			if (fl == 0) /* записываем первую встретившуюся вершину, не смотря на левел */
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
				fl = 1;
			}
			else if (fl == 1 && (room[str[j]]->lvl) < lvl)
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
			}
		}
		j++;
	}
	return (tmp);
}

// void		ft_block_link(char **matrix, int i, int j) /* временно заблокированную связь помечаем '7' */
// {
// 	matrix[i][j] = '7';
// 	matrix[j][i] = '7';
// }
void		ft_block_link(int **sets, int i, int j) /* временно заблокированную связь помечаем '7' */
{
	int		tmp;
	int		k;

	tmp = sets[i][j];
	k = 0;
	sets[i][j] = sets[i][j] - BLOCK;
	// sets[j][i] = '7';
	while (sets[tmp][k] != i)
	{
		if (sets[tmp][k] == -1)
			return;
		k++;
	}
	sets[tmp][k] = sets[tmp][k] - BLOCK;
}

// 02.09 удаление из набора очень длинного пути
void ft_path_overwrite(int i, t_path *path)
{
	int j;
	j = 0;
	while (path->path[i][j] > -1)
	{
		path->path[i][j] = -1;
		j++;
	}
}

int ft_check_path_2(t_room **room, int **sets, t_lem *lem, t_path *path)
{
    int str;

    path->j = 0;
    str = lem->count_rooms - 1;
    path->path[path->i][path->j] = str;
    path->j++;
	if (ft_units_present(sets[0]) == 0 || ft_units_present(sets[lem->count_rooms - 1]) == 0)
	{
		path->path[path->i][0] = -1;
		return (0); // мб в функцию, которая вызывает ft_check_path_2 добавить флаг, чтобы не было бесконечного цикла
	}
    while (str != 0) /* выполняем пока не пришли в строку start */
    {
		//ft_print_path(path->path[path->i]);
		if (path->j > 100) // 02.09 заглушка на длиннющий путь
		{
			ft_path_overwrite(path->i, path);
			path->i--;
			return (1);
		}
		// if (path->i > 10) // 02.09 заглушка на количество путей
		// {
		// 	// ft_path_overwrite(path->i, path);
		// 	// path->i--;
		// 	return (0);
		// }
		if (ft_units_present(sets[str]) == 1)
		{
			str = ft_next_link_2(sets[str], lem, room);
			path->path[path->i][path->j] = str;
			ft_del_link(sets, path->path[path->i][path->j - 1], path->path[path->i][path->j]);
			path->j++;
			continue ;
		}
		else
		{
			if (str == lem->count_rooms - 1)
			{
				path->path[path->i][0] = -1;
				return (0);
			}
			else
			{
				path->j--;
				str = path->path[path->i][path->j];
				path->path[path->i][path->j + 1] = -1;
				if (ft_units_present(sets[str]) == 1)
				{
					path->j++;
				}
			}
		}
    }
    return (1);
}

void	ft_free_path(t_path ***path, int i)
{
	while (--i >= 0)
	{
		free((*path)[i]);
		(*path)[i] = NULL;
	}
	free(*path);
	*path = NULL;
}

t_path		**ft_allocate_memory_path(int len, int count_rooms)
{
	int		i;
	t_path	**path;

	i = 0;
	if (!(path = (t_path**)malloc(sizeof(t_path*) * (len + 1)))) // было без +1
		ft_leave();
	while (i < len)
	{
		if (!(path[i] = (t_path*)malloc(sizeof(t_path))))
		{
			ft_free_path(&path, i);
			return (NULL);
		}
		ft_initialization_path(path[i]);
		path[i]->path = ft_allocate_matrix_int(count_rooms);
		i++;
	}
	path[i] = NULL;
	return (path);
}

// Заменяем в матрице '1' на '9'
void		ft_free_str(int **sets, int *path)
{
	int	i;
	int j;
	int tmp;

	i = 1; /* берем из пути индексы (начиная с 1го чтобы не занулять строку end и зануляем соответствующие строки матрицы смежности*/
	while (path[i] != 0)
	{
		tmp = path[i];
		j = 0;
		while (sets[tmp][j] != -1)
		{
			if (sets[tmp][j] >= 0 && sets[tmp][j] < BLOCK / 2)
			{
				sets[tmp][j] = sets[tmp][j] + BLOCK;
			}
			j++;
		}
		i++;
	}
}

void	ft_free_matrix(char ***matrix)
{
	int i;

	i = 0;
	while ((*matrix)[i] != NULL)
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

// void		ft_unblock_all(char **matrix)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (matrix[i] != NULL)
// 	{
// 		j = 0;
// 		while (matrix[i][j] != '\0')
// 		{
// 			if (matrix[i][j] == '7' || matrix[i][j] == '9')
// 				matrix[i][j] = '1';
// 			j++;
// 		}
// 		i++;
// 	}
// }

void		ft_unblock_all(int **sets)
{
	int i;
	int j;

	i = 0;
	while (sets[i][0] != -1)
	{
		j = 0;
		while (sets[i][j] != -1)
		{
			if (sets[i][j] < -BLOCK / 2) // заменить BLOCK / 2 на -1
				sets[i][j] = sets[i][j] + BLOCK;
			j++;
		}
		i++;
	}
}

void	ft_print_path(int *path)
{
	int i = 0;

	while (path[i] > -1)
	{
		printf("%d ", path[i]);
		i++;
	}
	printf("\n");
}

// Функция записывает первый набор путей
int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, int **sets, int *tmp)
{
	path->i = -1;
	while (1)
	{
		path->i++;
		path->j = 0;
		if (ft_check_path_2(room, sets, lem, path) == 0)
			break ;
		else
			ft_free_str(sets, path->path[path->i]); /* блокируем пути '9' */
		//printf("Путь %d\n", path->i);
		//ft_print_path(path->path[path->i]);
		//printf("\n\n");
		ft_nul_fl(room, lem);
		ft_bfs2(sets, lem, room, tmp);
		ft_unblock_link(sets, '7');
	}
	ft_count_iter(path, lem);
	ft_unblock_all(sets);
	return (path->path[0]);
}

// // Заменяем либо '7', либо '9' на '1'
// void		ft_unblock_link(char **matrix, char num)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (matrix[i] != NULL)
// 	{
// 		j = 0;
// 		while (matrix[i][j] != '\0')
// 		{
// 			if (matrix[i][j] == num)
// 				matrix[i][j] = '1';
// 			j++;
// 		}
// 		i++;
// 	}
// }

// вернуться к ней
void		ft_unblock_link(int **sets, char sign)
{
	int i;
	int j;

	i = 0;
	while (sets[i][0] != -1)
	{
		j = 0;
		while (sets[i][j] != -1)
		{
			if (sets[i][j] < -BLOCK / 2 && sign == '7')
				sets[i][j] = sets[i][j] + BLOCK;
			else if (sets[i][j] > BLOCK && sign == '9')
				sets[i][j] = sets[i][j] - BLOCK;
			j++;
		}
		i++;
	}
}

// Зануление структуры t_path
void		ft_del_info_path(t_path *path, t_lem *lem)
{
	int i;

	i = 0;
	path->i = 0;
	path->j = 0;
	path->count_paths = 0;
	path->res = 0;
	while (i < lem->count_rooms)
	{
		ft_memset(path->path[i], -1, lem->count_rooms * 4);
		i++;
	}

}

int			choose_set_of_paths(t_path **path)
{
	int tmp;

	tmp = ((path[0]->res) > (path[1]->res) && (path[1]->res != 0) ? 1 : 0);
	tmp = (tmp > (path[2]->res) && (path[2]->res != 0) ? 2 : tmp);
	return (tmp);
}

// Устанавливаем на все позиции матрицы "-1"
void		ft_clear_matrix_int(int **matrix, int len)
{
	int i = 0;

	while (i < len)
	{
		ft_memset(matrix[i], -1, len * 4);
		i++;
	}
}

int		ft_all_paths(t_path **path, t_room **room, t_lem *lem, int **sets, int *first, int *temp)
{
	int		i;
	int		k;
	int		len;
	int		flag;

	i = 1;
	k = 1;
	len = 0;
	flag = 0;

	while (first[len] >= 0)
		len++;
	len = len - 3; /* кол-во ребер, которое будем удалять = (кол-во вершин - 1) и еще (- 2) (т.к. не удаляем ребра у start и end) */
	while (len)
	{
		path[k]->i = 0;

		//ft_block_link(matrix, first[i], first[i + 1]);
		ft_del_link(sets, first[i], first[i + 1]);
		ft_nul_fl(room, lem);
		ft_bfs2(sets, lem, room, temp);
		ft_unblock_link(sets, '7');
		if (ft_check_path_2(room, sets, lem, path[k]) == 0)
		{
			ft_unblock_link(sets, '7');
			i++;
			len--;
			continue ;
		}

		while (1)
		{
			ft_nul_fl(room, lem);
			ft_bfs2(sets, lem, room, temp);
			ft_unblock_link(sets, '7');
			path[k]->i++;
			path[k]->j = 0;
			if (ft_check_path_2(room, sets, lem, path[k]) == 0)
				break ;
			else
				ft_free_str(sets, path[k]->path[path[k]->i]); /* заменяем "1" на "9" */
		}
		ft_count_iter(path[k], lem);
		if (flag == 1 && (len - 1))
		{
			k = (path[1]->res > path[2]->res ? 1 : 2);
			ft_del_info_path(path[k], lem); /* только зануляем информацию (не фришим) чтобы перезаписывать поверх */
		}
		if (flag == 0)
		{
			flag = 1;
			k++;
		}
		len--;
		i++;
		ft_unblock_all(sets);
	}
	k = choose_set_of_paths(path);
	return(k);
}

// Функция записывает путь в правильном порядке (от start к end), т.к. изначально путь хранится наоборот
// На нулевом месте хранится длина пути
void		ft_reverse_path(t_path *path)
{
	int i;
	int j;
	int k;
	int tmp;

	i = 0;
	k = 0;
	j = 0;
	while (path->path[k][0] >= 0)
	{
		while (path->path[k][j] >= 0)
				j++;
		path->path[k][j] = j;
		//j--;
		while (i < j)
		{
			tmp = path->path[k][i];
			path->path[k][i] = path->path[k][j];
			path->path[k][j] = tmp;
			i++;
			j--;
		}
		k++;
		i = 0;
		j = 0;
	}
}


// В каждый путь кладем количество муравьев, которые пойдут по этому пути
// path->path[i][0] хранится len массива
// path->path[i][1] хранится кол-во муравьев
void		ft_put_ants_in_path(t_lem *lem, t_path *path)
{
	int		i;
	int 	sum;
	int		ants;

	sum = 0;
	ants = lem->ants;
	while (ants > 0)
	{
		i = 0;
		while (path->path[i][0] != -1)
		{
			if (sum > path->path[i][0] + path->path[i][1])
			{
				path->path[i][1]++;
				ants--;
				if (ants == 0)
					break ;
			}
			i++;
		}
		sum++;
	}
}

void		add_path_in_matrix(t_path *path, int index, int **matrix_res)
{
	int i;
	int j;

	i = path->i; // смещение вниз по столбцу матрицы
	j = 2; // смещение влево по пути, начинаем с 2х т к на 0м месте len, на 1м количество муравьев
	while (path->path[index][j] > 0)
	{
		matrix_res[i][path->j] = path->path[index][j];
		i++;
		j++;
	}
}


// Создает несимметричную int матрицу и заполняет ее "-1"
// x длина, y высота

int		**ft_allocate_matrix_int_new(int x, int y)
{
	int		i;
	int		**matrix;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * y);
	while (i < y)
	{
		matrix[i] = (int *)malloc(sizeof(int) * x);
		ft_memset(matrix[i], -1, x * 4);
		i++;
	}
	return (matrix);
}

int		**ft_create_res_matrix(t_lem *lem, t_path *path, int iter)
{
	int	i;
	int	**matrix_res;
	int ants;

	i = 0;
	path->i = 0;
	path->j = 0;
	ants = lem->ants;
	matrix_res = ft_allocate_matrix_int_new(ants + 1, iter + 3); // несимметричная матрица
	while (ants)
	{
		while (path->path[i][0] != -1)
		{
			if (path->path[i][1] > 0)
			{
				add_path_in_matrix(path, i, matrix_res);
				path->j++;
				path->path[i][1]--; // отняли муравья из пути в массиве
				ants--; // отняли муравья от общего количества муравьев
			}
			i++;
		}
		path->i++;
		i = 0;
	}
	return (matrix_res);
}

int	path_present(int *str, int ants)
{
	int j = 0;

	while(j < ants)
	{
		if(str[j] > 0)
			return (1);
		j++;
	}
	return (0);
}

void		ft_print_res(int **matrix_res, t_lem *lem, t_room **room)
{
	int i = 0;
	int j = 0;
	int ants = lem->ants;

	while(path_present(matrix_res[i], ants) == 1)
	{
		while(j < ants)
		{
			if (matrix_res[i][j] > 0)
			{
				printf("L%d-", j + 1);
				printf("%s ", room[matrix_res[i][j]]->name);
			}
			j++;
		}
		i++;
		j = 0;
		printf("\n");
	}
	printf("count_iter=%d\n", i);
}

int		**ft_make_sets(char **map, t_room **room, t_lem *lem)
{
	int		i;
	int		**set;

	i = 0;
	set = ft_allocate_matrix_int(lem->count_rooms);
	while (map[i])
	{
		if (ft_valid_str(map[i]) == 5)
			ft_write_links(map[i], room, set);
		i++;
	}
	return (set);
}


int			main(void)
{
	int		k = 0;
	t_lem	lem;
	char	**map; 			// карта
	// char	**matrix; 		// матрица смежности
	int		**sets;
	int		*tmp;
	t_room	**room; 		// массив структур для комнат
	t_path	**path; 		// массив структур набора путей
	int		*first;			// кратчайший путь из 1-го набора путей (из него будем удалть ребра)
	int		**matrix_res;	// конечная матрица для вывода

	ft_initialization_lem(&lem);
	map = ft_read_map();
	ft_validation(map, &lem) == 1 ? room = ft_record(map, &lem) : exit (0);
	// matrix = ft_make_matrix(map, room, &lem);
	sets = ft_make_sets(map, room, &lem);

	// int l = 0;
	// while (sets[l][0] != -1)
	// {
	// 	k = 0;
	// 	while (k < lem.count_rooms)
	// 	{
	// 		printf("%3i ", sets[l][k]);
	// 		k++;
	// 	}
	// 	printf("\n");
	// 	l++;
	// }


	//ft_check_no_path(matrix);
	tmp = ft_alloc_qu(lem.count_rooms + 3);
	// ft_bfs2(matrix, &lem, room, tmp);
	ft_bfs2(sets, &lem, room, tmp);
	ft_unblock_all(sets);


	// l = 0;
	// printf("new sets\n");
	// while (sets[l][0] != -1)
	// {
	// 	k = 0;
	// 	while (k < lem.count_rooms)
	// 	{
	// 		printf("%3i ", sets[l][k]);
	// 		k++;
	// 	}
	// 	printf("\n");
	// 	l++;
	// }


	// k = 0;
	// printf("rooms\n");
	// while (room[k])
	// {
	// 	printf("room index %i - lvl %i", k, room[k]->lvl);
	// 	printf("\n");
	// 	k++;
	// }


	path = ft_allocate_memory_path(3, lem.count_rooms + 1); // выделяем память под 3 структуры, чтобы перезаписывать
	first = ft_first_path(path[0], room, &lem, sets, tmp); // записываем первый набор путей (без удаления ребер)
	k = ft_all_paths(path, room, &lem, sets, first, tmp); // возвращает индекс набора путей

	ft_reverse_path(path[k]); // разворачивает путь и записывает длину пути на 0 место
	ft_put_ants_in_path(&lem, path[k]); // на 1 место каждого пути кладем кол-во муравьев
	//ft_print_path_index(path[k]); // Проверка
	//printf("\n0 набор путей\n");
	//ft_print_path_index(path[0]);
	matrix_res = ft_create_res_matrix(&lem, path[k], path[k]->res); // Создаем матрицу из путей для всех меравьев, которую будем выводить построчно
	ft_print_res(matrix_res, &lem, room); // Печатаем вывод


	// printf("PATH->RES = %d\n", path[k]->res);
	printf("OK\n");
	//ft_print_name_lvl(&lem, room);
	//ft_print_matrix(matrix, &lem);
    return (0);
}


	// ft_print_path_name(path[0], room); 	/* печатаем пути по name */
	// ft_count_iter(path[0], &lem); 		/* кол-во итераций (= кол-во строк в конечном выводе) */
	// ft_print_path_name(path[1], room);
	// ft_count_iter(path[1], &lem); 		/* кол-во итераций (= кол-во строк в конечном выводе) */
	//ft_print_name_lvl(&lem, room);
	//ft_print_matrix(matrix, &lem); 	/* печатаем матрицу смежности */
	//ft_print_result(room, path[1], &lem); /* конечный вывод */

		// зафришить остальные наборы путей

	// Печать всех наборов путей
	// k = 0;
	// while (k < 3)
	// {
	// 	printf("SET OF PATHS #%d\n", k);
	// 	ft_reverse_path(path[k]);
	// 	//ft_print_path_name(path[k], room);
	// 	ft_count_iter(path[k], &lem);
	// 	printf("COUNT_ITER = %d\n\n", path[k]->res);
	// 	k++;
	// }
