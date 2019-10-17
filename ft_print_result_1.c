/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:59:10 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 20:46:01 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_map(char **map)
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

int		**ft_create_res_matrix(t_lem *lem, t_path *path, int iter)
{
	int	i;
	int	**matrix_res;
	int ants;

	path->i = 0;
	path->j = 0;
	ants = lem->ants;
	matrix_res = ft_alloc_matrix(ants, iter + 2);
	while (ants)
	{
		i = 0;
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
	}
	return (matrix_res);
}

int		path_present(int *str, int ants)
{
	int j;

	j = 0;
	while (j < ants)
	{
		if (str[j] > 0)
			return (1);
		j++;
	}
	return (0);
}

void	add_path_in_matrix(t_path *path, int index, int **matrix_res)
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

void	ft_print_res(int **matrix_res, t_lem *lem, t_room **room, char **map)
{
	int i;
	int j;
	int ants;

	i = 0;
	j = 0;
	ants = lem->ants;
	ft_print_map(map);
	while (path_present(matrix_res[i], ants) == 1)
	{
		while (j < ants)
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
}
