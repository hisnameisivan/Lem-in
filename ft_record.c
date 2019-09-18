/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:36:24 by waddam            #+#    #+#             */
/*   Updated: 2019/09/19 01:22:45 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_check_repeat(t_room **room, t_lem *lem)
{
	int		i;
	int		k;
	char	tmp[1000];

	i = 0;
	while (i < lem->count_rooms)
	{
		k = 0;
		ft_memset(tmp, 0, 1000);
		ft_strcpy(tmp, room[i]->name);
		while (k < lem->count_rooms)
		{
			if (ft_strcmp(tmp, room[k]->name) == 0 && k != i)
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

static int	ft_no_start_end(t_room **room, t_lem *lem)
{
	int		tmp;

	tmp = lem->count_rooms - 1;
	if (room[0]->name == NULL || room[tmp]->name == NULL)
		return (1);
	else if (ft_strcmp(room[0]->name, room[tmp]->name) == 0)
		return (1);
	else
		return (0);
}

static void	ft_helpers_1(char **map, t_room **room, t_lem *lem, int *i)
{
	while (ft_valid_sharp(map[*i + 1], lem) == 3)
		(*i)++;
	(*i)++;
	ft_write(map[*i], room, 0);
}

static void	ft_helpers_2(char **map, t_room **room, t_lem *lem, int *i)
{
	while (ft_valid_sharp(map[*i + 1], lem) == 3)
		(*i)++;
	(*i)++;
	ft_write(map[*i], room, lem->count_rooms - 1);
}

t_room		**ft_record(char **map, t_lem *lem)
{
	int		i;
	int		k;
	t_room	**room;
	int		valid_sharp;

	i = 0;
	k = 1;
	room = ft_alloc_rooms(lem);
	while (map[i])
	{
		valid_sharp = ft_valid_sharp(map[i], lem);
		if (map[i][0] == '#' && valid_sharp == 1)
			ft_helpers_1(map, room, lem, &i);
		else if ((map[i][0] == '#' && valid_sharp == 2))
			ft_helpers_2(map, room, lem, &i);
		else if (ft_valid_str(map[i]) == 4)
		{
			ft_write(map[i], room, k);
			k++;
		}
		i++;
	}
	if (ft_check_repeat(room, lem) == 1 || ft_no_start_end(room, lem) == 1)
		ft_leave();
	return (room);
}
