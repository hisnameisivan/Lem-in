/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:24:10 by draudrau          #+#    #+#             */
/*   Updated: 2019/07/21 17:08:39 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
# include "./libft/libft.h"

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


void	ft_print_matrix(char **matrix, t_lem *lem) /* Печатаем матрицу смежности */
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		ft_printf("%s\n", matrix[i]);
		i++;
	}
	ft_printf("\n\n");
}

void	ft_print_name_lvl(t_lem *lem, t_room **room) /* Печатаем имя, level, count_rooms*/
{
	int i;

	i = 0;
	ft_printf("\nCOUNT_ROOMS = %d\n", lem->count_rooms);
	ft_printf("\nCOUNT_ANTS = %d\n", lem->ants);
	while (i < lem->count_rooms)
	{
		ft_printf("name = %s, lvl = %d\n", room[i]->name, room[i]->lvl);
		i++;
	}
}
void		ft_print_path_index(t_path *path) /* Печатаем путь по индексу */
{
	int i;
	int j;

	i = 0;
	while (path->path[i][0] >= 0)
	{
		j = 0;
		while (path->path[i][j] >= 0)
		{
			ft_printf("path %d:  %d \n", i, path->path[i][j]);
			j++;
		}
		ft_printf("\nLEN_PATH = %d \n", j);
		ft_printf("\n");
		i++;
	}
}

void		ft_print_path_name(t_path *path, t_room **room) /* Печатаем путь по имени */
{
	int i;
	int j;

	i = 0;
	if (path->path[0][0] == -1)
	{
		ft_printf("Пустой набор путей\n"); /* ПРОВЕРКА УБРАТЬ */
		return ;
	}
	while (path->path[i][0] >= 0)
	{
		j = 0;
		while (path->path[i][j] >= 0)
		{
			ft_printf("path %d:  %s \n", i, room[path->path[i][j]]->name);
			j++;
		}
		ft_printf("\nLEN_PATH = %d \n", j);
		ft_printf("\n");
		i++;
	}
}


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
				ft_printf("not valid ants\n"); /* ПРОВЕРКА УБРАТЬ */
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
				ft_printf("2\n");
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
			ft_printf("3\n");
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

void 	ft_write(char *map, t_room **room, int k) /* Записывает Name x y */
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
	matrix = (int **)malloc(sizeof(int *) * dim);
	while (i < dim)
	{
		matrix[i] = (int *)malloc(sizeof(int) * dim * dim);
		ft_memset(matrix[i], -1, dim * dim * 4);
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

int		**ft_count_levels(char **matrix, /*t_room **room,*/ t_lem *lem)
{
	int		k;
	int		l;
	int		**tmp; /* списки смежности */

	lem->len = 1; /* {0} - 1 элемент */
	k = 0;
	tmp = ft_allocate_matrix_int(lem->count_rooms);
	tmp[0][0] = 0;
	while (lem->len)
	{
		l = 0;
		while (lem->len)
		{
			ft_create_str(matrix[tmp[k][l]], lem, &tmp, k);
			l++;
			lem->len--;
			//ft_printf("char matrix %s\n", matrix[tmp[k][l]]);
		}
		k++;
		lem->len = ft_del_repeat(&tmp, k); /* возвращает длину последней строчки */
		lem->n = 0;
	}
	k = 0;
	l = 0;
	while (k < lem->count_rooms)
	{
		l = 0;
		while (tmp[k][l] != -1)
		{
			ft_printf("%d ", tmp[k][l]);
			l++;
		}
		ft_printf("\n");
		k++;
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
	k = 0; /* индекс для массива структур room */
	room = ft_allocate_memory(lem);
	while (map[i])
	{
		valid_resh = ft_valid_resh(map[i], lem);
		// if (map[i][0] == '#' && valid_resh == 3)
		// 	/*i++*/;
		if (map[i][0] == '#' && valid_resh == 1)
		{
			i++;
		    ft_write(map[i], room, k); /* записать старт на 0 место */
			k++;
		}
		else if ((map[i][0] == '#' && valid_resh == 2))
		{
			i++;
			ft_write(map[i], room, k); /*записать end на *room[lem->count_rooms - 1] */
			k++;
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

/*
** Количество уже имеющихся в массиве соседних с текущим звеном графа звеньев.
*/

int		ft_count_nodes(t_room **room)
{
	int		len;

	len = 0;
	while (*room != NULL)
	{
		(*room)++;
		len++;
	}
	return (len);
}

/*
** Realloc для массива соседних с текущим звеном графа звеньев. Увеличение на 11
** элементов (10 + NULL) при вызове.
*/

void	ft_insert_links(t_room **all_rooms, t_room *room, int neighbour)
{
	t_room	**temp;
	int		len_lst; // длинна уже записанного списка ссылок на элементы (для реалока)
	int		i;
	int		j;

	len_lst = 0;
	temp = NULL;
	i = 0;
	j = 0;
	if (room->links == NULL)
	{
		room->links = (t_room**)malloc(sizeof(t_room*) * 11);
		room->links[10] = NULL;
		room->links[0] = all_rooms[neighbour];
		room->links[0]->empty_fl = 1;
	}
	else
	{
		while (room->links[i] != NULL && room->links[i]->empty_fl == 1)
			i++;
		if (room->links[i] != NULL)
		{
			len_lst = ft_count_nodes(room->links);
			temp = room->links;
			room->links = (t_room**)malloc(sizeof(t_room*) * (len_lst + 11));
			room->links[len_lst + 10] = NULL;
			while (j < len_lst + 10)
			{
				ft_bzero(room->links[j], sizeof(t_room));
				j++;;
			}
			ft_memcpy(room->links, temp, len_lst);
			free(temp);
		}
		room->links[i] = all_rooms[neighbour];
		room->links[i]->empty_fl = 1;
	}
}

/* Записываем линки между комнатами на соответствующие позиции матрицы смежности*/
void	ft_write_links(char *map, t_room **room, char **matrix)
{
	int		name1_ind;
	int		name2_ind;

	name1_ind = ft_search_name(&map, room, '-');
	map++;
	name2_ind = ft_search_name(&map, room, '\0');
	matrix[name1_ind][name2_ind] = '1';
	matrix[name2_ind][name1_ind] = '1';
	ft_printf("d1 == %d d2 == %d\n", name1_ind, name2_ind);
	ft_insert_links(room, room[name1_ind], name2_ind);
	ft_insert_links(room, room[name2_ind], name1_ind);
}

/* Функция создает матрицу смежности */
char	**ft_make_matrix(char **map, t_room **room, t_lem *lem)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = ft_allocate_matrix_char(lem->count_rooms);
	while (map[i])
	{
		if (ft_valid_str(map[i]) == 5)
			ft_write_links(map[i], room, matrix);
		i++;
	}
	i = 0;
	while (*room)
	{
		ft_printf("main_room: %s\n", (*room)->name);
		while ((*room)->links[i])
		{
			ft_printf("name: %s\n", (*room)->links[i]->name);
			i++;
		}
		ft_printf("\n");
		(*room)++;
	}
	exit(0);
	return (matrix);
}

/* Функция записывает в каждую комнату level, который получили в результате bfc обхода */

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
	ft_printf("COUNT_ITER = %d\n\n", path->res);
}

/* Функция ищет следующую связь, если у вершины есть связи -> хотя бы одна '1' в строке (end не учитываем)
Возвращаем индекс столбца с '1', либо '-1' - если у вершины нет связей
Из всех найденных связей выбираем с наименьшим level (чем меньше левел, тем короче путь) */

int		ft_next_link(char *matrix, t_lem *lem, t_room **room)
{
	int j;
	int tmp;
	int lvl;
	int fl;

	j = 0;
	fl = 0;
	while (matrix[j] != '\0')
	{
		if (matrix[j] == '1' && j != lem->count_rooms - 1 && j != lem->i /*room[j]->fl == 0*/)
		{
			if (fl == 0) /* записываем первую встретившуюся вершину, не смотря на левел */
			{
				tmp = j;
				lvl = room[j]->lvl;
				fl = 1;
			}
			else if (fl == 1 && (room[j]->lvl) < lvl)
			{
				tmp = j;
				lvl = room[j]->lvl;
			}
		}
		j++;
	}
	return (fl == 1 ? tmp : -1);
}

void	ft_del_link(char **matrix, int i, int j)
{
	matrix[i][j] = '0';
	matrix[j][i] = '0';
}

/* Функция собирает пути - если уперлись в тупик рекурсивно откатываемся на предыдущий шаг, при этом
затираем "тупиковую" связь и ищем обходной путь, если откатились до end - значит, путей больше нет.
2 варианта выхода из фунции - либо через lem->j = 0 - означает, что собрали путь (дошли до от end до start),
либо тупик - в строке закончились '1' (каждый раз "затираем" ребро в матрице смежности (1->0),
чтобы не использовать повторно ) */

int		ft_check_path(t_room **room, char **matrix, t_lem *lem, t_path *path, int j)
{
	//ft_printf("recursia\n");
	if (j == 0) /* базовое условие выхода из рекурсии - пришли в нулевую строку (это start) */
		return (1);
	if (ft_next_link(matrix[j], lem, room) != -1) /* если в строке есть '1'-> есть куда идти (раньше был while) */
	{
		path->j++;
		lem->i = j; /* lem->i - это из какой строки пришли */
		j = ft_next_link(matrix[j], lem, room);
		if (ft_check_path(room, matrix, lem, path, j) == 1)
		{
			/*path->path[lem->k][lem->l] = j; */
			path->path[path->i][path->j] = j;
			ft_del_link(matrix, lem->i, j);
			path->j--;
			return (1);
		}
		else
		{
			ft_del_link(matrix, lem->i, j);
			j = lem->i;
		}
	}
	return (0);
}

/* Функция копирует матрицу смежности */

char	**ft_copy_matrix(char **matrix, int len)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	copy = ft_allocate_matrix_char(len);
	while (matrix[i])
	{
		ft_strcpy(copy[i], matrix[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
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
	if (!(path = (t_path**)malloc(sizeof(t_path*) * len)))
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

void		ft_free_str(char **matrix, int *path, int len) /* Зануляем строку */
{
	int	i;
	int tmp;

	i = 1; /* берем из пути индексы (начиная с 1го чтобы не занулять строку end и зануляем соответствующие строки матрицы смежности*/
	while (path[i] != 0)
	{
		tmp = path[i];
		ft_memset(matrix[tmp], '0', len);
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

/* Функция записывает первый набор путей */

int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, char **matrix_copy)
{
	path->i = -1;
	while (1)
	{
		path->i++;
		path->j = 0;
		if (ft_check_path(room, matrix_copy, lem, path, lem->count_rooms - 1) == 0)
		{
			/* Зафришить неоконченный путь */
			break ;
		}
		else
		{
			path->path[path->i][path->j] = lem->count_rooms - 1; 		/* записываем индекс комнаты end на первое место */
			ft_del_link(matrix_copy, lem->count_rooms - 1, path->path[path->i][1]);
			ft_free_str(matrix_copy, path->path[path->i], lem->count_rooms); /* зануляем всю строку*/
			//ft_print_path_index(path[0]);						 		/* печатаем путь по индексу */
		}
	}
	return (path->path[0]);
	ft_free_matrix(&matrix_copy);
}

void		ft_block_link(char **matrix, int i, int j) /* временно заблокированную связь помечаем '7' */
{
	matrix[i][j] = '7';
	matrix[j][i] = '7';
}

void		ft_unblock_link(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == '7')
				matrix[i][j] = '1';
			j++;
		}
		i++;
	}
}
int		ft_path_with_del_link(t_path *path, t_room **room, t_lem *lem, char **matrix_copy)
{
	path->i = 0;
	path->j = 0;
	if (ft_check_path(room, matrix_copy, lem, path, lem->count_rooms - 1) == 0)
		return (0);
	else
	{
		path->path[0][0] = lem->count_rooms - 1; 		/* записываем индекс комнаты end на первое место */
		ft_del_link(matrix_copy, lem->count_rooms - 1, path->path[0][1]);
		ft_free_str(matrix_copy, path->path[0], lem->count_rooms);
	}
	return (1);
}

void		ft_all(t_path *path, t_room **room, t_lem *lem, char **matrix_copy)
{
	path->i = 0;
	while (1)
	{
		path->i++; /* начинаем запись остальных путей с 1ой строки (в нулевой уже лежит кратчайший путь) */
		path->j = 0;
		if (ft_check_path(room, matrix_copy, lem, path, lem->count_rooms - 1) == 0)
		{
			/* Зафришить неоконченный путь */
			break ;
		}
		else
		{
			path->path[path->i][path->j] = lem->count_rooms - 1; 		/* записываем индекс комнаты end на первое место */
			ft_del_link(matrix_copy, lem->count_rooms - 1, path->path[path->i][1]);
			ft_free_str(matrix_copy, path->path[path->i], lem->count_rooms); /* зануляем всю строку*/
		}
	}
	ft_free_matrix(&matrix_copy);
}

void		ft_del_info_path(t_path *path/*, t_lem *lem*/)
{
	int i;

	i = 0;
	ft_bzero(path, sizeof(t_path));
	// while (i < lem->count_rooms)
	// {
	// 	ft_memset(path->path[i], -1, lem->count_rooms * 4);
	// 	i++;
	// }

}

void		ft_all_paths(t_path **path, t_room **room, t_lem *lem, char **matrix, int *first)
{
	int		i;
	int		k;
	int		len;
	int		count = 0;
	char	**matrix_copy;

	i = 1;
	k = 1;
	len = 0;

	while (first[len] >= 0)
		len++;
	len = len - 3; /* кол-во ребер, которое будем удалять = (кол-во вершин - 1) и еще (- 2) (т.к. не удаляем ребра у start и end) */
	matrix_copy = ft_copy_matrix(matrix, lem->count_rooms);
	while (len)
	{
		count++; /* считаем сколько раз заходили в while */
		ft_block_link(matrix_copy, first[i], first[i + 1]);
		if (ft_path_with_del_link(path[k], room, lem, matrix_copy) == 0) /* собираем "новый" кратчайший путь c учетом, что заблокировали 1 ребро*/
		{																/* возможно надо еще пройтись bfs */
			ft_printf("no path\n");
			return ;
		}
		ft_unblock_link(matrix_copy); /* разблокируем ребро, чтобы найти отальные пути */
		ft_all(path[k], room, lem, matrix_copy);
		ft_count_iter(path[k], lem); /* считаем res */
		k++; /* переходим на следующую структуру (всего их 3, новые не создаем, перезаписываем следующий набор в структуру с большим res) */
		i++; /* чтобы заблокировать следующее ребро из кратчайшего пути path[0] */
		len--;
		if (count == 2) /* выбираем куда перезаписывать новый набор путей (выбираем k) */
		{
			count = 1;
			k = (path[1]->res > path[2]->res ? 1 : 2);
			ft_del_info_path(path[k]/*, lem*/); /* только зануляем информацию (не фришим) чтобы перезаписывать поверх */
		}

	}

}

/* Функция записывает путь в правильном порядке (от start к end), т.к. изначально путь хранится наоборот */
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
		j--;
		while (i < j)
		{
			tmp = path->path[k][i];
			path->path[k][i] = path->path[k][j];
			path->path[k][j] = tmp;
			i++;
			j--;
		}
		k++;
		j = 0;
		i = 0;
	}
}


// void		ft_print_result(t_room **room, t_path *path, t_lem *lem)
// {
// 	int i = 0;
// 	int delta = 0;
// 	int step = 0;
// 	int index_room;
// 	lem->i = 1; /* муравьи */
// 	//lem->j = 0;
// 	path->i = 0;
// 	path->j = 1; /* name комнаты start не выводим */
// 	int res = path->res;

// 	step = path->count_paths + delta;
// 	while (1)
// 	{
// 		while (step - i > 0)
// 		{
// 			index_room = path->path[path->i][path->j];
// 			ft_printf("L%d-%s ", lem->i, room[index_room]->name);
// 			path->i++;
// 			lem->i++; /* следующий муравей */
// 			if (lem->i > lem->ants)
// 				break ;
// 			i++;
// 		}
// 		path->i = 0;
// 		path->j++; /* индекс по iму пути */
// 		lem->i = 1;
// 		ft_printf("\n");
// 		res--;
// 		((path->res) < (res / 2)) ? (step = step + delta) : (step = step - delta);
// 		if (!res)
// 			break ;
// 	}

// }

int			choose_set_of_paths(t_path **path)
{
	int tmp;

	tmp = ((path[0]->res) < (path[1]->res) ? path[0]->res : path[1]->res);
	tmp = (tmp < (path[2]->res) ? tmp : path[2]->res);
	return (tmp);
}

int			main(void)
{
	t_lem	lem;
	int		**tmp; 			/* списки смежности */
	char	**map; 			/* карта */
	char	**matrix; 		/* матрица смежности */
	char	**matrix_copy;
	t_room	**room; 		/* массив структур для комнат */
	t_path	**path; 		/* массив структур набора путей */
	int		*first;			/* кратчайший путь из 1-го набора путей (из него будем удалть ребра) */

	ft_initialization_lem(&lem);
	map = ft_read_map();
	ft_validation(map, &lem) == 1 ? room = ft_record(map, &lem) : exit (0);
	matrix = ft_make_matrix(map, room, &lem);
	matrix_copy = ft_copy_matrix(matrix, lem.count_rooms); /* работаем с копией матрицы, т.к. в процессе сбора пути удаляем связи */
	tmp = ft_count_levels(matrix, &lem);
	ft_write_lvl_in_room(room, tmp);
	//ft_flag_null(room, lem.count_rooms); 					/* зануляем флаги у комнат */
	path = ft_allocate_memory_path(3, lem.count_rooms + 1); /* выделяем память под 3 структуры, чтобы не перезаписывать */
	first = ft_first_path(path[0], room, &lem, matrix_copy); /* записываем первый набор путей (без удаления ребер) */
	ft_all_paths(path, room, &lem, matrix, first);


	// Печать
	int k = 0;
	while (k < 3)
	{
		ft_printf("SET OF PATHS #%d\n", k);
		ft_reverse_path(path[k]);
		ft_print_path_name(path[k], room);
		ft_count_iter(path[k], &lem);
		k++;
	}
	// ft_print_path_name(path[0], room); 	/* печатаем пути по name */
	// ft_count_iter(path[0], &lem); 		/* кол-во итераций (= кол-во строк в конечном выводе) */
	// ft_print_path_name(path[1], room);
	// ft_count_iter(path[1], &lem); 		/* кол-во итераций (= кол-во строк в конечном выводе) */
	k = choose_set_of_paths(path);
	//ft_print_name_lvl(&lem, room);
	//ft_print_matrix(matrix, &lem); 	/* печатаем матрицу смежности */

	ft_reverse_path(path[1]); /* записываем путь в правильном порядке */
	//ft_print_result(room, path[1], &lem); /* конечный вывод */
	ft_printf("OK\n");
    return (0);
}
