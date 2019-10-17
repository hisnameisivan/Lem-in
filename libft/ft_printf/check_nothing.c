/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nothing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 19:58:41 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/21 16:20:59 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_nothing_minus(t_pf *pf, int *count)
{
	if (pf->dot != 0 && pf->prec == 0)
	{
		if (pf->spec == 'd' || pf->spec == 'i')
		{
			if (pf->plus == 1)
				return (ft_print_nothing_12(pf, 1, count));
			else if (pf->plus == 0)
				return (ft_print_nothing_12(pf, 2, count));
		}
		else if (pf->resh != 0 && (pf->spec == 'o'))
			return (ft_print_nothing_34(pf, 4, count));
		else
			return (ft_print_nothing_12(pf, 2, count));
	}
	else if ((pf->spec == 'x' || pf->spec == 'X' ||
	pf->spec == 'o') && pf->resh)
		return (ft_print_nothing_34(pf, 4, count));
	return (0);
}

int		ft_printf_nothing_without_minus(t_pf *pf, int *count)
{
	if (pf->dot != 0 && pf->prec == 0)
	{
		if (pf->spec == 'd' || pf->spec == 'i')
		{
			if (pf->plus == 1)
				return (ft_print_nothing_78(pf, 8, count));
			else if (pf->plus == 0)
				return (ft_print_nothing_12(pf, 2, count));
		}
		else if (pf->resh != 0 && (pf->spec == 'o'))
			return (ft_print_nothing_56(pf, 5, count));
		else
			return (ft_print_nothing_12(pf, 2, count));
	}
	else if ((pf->spec == 'x' || pf->spec == 'X' || pf->spec == 'o')
	&& pf->resh)
		return (ft_print_nothing_56(pf, 5, count));
	return (0);
}

int		ft_check_nothing(char *num, t_pf *pf, int *count)
{
	if (num == NULL)
		return (0);
	if (ft_strcmp("0", num) == 0)
	{
		if (pf->minus)
			return (ft_printf_nothing_minus(pf, count));
		else if (!pf->minus)
			return (ft_printf_nothing_without_minus(pf, count));
	}
	return (0);
}
