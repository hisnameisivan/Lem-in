/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:58:59 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 15:02:35 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_write(char *map, t_room **room, int k)
{
	int co;

	co = 0;
	while (map[co] != ' ')
		co++;
	if (!(room[k]->name = ft_strnew(co)))
	{
		ft_leave();
	}
	ft_strncpy(room[k]->name, map, co);
	room[k]->x = ft_atoi(&map[co]);
	co++;
	while (map[co] != ' ')
		co++;
	room[k]->y = ft_atoi(&map[co]);
}

void	ft_find(int ***tmp, int i, int j, int k)
{
	int		l;
	int		m;
	int		num;

	l = 0;
	num = (*tmp)[i][j];
	while (l < k + 1)
	{
		m = 0;
		while ((*tmp)[l][m] >= 0)
		{
			if (((*tmp)[l][m] == num) && !(i == l && j == m))
			{
				while ((*tmp)[l][m] >= 0)
				{
					(*tmp)[l][m] = (*tmp)[l][m + 1];
					m++;
				}
				m = 0;
			}
			m++;
		}
		l++;
	}
}

void	ft_create_str(char *matrix, t_lem *lem, int ***tmp, int k)
{
	int j;

	j = 0;
	while (matrix[j])
	{
		if (matrix[j] == '1')
		{
			(*tmp)[k + 1][lem->n] = j;
			lem->n++;
		}
		j++;
	}
}

void	ft_unblock_link(int **sets, char sign)
{
	int i;
	int j;

	i = 0;
	while (sets[i][0] != -1)
	{
		j = 0;
		while (sets[i][j] != -1)
		{
			if (sets[i][j] < -1 && sign == '7')
				sets[i][j] = sets[i][j] + BLOCK;
			else if (sets[i][j] > BLOCK && sign == '9')
				sets[i][j] = sets[i][j] - BLOCK;
			j++;
		}
		i++;
	}
}
