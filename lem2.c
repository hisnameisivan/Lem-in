// Старый алгоритм (без рекурсии)

#include "lemin.h"

int		**ft_get_path(t_room **room, char **matrix, t_lem *lem, t_path *path)
{
	int i;
	//int j;
	int	l;
	int	lvl;
	//int	**path;

	path->path = ft_allocate_matrix_int(lem->count_rooms + 1);
	while (lem->n < lem->max) /* lem->max - максимально возможное количество независимых путей */
	{
		l = 0;
		lvl = 0;
		ft_start(lem, &(path->path), &i); /* начинаем записывать новый путь -> i-ый индекс на строке с end, lem->j_path = 1, в path[0][0] end */
		while (lem->count_rooms > l && lem->fl1 == 0)
		{
			lem->j = 0; /* индекс по столбцам матрицы смежности */
			while (matrix[i][lem->j])
			{
				if (matrix[i][lem->j] == '1' && room[lem->j]->lvl == lvl && (room[lem->j]->fl == 0 || lem->j == 0 )) /* j = 0 для вершины start */
				{
					//ft_check_path(matrix, lem);
					if (i == 0 || i == lem->count_rooms - 1)
						ft_del_link(matrix, i, lem->j); /* удаляем связь только для start и end */
					i = lem->j;
					ft_add_room_to_path(room, lem, lem->j, path->path);
					lem->fl = 1; /* флаг что заходили в if */
					l++;
					break ;
				}
				else
					lem->j++;
			}
			if (ft_finish_write_way(path->path, lem, matrix[i], room) == 1)
				break ;
			lem->fl == 0 ? lvl++ : (lvl = 0); /* если fl == 0 -> не нашли подходящую для доавления в путь вершину -> увеличиваем  lvl, иначе мы уже на другой строке (lvl занулим) */
			if (lvl == 0)
				lem->fl = 0;		
		}
		lem->n++;
	}
	//while (ft_search_one(matrix[0]) == 1 || ft_search_one(matrix[lem->count_rooms - 1]) == 1)
	i = 0;
	lem->j = 0;
	while (path->path[i][0] > 0)
	{
		lem->j = 0;
		ft_printf("\npath %d\n", i);
		while (path->path[i][lem->j] > 0)
		{
			ft_printf("step: %d  %d\n", lem->j, path->path[i][lem->j]);
			lem->j++;
		}
		i++;
	}
		ft_printf("path1: %d ", path->path[0][0]);
		ft_printf("path1: %d ", path->path[0][1]);
		ft_printf("path1: %d ", path->path[0][2]);
		ft_printf("path1: %d\n", path->path[0][3]);
		ft_printf("path2: %d ", path->path[1][0]);
		ft_printf("path2: %d ", path->path[1][1]);
		ft_printf("path2: %d ", path->path[1][2]);
		ft_printf("path2: %d ", path->path[1][3]);
		ft_printf("path2: %d\n", path->path[1][4]);
	ft_count_iter(path, lem);
	return (path->path);
}

void	ft_max_count(char **matrix, t_lem *lem)
{
	int		i;
	int		count_start;
	int		count_end;

	i = 0;
	count_start = 0;
	count_end = 0;
	while (matrix[0][i] != '\0')
	{
		if (matrix[0][i] == '1')
			count_start++;
		i++;
	}
	i = 0;
	while (matrix[lem->count_rooms - 1][i] != '\0')
	{
		if (matrix[lem->count_rooms - 1][i] == '1')
			count_end++;
		i++;
	}
	lem->max = (count_end > count_start ? count_start : count_end);
}

int		ft_finish_write_way(int **path, t_lem *lem, char *matrix, t_room **room) /* return 1 - закончили запись пути, return 0 - продолжаем */
{
	int j;

	j = 0;
	if (path[lem->i_path][lem->j_path - 1] == 0) /* последний записанный элемент в путь - это start (его индекс = 0) */
	{
		lem->i_path++; /* переходим на следующую строку дл записи следующего пути */
		lem->j_path = 1; /* начинаем запись пути с 1го элемента - на нулевом месте всегда end */
		lem->fl1 = 1; /* флаг показывает, что закончили записывать путь -> чтобы не зайти в while */
		return (1);
	}
	else if (path[lem->i_path][lem->j_path - 1] != 0) /* если мы не закончили запись пути, проверяем что у последней добавленной в путь вершины есть незаблокированные соседи иначе тупик */
	{
		while (matrix[j])
		{
			if (matrix[j] == '1')
			{
				if (room[j]->fl == 1 && j != 0)
					j++;
				else
					return (0);
			}
			j++;
		}

		//ft_memset(path[lem->i_path], -1, lem->count_rooms * lem->count_rooms); /* пришли в тупик - зачищаем путь */
		return (1);
	}
	return (0);

}

void	ft_add_room_to_path(t_room **room, t_lem *lem, int j, int **path) /* добавляем комнату в путь и переключаем флаг */
{
	path[lem->i_path][lem->j_path] = j;
	lem->j_path++;
	room[j]->fl = 1;
}

void	ft_start(t_lem *lem, int ***path, int *i)
{
	lem->fl1 = 0;
	(*path)[lem->i_path][0] = lem->count_rooms - 1;
	lem->j_path = 1; /* т к на 0 месте всегда end */
	(*i) = lem->count_rooms - 1;
}

void	ft_del_link(char **matrix, int i, int j)
{
	matrix[i][j] = '0';
	matrix[j][i] = '0';
}

void	ft_flag_null(t_room **room, int len)
{
	int		i;

	i = 0;
	while (len > i)
	{
		room[i]->fl = 0;
		i++;
	}
}

int		ft_search_one(char *matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i] == '1')
			return (1);
		else
			i++;
	}
	return (0);
}