/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:07:03 by zszeredi          #+#    #+#             */
/*   Updated: 2020/03/07 11:00:02 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_s_last_line(char **str)
{
	int j;
	int i;

	i = 0;
	j = 19;
	if (str[i][j] == '\n')
		return (-1);
	return (1);
}

int		ft_m_last_line(char **str, int number_tetroes)
{
	int j;
	int i;

	j = 19;
	i = 0;
	while ((str[i][j] != '\0') && (number_tetroes >= 1))
	{
		if (str[i][j] != '\n')
			return (-1);
		number_tetroes--;
		if (number_tetroes != 1)
			i++;
	}
	if (number_tetroes == 0)
	{
		if (str[i][j] == '\n')
			return (-1);
		str[i][j] = '\0';
	}
	return (1);
}

int		ft_nbt(int number_tetroes, char **str)
{
	if (number_tetroes < 1 || number_tetroes > 26)
		return (-1);
	if (number_tetroes == 1)
		if (ft_s_last_line(str) < 0)
			return (-1);
	if (number_tetroes > 1 && number_tetroes <= 26)
		if ((ft_m_last_line(str, number_tetroes)) < 1)
			return (-1);
	return (1);
}

t_tetra	*read_file(const int fd)
{
	int		i;
	int		ret;
	int		number_tetroes;
	char	buf[BUFFER_SIZE + 1];
	char	**str;

	number_tetroes = 0;
	i = -1;
	if (((fd < 0 || fd >= OPEN_MAX) || read(fd, buf, 0) < 0
				|| (!(str = ft_memalloc(27 * sizeof(char*))))))
		return (NULL);
	while ((ret = read(fd, buf, BUFFER_SIZE)) && number_tetroes <= 26)
	{
		buf[ret] = '\0';
		if (!(str[++i] = ft_strdup(buf)))
			return (NULL);
		if ((check_charachters(str[i])) < 1)
			return (ft_delete_double_array(str));
		if (++number_tetroes == 26)
			break ;
	}
	if (number_tetroes > 27 || (ft_nbt(number_tetroes, str)) < 1)
		return (ft_delete_double_array(str));
	return (ft_store_teros(str, number_tetroes + 1));
}
