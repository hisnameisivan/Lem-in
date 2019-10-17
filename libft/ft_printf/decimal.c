/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:47:16 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/21 21:46:34 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_complex_constructor(t_pf *pf, char *new_num, int *count)
{
	if (pf->minus)
	{
		if (pf->znak == -1)
			ft_print_sit_1(pf, new_num, count);
		else
		{
			if (pf->plus)
				ft_print_sit_1(pf, new_num, count);
			else
				ft_print_sit_2(pf, new_num, count);
		}
	}
	else
	{
		if (pf->znak == -1)
			ft_print_sit_4(pf, new_num, count);
		else
		{
			if (pf->plus)
				ft_print_sit_4(pf, new_num, count);
			else if (!(pf->plus))
				ft_print_sit_6(pf, new_num, count);
		}
	}
}

void		ft_create_num(char *new_num, t_pf *pf, int *count)
{
	if (new_num)
	{
		if ((ft_check_nothing(new_num, pf, count)) == 1)
		{
			free(new_num);
			return ;
		}
		ft_cmp_wid_prec_num(pf, new_num);
		if (pf->znak == 0)
		{
			if (pf->minus)
				ft_print_sit_2(pf, new_num, count);
			else
				ft_print_sit_6(pf, new_num, count);
			free(new_num);
			return ;
		}
		ft_complex_constructor(pf, new_num, count);
		free(new_num);
	}
}

void		ft_decimal(va_list ap, int *count, t_pf *pf)
{
	long long	num;
	char		*new_num;

	new_num = NULL;
	if (pf->h || pf->l || pf->hh || pf->ll || pf->j || pf->z)
		num = ft_apply_modificator(ap, pf);
	else
	{
		num = va_arg(ap, int);
		((pf->spec == 'd') || (pf->spec == 'i')) ? (num = (int)num) :
			(num = (unsigned int)num);
	}
	if (pf->spec == 'x' || pf->spec == 'X')
		new_num = ft_convert_v_16(num, pf);
	else if (pf->spec == 'o')
		new_num = ft_convert_v_8(num);
	else if (pf->spec == 'u' && num < 0)
		new_num = ft_ulong_to_ascii(num);
	else if (pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'u')
		new_num = ft_long_to_ascii(num);
	ft_create_num(new_num, pf, count);
}
