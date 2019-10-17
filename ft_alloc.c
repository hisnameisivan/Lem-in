/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:31:50 by waddam            #+#    #+#             */
/*   Updated: 2019/09/19 15:12:30 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*ft_alloc_qu(int len, t_lem *lem)
{
	int	*tmp;

	if (!(tmp = (int *)malloc(sizeof(int) * len)))
		ft_leave();
	ft_memset(tmp, -1, sizeof(int) * len);
	lem->qu = tmp;
	return (tmp);
}

t_room	**ft_alloc_rooms(t_lem *lem)
{
	int		i;
	t_room	**room;

	i = 0;
	if (!(room = (t_room **)malloc(sizeof(t_room *) * (lem->count_rooms + 1))))
		ft_leave();
	while (i < (lem->count_rooms))
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

t_path	**ft_alloc_path(int len, int count_rooms)
{
	int		i;
	t_path	**path;

	i = 0;
	if (!(path = (t_path **)malloc(sizeof(t_path *) * (len))))
		ft_leave();
	while (i < len)
	{
		if (!(path[i] = (t_path *)malloc(sizeof(t_path))))
		{
			ft_free_path(count_rooms, path, i);
			ft_leave();
		}
		ft_init(path[i], sizeof(t_path));
		path[i]->path = ft_alloc_matrix(count_rooms, count_rooms);
		i++;
	}
	return (path);
}

int		**ft_alloc_matrix(int x, int y)
{
	int		i;
	int		**matrix;

	i = 0;
	if (!(matrix = (int **)malloc(sizeof(int *) * (y + 1))))
		ft_leave();
	while (i < (y + 1))
	{
		if (!(matrix[i] = (int *)malloc(sizeof(int) * (x + 1))))
		{
			ft_free_matrix(&matrix, i);
			ft_leave();
		}
		ft_memset(matrix[i], -1, sizeof(int) * (x + 1));
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
