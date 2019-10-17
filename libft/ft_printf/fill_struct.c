/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:40:40 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/19 22:43:35 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyze(t_pf *pf)
{
	if (pf->spec == 'D' || pf->spec == 'O' || pf->spec == 'U')
	{
		pf->spec += 32;
		pf->l = 1;
	}
	if (pf->ll || pf->l || pf->z || pf->j)
	{
		pf->h = 0;
		pf->hh = 0;
	}
	else if (pf->h)
		pf->hh = 0;
	if (pf->spec != 0 && pf->spec != 'f' && pf->spec != 'c' &&
	pf->spec != 's' && !pf->procent && pf->dot && pf->nul)
		pf->nul = 0;
}

void	ft_fill_width(t_pf *pf, char **p)
{
	pf->wid = 0;
	while (**p >= '0' && **p <= '9')
	{
		pf->wid = pf->wid * 10 + **p - '0';
		(*p)++;
	}
	(*p)--;
}

void	ft_fill_precision(t_pf *pf, char **p)
{
	pf->dot = 1;
	pf->prec = 0;
	while (**p >= '0' && **p <= '9')
	{
		pf->prec = pf->prec * 10 + **p - '0';
		(*p)++;
	}
	(*p)--;
}

void	ft_fill_flags(t_pf *pf, char *p)
{
	if (*p == '-')
		pf->minus = 1;
	else if (*p == '+')
		pf->plus = 1;
	else if (*p == '#')
		pf->resh = 1;
	else if (*p == ' ')
		pf->space = 1;
	else if (*p == 'L')
		pf->bl = 1;
	else if (*p == '%')
		pf->procent = 1;
}

void	ft_fill_struct(t_pf *pf, char *p)
{
	ft_check_modificator(pf, p);
	while (ft_check_specificator(p) && *p != '\0')
	{
		if (*p == '0')
			pf->nul = 1;
		else if (pf->dot == 0 && *p >= '0' && *p <= '9')
			ft_fill_width(pf, &p);
		else if (*(p - 1) == '.' && *p >= '0' && *p <= '9')
			ft_fill_precision(pf, &p);
		else if (*p == '.' && (*p < '0' || *p > '9'))
		{
			pf->dot = 1;
			pf->prec = 0;
		}
		else
			ft_fill_flags(pf, p);
		p++;
	}
	pf->spec = *p;
	ft_analyze(pf);
}
