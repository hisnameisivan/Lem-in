/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:07:23 by waddam            #+#    #+#             */
/*   Updated: 2019/09/18 00:37:07 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static int	ft_helpers(char map_i, t_valid *val, int *i, int *fl)
// {
// 	if (map_i == ' ' || map_i == '-')
// 		ft_helper_1(map_i, val, i, fl);
// 	else if ((map_i != ' ' && (*fl) == 0 && val->name < 1))
// 		ft_helper_2(val, i, fl);
// 	else if ((map_i != '-' && (*fl) == 0 && val->name < 2 && val->defice == 1))
// 		ft_helper_2(val, i, fl);
// 	else if ((map_i != ' ' && map_i != '-') && (*fl) == 0 && val->space == 1) /* для валидации координаты x */
// 	{
// 		if (ft_helper_3(map_i, val, i) == 0)
// 			return (0);
// 	}
// 	else if ((map_i != ' ' && map_i != '-') && (*fl) == 0 && val->space == 2)
// 	{
// 		if (ft_helper_4(map_i, val, i) == 0)
// 			return (0);
// 	}
// 	else if (val->name == 1 && (*fl) == 0 && (map_i != ' ' && map_i != '-') && val->defice == 1) /* валидируем name2 */
// 	{
// 		if (map_i == '#' || map_i == 'L')
// 			return (0);
// 		ft_helper_1(map_i, val, i, fl);
// 	}
// 	else if ((map_i != ' ' && map_i != '-') && (*fl) == 1) /* находимся в name */
// 		(*i)++;
// 	else
// 		return (0);
// 	return (-1);
// }

int			ft_valid_str(char *map)
{
	int		i;
	int		fl;
	t_valid	val;

	i = 0;
	fl = 0;
	ft_init(&val, sizeof(t_valid));
	if (map[0] == 'L')
		return (0);
	else if (map[0] == '#')
		return (3);
	while (map[i])
	{
		// if (ft_helpers(map[i], &val, &i, &fl) == 0)
		// 	return (0);
		if (map[i] == ' ' || map[i] == '-')
		{
			map[i] == ' ' ? val.space++ : val.defice++;
			fl = 0;
			i++;
		}
		else if ((map[i] != ' ' && fl == 0 && val.name < 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != '-' && fl == 0 && val.name < 2 && val.defice == 1))
		{
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 1) /* для валидации координаты x */
		{
			while(map[i] != ' ')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else if (map[i] == '\0' || ft_isdigit(map[i]) == 0)
					return (0);
			}
			val.count_x++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 0 && val.space == 2)
		{
			while(map[i] != '\0')
			{
				if (ft_isdigit(map[i]) == 1)
					i++;
				else
					return (0);
			}
			val.count_y++;
		}
		else if (val.name == 1 && fl == 0 && (map[i] != ' ' && map[i] != '-') && val.defice == 1) /* валидируем name2 */
		{
			if (map[i] == '#' || map[i] == 'L')
				return (0);
			val.name++;
			fl = 1;
			i++;
		}
		else if ((map[i] != ' ' && map[i] != '-') && fl == 1) /* находимся в name */
			i++;
		else
		    return (0);
	}
	if (val.space == 2 && val.name == 1 && val.count_x == 1 && val.count_y == 1)
		return (4);
	else if (val.defice == 1 && val.name == 2)
		return (5);
	else
		return (0);
}