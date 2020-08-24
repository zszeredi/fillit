/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:20:20 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/26 17:22:02 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_delete_double_array(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
