/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:57:07 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 19:44:22 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_cycle(t_room **room, t_lem *lem, t_path **path, int *qu)
{
	while (1)
	{
		ft_nul_fl(room, lem);
		ft_bfs2(lem->sets, lem, room, qu);
		ft_unblock_link(lem->sets, '7');
		path[lem->k]->i++;
		path[lem->k]->j = 0;
		if (ft_check_path_2(room, lem->sets, lem, path[lem->k]) == 0)
			break ;
	}
}

void	ft_apply_bfs(t_lem *lem, int *first, t_room **room, int *qu)
{
	ft_del_link(lem->sets, first[lem->i], first[lem->i + 1]);
	ft_nul_fl(room, lem);
	ft_bfs2(lem->sets, lem, room, qu);
	ft_unblock_link(lem->sets, '7');
}

void	ft_all_start(t_lem *lem)
{
	lem->i = 1;
	lem->k = 1;
	lem->len = 0;
}

void	ft_all_paths(t_path **path, t_room **room, t_lem *lem, int *qu)
{
	int		i;
	int		flag;
	int		*first;

	ft_all_start(lem);
	flag = 0;
	first = ft_first_path(path[0], room, lem, lem->sets);
	while (first[lem->len] >= 0)
		lem->len++;
	lem->len = lem->len - 3;
	while (lem->len > 0)
	{
		path[lem->k]->i = 0;
		ft_apply_bfs(lem, first, room, qu);
		if (ft_check_path_2(room, lem->sets, lem, path[lem->k]) == 0)
		{
			ft_unblock_link(lem->sets, '7');
			i++;
			lem->len--;
			continue ;
		}
		ft_cycle(room, lem, path, qu);
		ft_all_flag(&flag, lem, path, &i);
	}
	lem->k = choose_set_of_paths(path);
}
