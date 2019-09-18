/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:06:48 by waddam            #+#    #+#             */
/*   Updated: 2019/09/19 01:07:02 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_search_name(char **map, t_room **room, char end)
{
	int		len_name;
	int		index;
	char	*name;
	char	*temp;

	len_name = 0;
	index = 0;
	temp = *map;
	name = NULL;
	while (**map != end)
	{
		(*map)++;
		len_name++;
	}
	if (!(name = ft_strnew(len_name)))
		ft_leave();
	ft_strncpy(name, temp, len_name);
	while (room[index])
	{
		if (ft_strcmp(name, room[index]->name) == 0)
			break ;
		index++;
	}
	ft_strdel(&name);
	return (room[index] == NULL ? -1 : index);
}

static void	ft_write_links(char *map, t_room **room, int **set)
{
	int		name1_ind;
	int		name2_ind;
	int		i;

	if ((name1_ind = ft_search_name(&map, room, '-')) == -1)
		ft_leave();
	map++;
	if ((name2_ind = ft_search_name(&map, room, '\0')) == -1)
		ft_leave();
	i = 0;
	while (set[name1_ind][i] != -1)
		i++;
	set[name1_ind][i] = name2_ind;
	i = 0;
	while (set[name2_ind][i] != -1)
		i++;
	set[name2_ind][i] = name1_ind;
}

void		ft_make_sets(char **map, t_room **room, t_lem *lem)
{
	int		i;
	int		**set;

	i = 0;
	set = ft_alloc_matrix(lem->count_rooms, lem->count_rooms);
	while (map[i])
	{
		if (ft_valid_str(map[i]) == 5)
			ft_write_links(map[i], room, set);
		i++;
	}
	lem->sets = set;
}
