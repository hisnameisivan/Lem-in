/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_p1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:31:25 by waddam            #+#    #+#             */
/*   Updated: 2019/09/17 23:06:54 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_helper(char *map_i1, char *map_i2, t_lem *lem, int *i)
{
	if (map_i1[0] == '#')
	{
		lem->vld = ft_valid_sharp(map_i1, lem);
		if (((lem->vld == 1 || lem->vld == 2) && (map_i2 != NULL)
			&& (ft_valid_str(map_i2) == 4)) || lem->vld == 3)
			(*i)++;
		else if ((lem->vld == 1 || lem->vld == 2) && (map_i2 != NULL)
			&& ft_valid_sharp(map_i2, lem))
			(*i)++;
		else
			ft_leave();
	}
	else if (ft_valid_str(map_i1) == 4)
	{
		lem->count_rooms++;
		(*i)++;
	}
	else if (ft_valid_str(map_i1) == 5)
	{
		lem->links++;
		(*i)++;
	}
	else
		ft_leave();
}

int			ft_validation(char **map, t_lem *lem)
{
	int i;

	i = ft_valid_ants(map, lem);
	while (map[i])
		ft_helper(map[i], map[i + 1], lem, &i);
	if (lem->start == 1 && lem->end == 1 && lem->links > 0)
		return (1);
	else
		ft_leave();
	return (0);
}

int			ft_valid_sharp(char *map, t_lem *lem)
{
	int		i;

	i = 0;
	if (map == NULL)
		ft_leave();
	else if (ft_strcmp(map, "##start") == 0)
	{
		lem->start++;
		return (1);
	}
	else if (ft_strcmp(map, "##end") == 0)
	{
		lem->end++;
		return (2);
	}
	else if (map[0] == '#' && map[1] != '\0')
		return (3);
	return (0);
}

int			ft_valid_ants(char **map, t_lem *lem)
{
	int		i;
	int		j;

	i = 0;
	while (map[i][0] == '#')
		i++;
	if (map[i][0] >= '1' && map[i][0] <= '9')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_isdigit(map[i][j]) == 1)
				j++;
			else
				ft_leave();
		}
		lem->ants = ft_atoi(map[i]);
		if (lem->ants < 1)
			ft_leave();
		i++;
		return (i);
	}
	ft_leave();
	return (0);
}
