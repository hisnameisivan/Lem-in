/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:54:08 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 19:40:19 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_block_link(int **sets, int i, int j)
{
	int		tmp;
	int		k;

	tmp = sets[i][j];
	k = 0;
	sets[i][j] = sets[i][j] - BLOCK;
	while (sets[tmp][k] != i)
	{
		if (sets[tmp][k] == -1)
			return ;
		k++;
	}
	sets[tmp][k] = sets[tmp][k] - BLOCK;
}

void	ft_del_link(int **sets, int i, int j)
{
	int		k;

	k = 0;
	while (sets[i][k] != j)
	{
		if (sets[i][k] == -1)
			return ;
		k++;
	}
	sets[i][k] = j + BLOCK;
	k = 0;
	while (sets[j][k] != i)
	{
		if (sets[j][k] == -1)
			return ;
		k++;
	}
	sets[j][k] = sets[j][k] + BLOCK;
}

void	ft_del_info_path(t_path *path, t_lem *lem)
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

void	ft_all_flag(int *flag, t_lem *lem, t_path **path, int *i)
{
	ft_count_iter(path[lem->k], lem);
	if ((*flag) == 1 && ((lem->len) - 1))
	{
		lem->k = (path[1]->res > path[2]->res ? 1 : 2);
		ft_del_info_path(path[lem->k], lem);
	}
	if ((*flag) == 0)
	{
		(*flag) = 1;
		lem->k++;
	}
	lem->len--;
	i++;
	ft_unblock_all(lem->sets);
}

void	ft_unblock_all(int **sets)
{
	int i;
	int j;

	i = 0;
	while (sets[i][0] != -1)
	{
		j = 0;
		while (sets[i][j] != -1)
		{
			if (sets[i][j] < -1)
				sets[i][j] = sets[i][j] + BLOCK;
			j++;
		}
		i++;
	}
}
