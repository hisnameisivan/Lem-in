/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_p3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 00:07:53 by waddam            #+#    #+#             */
/*   Updated: 2019/09/18 00:34:09 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_helper_1(char map_i, t_valid *val, int *i, int *fl)
{
	map_i == ' ' ? val->space++ : val->defice++;
	(*fl) = 0;
	(*i)++;
}

void	ft_helper_2(t_valid *val, int *i, int *fl)
{
	val->name++;
	(*fl) = 1;
	(*i)++;
}

int		ft_helper_3(char map_i, t_valid *val, int *i)
{
	while(map_i != ' ')
	{
		if (ft_isdigit(map_i) == 1)
			(*i)++;
		else if (map_i == '\0' || ft_isdigit(map_i) == 0)
			return (0);
	}
	val->count_x++;
	return (-1);
}

int		ft_helper_4(char map_i, t_valid *val, int *i)
{
	while(map_i != '\0')
	{
		if (ft_isdigit(map_i) == 1)
			(*i)++;
		else
			return (0);
	}
	val->count_y++;
	return (-1);
}