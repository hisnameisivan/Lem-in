/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:55:47 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 12:57:56 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	ft_res(t_path **path, t_lem *lem, t_room **room, char **map)
{
	int **matrix_res;

	ft_reverse_path(path[lem->k]);
	ft_put_ants_in_path(lem, path[lem->k]);
	matrix_res = ft_create_res_matrix(lem, path[lem->k], path[lem->k]->res);
	ft_print_res(matrix_res, lem, room, map);
	ft_free_rooms(room, lem);
	ft_free_res_matrix(matrix_res, path[lem->k]->res);
	ft_free_path(lem->count_rooms + 1, path, 3);
	ft_free_sets(lem->sets, lem);
}
