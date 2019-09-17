/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:24:10 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/17 23:08:25 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void ft_nul_fl(t_room **room, t_lem *lem)
{
	int i = 0;
	while (i < lem->count_rooms)
	{
		room[i]->fl = 0;
		room[i]->lvl = 0;
		i++;
	}
}

int		ft_check_empty(int *tmp, t_lem *lem)
{
	int i = 0;

	while (i < lem->count_rooms)
	{
		if (tmp[i] != -1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_neighbors(int **sets, t_room **room, int *tmp)
{
	int i;
	int j = 0;
	int k = 0;
	int lvl;

	while (tmp[k] == -1)
		k++;
	i = tmp[k];
	lvl = room[i]->lvl + 1;
	while (tmp[k] != -1)
		k++;
	while (sets[i][j] != -1)
	{
		if (sets[i][j] >= 0 && sets[i][j] < BLOCK / 2 && room[sets[i][j]]->fl == 0)
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
	int i = 0;

	while (tmp[i] == -1)
		i++;
	tmp[i] = -1;
}

int		*ft_alloc_qu(int len)
{
	int *tmp;

	if (!(tmp = (int *)malloc(sizeof(int) * len)))
		ft_leave();
	ft_memset(tmp, -1, len * 4);
	return (tmp);
}

void	ft_bfs2(int **sets, t_lem *lem, t_room **room, int *tmp)
{
	int i;

	i = 0;

	tmp[0] = 0;
	while(ft_check_empty(tmp, lem) != 0)
	{
		ft_add_neighbors(sets, room, tmp);
		ft_del_left(tmp);
		i++;
	}
}

// void	ft_leave(void)
// {
// 	ft_printf("ERROR\n");
// 	exit(0);
// }

// void	ft_init(void *data, size_t size)
// {
// 	ft_bzero(data, size);
// }

// int		ft_valid_str(char *map)
// {
// 	int		i;
// 	int		fl;
// 	t_valid	val;

// 	i = 0;
// 	fl = 0;

// 	val.name = 0;
// 	val.count_x = 0;
// 	val.count_y = 0;
// 	val.defice = 0;
// 	val.space = 0;
// 	if (map[0] == 'L')
// 		return (0);
// 	else if (map[0] == '#')
// 		return (3);
// 	while (map[i])
// 	{
// 		if (map[i] == ' ' || map[i] == '-')
// 		{
// 			map[i] == ' ' ? val.space++ : val.defice++;
// 			fl = 0;
// 			i++;
// 		}
// 		else if ((map[i] != ' ' && fl == 0 && val.name < 1))
// 		{
// 			val.name++;
// 			fl = 1;
// 			i++;
// 		}
// 		else if ((map[i] != '-' && fl == 0 && val.name < 2 && val.defice == 1))
// 		{
// 			val.name++;
// 			fl = 1;
// 			i++;
// 		}
// 		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 1) /* для валидации координаты x */
// 		{
// 			while(map[i] != ' ')
// 			{
// 				if (ft_isdigit(map[i]) == 1)
// 					i++;
// 				else if (map[i] == '\0' || ft_isdigit(map[i]) == 0)
// 					return (0);
// 			}
// 			val.count_x++;
// 		}
// 		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 2)
// 		{
// 			while(map[i] != '\0')
// 			{
// 				if (ft_isdigit(map[i]) == 1)
// 					i++;
// 				else
// 					return (0);
// 			}
// 			val.count_y++;
// 		}
// 		else if (val.name == 1 && fl == 0 && (map[i] != ' ' && map[i] != '-') && val.defice == 1) /* валидируем name2 */
// 		{
// 			if (map[i] == '#' || map[i] == 'L')
// 				return (0);
// 			val.name++;
// 			fl = 1;
// 			i++;
// 		}
// 		else if ((map[i] != ' ' && map[i] != '-') && fl == 1) /* находимся в name */
// 			i++;
// 		else
// 		    return (0);
// 	}
// 	if (val.space == 2 && val.name == 1 && val.count_x == 1 && val.count_y == 1)
// 		return (4);
// 	else if (val.defice == 1 && val.name == 2)
// 		return (5);
// 	else
// 		return (0);
// }

// int		ft_valid_sharp(char *map, t_lem *lem) /* проверяем start, end и comment*/
// {
// 	int i;

// 	i = 0;
// 	if (map == NULL)
// 		ft_leave();
// 	else if (ft_strcmp(map, "##start") == 0)
// 	{
// 		lem->start++;
// 		return (1);
// 	}
// 	else if (ft_strcmp(map, "##end") == 0)
// 	{
// 		lem->end++;
// 		return (2);
// 	}
// 	else if (map[0] == '#' && map[1] != '\0')
// 		return (3);
// 	return (0);
// }

// int		ft_valid_ants(char **map, t_lem *lem)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i][0] == '#')
// 		i++;
// 	if (map[i][0] >= '1' && map[i][0] <= '9')
// 	{
// 		j = 0;
// 		while (map[i][j] != '\0')
// 		{
// 			if (ft_isdigit(map[i][j]) == 1)
// 				j++;
// 			else
// 				ft_leave();
// 		}
// 		lem->ants = ft_atoi(map[i]);
// 		if (lem->ants < 1)
// 			ft_leave();
// 		i++;
// 		return (i);
// 	}
// 	else
// 	{
// 		ft_leave();
// 		return (0);
// 	}
// }

// int		ft_validation(char **map, t_lem *lem)
// {
// 	int i;
// 	int	valid_resh;

// 	i = ft_valid_ants(map, lem);
// 	while (map[i])
// 	{
// 		if (map[i][0] == '#')
// 		{
// 			valid_resh = ft_valid_sharp(map[i], lem);
// 			if (((valid_resh == 1 || valid_resh == 2) && (map[i + 1] != NULL)
// 			&& (ft_valid_str(map[i + 1]) == 4)) || valid_resh == 3)
// 				i++;
// 			else if((valid_resh == 1 || valid_resh == 2) && (map[i + 1] != NULL)
// 			&& ft_valid_sharp(map[i + 1], lem))
// 				i++;
// 			else
// 				ft_leave();
// 		}
// 		else if (ft_valid_str(map[i]) == 4)
// 		{
// 			lem->count_rooms++;
// 			i++;
// 		}
// 		else if (ft_valid_str(map[i]) == 5)
// 		{
// 			lem->links++;
// 			i++;
// 		}
// 		else
// 			ft_leave();
// 	}
// 	if (lem->start == 1 && lem->end == 1 && lem->links > 0)
// 		return (1);
// 	else
// 	{
// 		ft_leave();
// 		return (0);
// 	}
// }

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
			ft_leave();
		}
		ft_init(room[i], sizeof(t_room));
		i++;
	}
	room[i] = NULL;
	return (room);
}

void 	ft_write(char *map, t_room **room, int k)
{
	int co;

	co = 0;
	while (map[co] != ' ')
		co++;
	if (!(room[k]->name = ft_strnew(co)))
	{
		ft_leave();
	}
	ft_strncpy(room[k]->name, map, co);
	room[k]->x = ft_atoi(&map[co]);
	co++;
	while (map[co] != ' ')
		co++;
	room[k]->y = ft_atoi(&map[co]);
}

void	ft_free_matrix_int(int ***matrix, int i)
{
	while (--i >= 0)
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
}

void	ft_free_matrix_char(char ***matrix, int i)
{
	while (--i >= 0)
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
}

char	**ft_allocate_matrix_char(int dim)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = NULL;
	if (!(matrix = (char **)malloc(sizeof(char *) * (dim + 1))))
		ft_leave();
	while (i < dim)
	{
		if (!(matrix[i] = ft_strnew(dim)))
		{
			ft_free_matrix_char(&matrix, i);
			ft_leave();
		}
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
	dim++;
	if (!(matrix = (int **)malloc(sizeof(int *) * dim)))
		ft_leave();
	while (i < dim)
	{
		if (!(matrix[i] = (int *)malloc(sizeof(int) * dim)))
		{
			ft_free_matrix_int(&matrix, i);
			ft_leave();
		}
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

int ft_check_repeat(t_room **room, t_lem *lem)
{
	int		i;
	int		k;
	char	tmp[1000];

	i = 0;
	while (i < lem->count_rooms)
	{
		k = 0;
		ft_strcpy(tmp, room[i]->name);
		while (k < lem->count_rooms)
		{
			if(ft_strcmp(tmp, room[k]->name) == 0 && k != i)
			{
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int		ft_no_start_end(t_room **room, t_lem *lem)
{
	int tmp;

	tmp = lem->count_rooms - 1;
	if (room[0]->name == NULL || room[tmp]->name == NULL)
		return (1);
	else if(ft_strcmp(room[0]->name, room[tmp]->name) == 0)
		return (1);
	else
		return (0);
}

t_room 	**ft_record(char **map, t_lem *lem)
{
	int			i;
	int			k;
	int			valid_resh;
	t_room		**room;

	i = 0;
	k = 1;
	room = ft_allocate_memory(lem);
	while (map[i])
	{
		valid_resh = ft_valid_sharp(map[i], lem);
		if (map[i][0] == '#' && valid_resh == 1)
		{
			while (ft_valid_sharp(map[i + 1], lem) == 3)
				i++;
			i++;
		    ft_write(map[i], room, 0);
		}
		else if ((map[i][0] == '#' && valid_resh == 2))
		{
			while (ft_valid_sharp(map[i + 1], lem) == 3)
				i++;
			i++;
			ft_write(map[i], room, lem->count_rooms - 1);
		}
		else if (ft_valid_str(map[i]) == 4)
		{
			ft_write(map[i], room, k);
            k++;
		}
		i++;
	}
	if (ft_check_repeat(room, lem) == 1 || ft_no_start_end(room, lem) == 1)
	{
		// надо зафришить комнаты
		ft_leave();
	}
	return (room);
}

// int		ft_strsrch(char *str, char chr)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i + 1] != '\0')
// 	{
// 		if (str[i] == chr && str[i + 1] == chr)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	**ft_read_map()
// {
// 	int		ret;
//     char	buff[BUFF_SIZE + 1];
// 	char	*del;
// 	char	*temp;
// 	int 	fl;
// 	char	**map;

// 	fl = 0;
// 	if (!(temp = ft_strnew(0)))
// 		ft_leave();
// 	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
// 	{
// 		buff[ret] = '\0';
// 		if (ft_strsrch(buff, '\n') == 1)
// 			ft_leave();
// 		del = temp;
// 		temp = ft_strjoin(temp, buff);
// 		free(del);
// 		fl = 1;
// 	}
// 	if (fl == 0)
// 		ft_leave();
// 	map = ft_strsplit(temp, '\n');
// 	free(temp);
// 	return (map);
// }

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
	if (!(name = ft_strnew(len_name)))
		ft_leave();
	ft_strncpy(name, temp, len_name);
	while (room[index])
	{
		if (ft_strcmp(name, room[index]->name) == 0)
			break ;
		index++;
	}
	free(name);
	if (room[index] == NULL)
		return (-1);
	return (index);
}

void	ft_write_links(char *map, t_room **room, int **set)
{
	int		name1_ind;
	int		name2_ind;
	int		i;

	if ((name1_ind = ft_search_name(&map, room, '-')) == -1)
		ft_leave();
	map++;
	if ((name2_ind = ft_search_name(&map, room, '\0')) == -1)
		ft_leave();
	i = 0;
	while (set[name1_ind][i] != -1)
		i++;
	set[name1_ind][i] = name2_ind;
	i = 0;
	while (set[name2_ind][i] != -1)
		i++;
	set[name2_ind][i] = name1_ind;
}


void	ft_count_iter(t_path *path, t_lem *lem)
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
	if (path->path[0][0] == -1)
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
}

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
	k = 0;
	while (sets[j][k] != i)
	{
		if (sets[j][k] == -1)
			return;
		k++;
	}
	sets[j][k] = sets[j][k] + BLOCK;
}

int ft_units_present(int *str)
{
    int i;

    i = 0;
    while (str[i] != -1)
    {
        if (str[i] >= 0 && str[i] < BLOCK / 2)
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
		if (str[j] >= 0  && str[j] <= BLOCK / 2)
		{
			if (fl == 0)
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

void		ft_block_link(int **sets, int i, int j)
{
	int		tmp;
	int		k;

	tmp = sets[i][j];
	k = 0;
	sets[i][j] = sets[i][j] - BLOCK;
	while (sets[tmp][k] != i)
	{
		if (sets[tmp][k] == -1)
			return;
		k++;
	}
	sets[tmp][k] = sets[tmp][k] - BLOCK;
}

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
		return (0);
	}
    while (str != 0)
    {
		if (path->j > 100)
		{
			ft_path_overwrite(path->i, path);
			path->i--;
			return (1);
		}
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

void	ft_free_matrix_i(int **matrix, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_free_path(int count, t_path **path, int i)
{
	int **tmp;
	int len;

	len = i;
	while (--i >= 0)
	{
		tmp = path[i]->path;
		ft_free_matrix_i(tmp, count);
		free(path[i]);
	}
	free(path);
}

t_path		**ft_allocate_memory_path(int len, int count_rooms)
{
	int		i;
	t_path	**path;

	i = 0;
	if (!(path = (t_path**)malloc(sizeof(t_path*) * (len))))
		ft_leave();
	while (i < len)
	{
		if (!(path[i] = (t_path*)malloc(sizeof(t_path))))
		{
			ft_free_path(count_rooms, path, i);
			ft_leave();
		}
		ft_init(path[i], sizeof(t_path));
		path[i]->path = ft_allocate_matrix_int(count_rooms);
		i++;
	}
	return (path);
}

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
			if (sets[i][j] < -BLOCK / 2)
				sets[i][j] = sets[i][j] + BLOCK;
			j++;
		}
		i++;
	}
}

int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, int **sets, int *tmp)
{
	path->i = -1;
	while (1)
	{
		path->i++;
		path->j = 0;
		if (ft_check_path_2(room, sets, lem, path) == 0)
			break ;
		//else
		//	ft_free_str(sets, path->path[path->i]); /* блокируем пути '9' */
		ft_nul_fl(room, lem);
		ft_bfs2(sets, lem, room, tmp);
		ft_unblock_link(sets, '7');
	}
	ft_count_iter(path, lem);
	ft_unblock_all(sets);
	return (path->path[0]);
}

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
	len = len - 3;
	while (len > 0)
	{
		path[k]->i = 0;
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
			//else
			//	ft_free_str(sets, path[k]->path[path[k]->i]); /* заменяем "1" на "9" */
		}
		ft_count_iter(path[k], lem);
		if (flag == 1 && (len - 1))
		{
			k = (path[1]->res > path[2]->res ? 1 : 2);
			ft_del_info_path(path[k], lem);
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

	i = path->i;
	j = 2;
	while (path->path[index][j] > 0)
	{
		matrix_res[i][path->j] = path->path[index][j];
		i++;
		j++;
	}
}


int		**ft_allocate_matrix_int_new(int x, int y)
{
	int		i;
	int		**matrix;

	i = 0;
	if (!(matrix = (int **)malloc(sizeof(int *) * y)))
		ft_leave();
	while (i < y)
	{
		if (!(matrix[i] = (int *)malloc(sizeof(int) * x)))
		{
			ft_free_matrix_int(&matrix, i);
			ft_leave();
		}
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
	matrix_res = ft_allocate_matrix_int_new(ants + 1, iter + 3);
	while (ants)
	{
		while (path->path[i][0] != -1)
		{
			if (path->path[i][1] > 0)
			{
				add_path_in_matrix(path, i, matrix_res);
				path->j++;
				path->path[i][1]--;
				ants--;
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

void		ft_print_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("\n");
	ft_free_map(&map);
}

void		ft_print_res(int **matrix_res, t_lem *lem, t_room **room, char **map)
{
	int i = 0;
	int j = 0;
	int ants = lem->ants;

	ft_print_map(map);
	while(path_present(matrix_res[i], ants) == 1)
	{
		while(j < ants)
		{
			if (matrix_res[i][j] > 0)
			{
				ft_printf("L%d-", j + 1);
				ft_printf("%s ", room[matrix_res[i][j]]->name);
			}
			j++;
		}
		i++;
		j = 0;
		ft_printf("\n");
	}
	ft_printf("count_iter=%d\n", i);
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

void	ft_free_map(char ***map)
{
	int i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

void	ft_free_rooms(t_room **room, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms)
	{
		free(room[i]->name);
		free(room[i]);
		i++;
	}
	free(room);
}

void	ft_free_sets(int **sets, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->count_rooms + 1)
	{
		free(sets[i]);
		i++;
	}
	free(sets);
}

void	ft_free_res_matrix(int **matrix, int iter)
{
	int i;

	i = 0;
	while (i < iter + 3)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int			main(void)
{
	int		k;
	t_lem	lem;
	char	**map;
	int		**sets;
	int		*tmp;
	t_room	**room;
	t_path	**path;
	int		*first;
	int		**matrix_res;


	ft_init(&lem, sizeof(t_lem));
	ft_read_map(&map);
	ft_validation(map, &lem) == 1 ? room = ft_record(map, &lem) : exit (0);
	sets = ft_make_sets(map, room, &lem);
	tmp = ft_alloc_qu(lem.count_rooms + 3);
	ft_bfs2(sets, &lem, room, tmp);
	if (room[lem.count_rooms - 1]->lvl == 0)
		ft_leave();
	ft_unblock_all(sets);
	path = ft_allocate_memory_path(3, lem.count_rooms + 1);
	first = ft_first_path(path[0], room, &lem, sets, tmp);
	k = ft_all_paths(path, room, &lem, sets, first, tmp);
	ft_reverse_path(path[k]);
	ft_put_ants_in_path(&lem, path[k]);
	matrix_res = ft_create_res_matrix(&lem, path[k], path[k]->res);
	ft_print_res(matrix_res, &lem, room, map);
	ft_free_sets(sets, &lem);
	ft_free_rooms(room, &lem);
	ft_free_res_matrix(matrix_res, path[k]->res);
	ft_free_path(lem.count_rooms + 1, path, 3);
	free(tmp);
	// printf("OK\n"); // УБРАТЬ
    return (0);
}