/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:58:27 by draudrau          #+#    #+#             */
/*   Updated: 2019/09/19 19:45:49 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(void)
{
	t_lem	lem;
	char	**map;
	int		*qu;
	t_room	**room;
	t_path	**path;

	ft_init(&lem, sizeof(t_lem));
	ft_read_map(&map, &lem);
	ft_validation(map, &lem) == 1 ? room = ft_record(map, &lem) : exit(0);
	ft_make_sets(map, room, &lem);
	qu = ft_alloc_qu(lem.count_rooms + 3, &lem);
	ft_bfs2(lem.sets, &lem, room, qu);
	if (room[lem.count_rooms - 1]->lvl == 0)
		ft_leave();
	ft_unblock_all(lem.sets);
	path = ft_alloc_path(3, lem.count_rooms + 1);
	ft_all_paths(path, room, &lem, qu);
	ft_res(path, &lem, room, map);
	free(qu);
	return (0);
}
