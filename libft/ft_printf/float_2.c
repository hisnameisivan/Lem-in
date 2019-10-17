/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:43:22 by waddam            #+#    #+#             */
/*   Updated: 2019/05/21 21:42:22 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_float(char *str1, char *str2, t_pf *pf)
{
	char	*tab;
	int		i;
	int		k;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = -1;
	k = 0;
	if (!(tab = ft_strnew(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (NULL);
	while (str1[++i] != 0)
		tab[i] = str1[i];
	if (*str2 != '\0' || pf->resh == 1)
		tab[i++] = '.';
	while (str2[k] != 0)
		tab[i++] = str2[k++];
	tab[i] = '\0';
	return (tab);
}

void	ft_inf_minus(t_pf *pf, char *new_num, int znak, int *count)
{
	if (pf->plus && znak == 1)
	{
		ft_putchar_pf('+', count);
		pf->wid--;
	}
	else if (pf->space && znak == 1)
	{
		ft_putchar_pf(' ', count);
		pf->wid--;
	}
	ft_putstr_pf(new_num, count);
	ft_type_space(pf->wid, count);
}

void	ft_inf_without_minus(t_pf *pf, char *new_num, int znak, int *count)
{
	((pf->plus || pf->space) && znak == 1) ? pf->wid-- : (pf->wid = pf->wid);
	ft_type_space(pf->wid, count);
	if (pf->plus && znak == 1)
		ft_putchar_pf('+', count);
	else if (pf->space && znak == 1)
		ft_putchar_pf(' ', count);
	ft_putstr_pf(new_num, count);
}

int		ft_analyze_inf(long double num, int *znak)
{
	long double	inf_p;
	long double	inf_m;

	inf_p = 42.0 / 0.0;
	inf_m = -42.0 / 0.0;
	if (num == inf_p)
		return (1);
	else if (num == inf_m)
	{
		*znak = -1;
		return (-1);
	}
	return (0);
}

int		ft_check_inf(t_pf *pf, long double num, int *count)
{
	long double	inf_p;
	long double	inf_m;
	char		*new_num;
	int			znak;

	inf_p = 42.0 / 0.0;
	inf_m = -42.0 / 0.0;
	new_num = NULL;
	znak = 1;
	if (num == inf_m || num == inf_p)
	{
		if (ft_analyze_inf(num, &znak) != 0)
			new_num = ((ft_analyze_inf(num, &znak) == 1) ? "inf" : "-inf");
		pf->wid = ((ft_strcmp("-inf", new_num) == 0) ?
			(pf->wid - 4) : (pf->wid - 3));
		if (pf->minus)
			ft_inf_minus(pf, new_num, znak, count);
		else if (!pf->minus)
			ft_inf_without_minus(pf, new_num, znak, count);
		return (1);
	}
	return (0);
}
