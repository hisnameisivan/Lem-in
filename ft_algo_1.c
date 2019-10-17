/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:49:27 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 15:07:28 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_check_len_path(t_path *path)
{
	if (path->j > 100)
	{
		ft_path_overwrite(path->i, path);
		path->i--;
		return (1);
	}
	return (0);
}

void	ft_start_check_path(t_path *path, t_lem *lem)
{
	path->j = 0;
	lem->str = lem->count_rooms - 1;
	path->path[path->i][path->j] = lem->str;
	path->j++;
}

void	ft_check_2(t_lem *lem, int **sets, t_path *path, t_room **room)
{
	lem->str = ft_next_link_2(sets[lem->str], lem, room);
	path->path[path->i][path->j] = lem->str;
	ft_del_link(sets, path->path[path->i][path->j - 1],
	path->path[path->i][path->j]);
	path->j++;
}

void	ft_check_3(t_lem *lem, int **sets, t_path *path)
{
	path->j--;
	lem->str = path->path[path->i][path->j];
	path->path[path->i][path->j + 1] = -1;
	if (ft_units_present(sets[lem->str]) == 1)
		path->j++;
}

int		ft_check_path_2(t_room **room, int **sets, t_lem *lem, t_path *path)
{
	ft_start_check_path(path, lem);
	if (ft_check_1(sets, lem, path) == 0)
		return (0);
	while (lem->str != 0)
	{
		if (ft_check_len_path(path) == 1)
			return (1);
		if (ft_units_present(sets[lem->str]) == 1)
		{
			ft_check_2(lem, sets, path, room);
			continue ;
		}
		else
		{
			if (lem->str == lem->count_rooms - 1)
			{
				path->path[path->i][0] = -1;
				return (0);
			}
			else
				ft_check_3(lem, sets, path);
		}
	}
	return (1);
}
