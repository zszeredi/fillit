/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:41:46 by zszeredi          #+#    #+#             */
/*   Updated: 2020/03/07 11:01:18 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_table(t_table *t)
{
	int		m;
	int		j;

	m = 0;
	while (t->square[m] && m < t->table_size)
	{
		j = 0;
		while (t->square[m][j] && j <= t->table_size)
		{
			ft_putchar(t->square[m][j]);
			j++;
		}
		ft_putchar('\n');
		m++;
	}
}
