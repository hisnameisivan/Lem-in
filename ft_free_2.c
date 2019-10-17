/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:10:50 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 19:33:04 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	ft_free_matrix(int ***matrix, int i)
{
	while (--i >= 0)
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
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
