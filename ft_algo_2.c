/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:54:05 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 19:43:17 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_path_overwrite(int i, t_path *path)
{
	int j;

	j = 0;
	while (path->path[i][j] > -1)
	{
		path->path[i][j] = -1;
		j++;
	}
}

int		ft_check_1(int **sets, t_lem *lem, t_path *path)
{
	if (ft_units_present(sets[0]) == 0 ||
	ft_units_present(sets[lem->count_rooms - 1]) == 0)
	{
		path->path[path->i][0] = -1;
		return (0);
	}
	return (1);
}

int		ft_next_link_2(int *str, t_lem *lem, t_room **room)
{
	int j;
	int tmp;
	int lvl;

	j = 0;
	lem->fl = 0;
	while (str[j] != -1)
	{
		if (str[j] >= 0 && str[j] < BLOCK)
		{
			if (lem->fl == 0)
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
				lem->fl = 1;
			}
			else if (lem->fl == 1 && (room[str[j]]->lvl) < lvl)
			{
				tmp = str[j];
				lvl = room[str[j]]->lvl;
			}
		}
		j++;
	}
	return (tmp);
}

int		ft_units_present(int *str)
{
	int i;

	i = 0;
	while (str[i] != -1)
	{
		if (str[i] >= 0 && str[i] < BLOCK)
			return (1);
		else
			i++;
	}
	return (0);
}

int		*ft_first_path(t_path *path, t_room **room, t_lem *lem, int **sets)
{
	path->i = -1;
	while (1)
	{
		path->i++;
		path->j = 0;
		if (ft_check_path_2(room, sets, lem, path) == 0)
			break ;
		ft_nul_fl(room, lem);
		ft_bfs2(sets, lem, room, lem->qu);
		ft_unblock_link(sets, '7');
	}
	ft_count_iter(path, lem);
	ft_unblock_all(sets);
	return (path->path[0]);
}
