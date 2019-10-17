/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:26:49 by waddam            #+#    #+#             */
/*   Updated: 2019/05/21 20:33:30 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_fraction(va_list ap, t_pf *pf)
{
	long double	fraction;
	char		*znak;

	if (pf->bl)
	{
		fraction = va_arg(ap, long double);
		znak = (char *)&fraction;
		znak += 9;
		pf->znak = ((*znak < 0) ? -1 : 1);
	}
	else
	{
		fraction = va_arg(ap, double);
		znak = (char *)&fraction;
		znak += 9;
		pf->znak = ((*znak < 0) ? -1 : 1);
	}
	return (fraction);
}

char		*ft_create_fr(t_pf *pf, long double fraction, int *i, int *rounding)
{
	int			prec;
	long long	temp;
	char		*fr;

	prec = 0;
	if (!(fr = ft_strnew(5000)))
		return (NULL);
	prec = ((pf->dot == 0) ? 7 : (pf->prec + 1));
	while (prec > 0)
	{
		fraction = fraction * 10;
		fr[*i] = (int)fraction + '0';
		temp = (long long)fraction;
		fraction = fraction - temp;
		prec--;
		(*i)++;
	}
	(*i)--;
	*rounding = fr[*i] - '0';
	fr[*i] = '\0';
	(*i)--;
	return (fr);
}

long long	ft_rounding(t_pf *pf, char *fr, int i, long long whole)
{
	fr[i]++;
	while (((fr[i] - '0') == 10) && (i >= 0))
	{
		fr[i] = '0';
		if (i == 0)
			(whole >= 0) ? (whole++) : (whole--);
		else
			fr[i - 1]++;
		i--;
	}
	if (pf->dot && pf->prec == 0)
		(whole >= 0) ? (whole++) : (whole--);
	return (whole);
}

char		*ft_new_float(t_pf *pf, char *fr, long long whole, long double fn)
{
	int		i;
	int		rounding;
	char	*wh;
	char	*new_float;

	i = 0;
	rounding = 0;
	wh = NULL;
	new_float = NULL;
	fr = ft_create_fr(pf, fn, &i, &rounding);
	if (rounding >= 5)
		whole = ft_rounding(pf, fr, i, whole);
	wh = ft_long_to_ascii(whole);
	pf->prec = 0;
	new_float = ft_strjoin_float(wh, fr, pf);
	return (new_float);
}

void		ft_float(va_list ap, int *count, t_pf *pf)
{
	long long	whole;
	long double	fraction;
	char		*fr;
	char		*new_float;

	fr = NULL;
	new_float = NULL;
	fraction = ft_fraction(ap, pf);
	if (ft_check_inf(pf, fraction, count) == 1)
		return ;
	whole = (long long)fraction;
	if ((fraction = fraction - whole) < 0)
		fraction = fraction * (-1);
	new_float = ft_new_float(pf, fr, whole, fraction);
	ft_cmp_wid_prec_num(pf, new_float);
	ft_complex_constructor(pf, new_float, count);
	free(fr);
	free(new_float);
}
