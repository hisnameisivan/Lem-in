/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:22:44 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/19 22:37:08 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_specificator(char *ptr)
{
	if (*ptr != 'c' && *ptr != 's' && *ptr != 'p' &&
	*ptr != 'd' && *ptr != 'D' && *ptr != 'i' && *ptr != 'o'
	&& *ptr != 'O' && *ptr != 'u' && *ptr != 'U' && *ptr != 'x'
	&& *ptr != 'X' && *ptr != 'f')
	{
		return (1);
	}
	return (0);
}

static void	ft_change_mod(t_pf *pf)
{
	pf->hh = 1;
	pf->h = 0;
}

void		ft_search_modificator_h(char *ptr, t_pf *pf)
{
	int		count_h;

	count_h = 0;
	while (ft_check_specificator(ptr) && *ptr != '\0')
	{
		if (*ptr == 'h' && pf->h != 1)
		{
			pf->h = 1;
			count_h++;
			ptr++;
			while (ft_check_specificator(ptr) && *ptr != '\0')
			{
				if (*ptr != 'h' && pf->h == 1)
					break ;
				else if (*ptr == 'h')
					count_h++;
				ptr++;
				if ((count_h % 2) == 0)
					ft_change_mod(pf);
				else
					pf->h = 1;
			}
		}
		ptr++;
	}
}

void		ft_check_modificator(t_pf *pf, char *ptr)
{
	ft_search_modificator_h(ptr, pf);
	while (ft_check_specificator(ptr) && *ptr != '\0')
	{
		if (*ptr == 'l')
		{
			if (*(ptr + 1) == 'l')
			{
				pf->ll = 1;
				return ;
			}
			else
			{
				pf->l = 1;
				return ;
			}
		}
		else if (*ptr == 'j')
			pf->j = 1;
		else if (*ptr == 'z')
			pf->z = 1;
		ptr++;
	}
}

int			ft_search_before_spec(char *p, char c)
{
	while (ft_check_specificator(p) && *p != '\0')
	{
		if (*p == c)
			return (1);
		else
			p++;
	}
	return (0);
}
