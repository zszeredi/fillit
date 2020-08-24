/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:06:07 by zszeredi          #+#    #+#             */
/*   Updated: 2020/04/28 17:07:24 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int n)
{
	if (n == 1)
		ft_putstr("usage: ./fillit filename\n");
	else
		ft_putstr("error\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_tetra	*s;
	t_table *s2;

	s = NULL;
	if (*argv && argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			return (ft_error(1));
		if ((s = read_file(fd)) == NULL)
			return (ft_error(2));
		else
		{
			s2 = ft_ptr_alloc();
			s2->square = ft_allocate(s2, s, 0);
			free(s);
			free(s2);
			return (0);
		}
		close(fd);
	}
	else
		return (ft_error(1));
	return (0);
}
