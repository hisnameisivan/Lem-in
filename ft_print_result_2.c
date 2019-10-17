/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:31:25 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 19:35:58 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_put_ants_in_path(t_lem *lem, t_path *path)
{
	int	i;
	int	sum;
	int	ants;

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

void	ft_reverse_path(t_path *path)
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

void	ft_count_iter(t_path *path, t_lem *lem)
{
	int i;
	int j;
	int count_iter;
	int	count_steps;

	i = 0;
	count_iter = 0;
	count_steps = 0;
	path->count_paths = 0;
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
		path->count_paths++;
		i++;
	}
	count_steps = count_steps - path->count_paths;
	path->res = ((count_steps + (lem->ants - path->count_paths))
	/ path->count_paths);
}

int		choose_set_of_paths(t_path **path)
{
	int tmp;

	tmp = ((path[0]->res) > (path[1]->res) && (path[1]->res != 0) ? 1 : 0);
	tmp = (tmp > (path[2]->res) && (path[2]->res != 0) ? 2 : tmp);
	return (tmp);
}
