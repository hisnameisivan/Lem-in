/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:50:14 by waddam            #+#    #+#             */
/*   Updated: 2019/05/19 22:50:45 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_valid_simbols(char c)
{
	if (ft_strchr("cspdDioOuUxXflhzj -+0123456789#%.", c) != NULL)
		return (1);
	return (0);
}

int		ft_csp(va_list ap, t_pf *pf, char *p, int *count)
{
	if (*p == 'c')
	{
		ft_char(ap, count, pf);
		free(pf);
		return (1);
	}
	if (*p == 's')
	{
		ft_string(ap, count, pf);
		free(pf);
		return (1);
	}
	if (*p == 'p')
	{
		ft_pointer(ap, count, pf);
		free(pf);
		return (1);
	}
	return (0);
}

int		ft_dioux_prc_f(va_list ap, t_pf *pf, char *p, int *count)
{
	if (*p == 'd' || *p == 'D' || *p == 'i' || *p == 'o' || *p == 'O'
		|| *p == 'u' || *p == 'U' || *p == 'x' || *p == 'X')
	{
		ft_decimal(ap, count, pf);
		free(pf);
		return (1);
	}
	if (*p == 'f')
	{
		ft_float(ap, count, pf);
		free(pf);
		return (1);
	}
	if (*p == '%')
	{
		ft_percent(count, pf);
		free(pf);
		return (1);
	}
	return (0);
}

void	ft_if_procent(va_list ap, char **p, int *count)
{
	int		valid;
	t_pf	*pf;

	valid = 0;
	pf = NULL;
	(*p)++;
	pf = ft_create_struct_printf();
	ft_fill_struct(pf, *p);
	while (**p && (valid = ft_valid_simbols(**p)) == 1)
	{
		if (ft_csp(ap, pf, *p, count))
			break ;
		if (ft_dioux_prc_f(ap, pf, *p, count))
			break ;
		(*p)++;
	}
	if (valid == 0 && **p)
	{
		ft_char_2(**p, count, pf);
		free(pf);
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*p;
	int		count;

	p = (char *)fmt;
	count = 0;
	va_start(ap, fmt);
	while (!p)
		return (-1);
	while (*p)
	{
		if (*p == '%')
			ft_if_procent(ap, &p, &count);
		else
			ft_putchar_pf(*p, &count);
		if (*p)
			p++;
	}
	va_end(ap);
	return (count);
}
