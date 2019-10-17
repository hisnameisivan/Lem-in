/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:35:36 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 19:38:55 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
