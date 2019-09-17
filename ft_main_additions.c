/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_additions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:12:32 by waddam            #+#    #+#             */
/*   Updated: 2019/09/17 22:28:44 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_init(void *data, size_t size)
{
	ft_bzero(data, size);
}

void		ft_leave(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

static int	ft_strsrch(char *str, char chr)
{
	int		i;

	i = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == chr && str[i + 1] == chr)
			return (1);
		i++;
	}
	return (0);
}

void		ft_read_map(char ***map)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	char	*line;

	if (!(line = ft_strnew(0)))
		ft_leave();
	while ((ret = read(0, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_strsrch(buff, '\n') == 1)
			ft_leave();
		temp = line;
		line = ft_strjoin(line, buff);
		free(temp);
	}
	if (line == NULL)
		ft_leave();
	*map = ft_strsplit(line, '\n');
	free(line);
}
