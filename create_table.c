/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:23 by zszeredi          #+#    #+#             */
/*   Updated: 2020/04/28 17:09:29 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	dot(char *s, int i)
{
	while (i > 0)
	{
		i--;
		s[i] = '.';
	}
}

int		ft_sqrt(int nb)
{
	int square;

	square = 1;
	while (nb > 1 && square <= nb / 2)
	{
		if (square * square >= nb)
			return (square);
		square++;
	}
	return (2);
}

int		min_table(int i)
{
	int size;

	size = ft_sqrt(i * 4);
	return (size);
}

t_table	*ft_ptr_alloc(void)
{
	t_table *s2;

	if (!(s2 = (t_table *)malloc(sizeof(t_table))))
	{
		free(s2);
		s2 = NULL;
	}
	return (s2);
}

char	**ft_allocate(t_table *s2, t_tetra *s, int size)
{
	int		i;

	i = -1;
	if (s2->square != NULL)
	{
		s2->table_size = min_table(s->total_tetroes + size);
		if (!(s2->square = ft_memalloc((s2->table_size + 1) * sizeof(char *))))
			return (ft_delete_double_array(s2->square));
		while (++i < s2->table_size)
		{
			if (!(s2->square[i] = ft_memalloc((s2->table_size + 1)
							* sizeof(char))))
				return (ft_delete_double_array(s2->square));
			else
				dot(s2->square[i], s2->table_size);
		}
		if (solver(s2, s) == 1)
			ft_print_table(s2);
		return (s2->square);
	}
	return (NULL);
}
