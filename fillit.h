/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zszeredi <zszeredi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:24:02 by zszeredi          #+#    #+#             */
/*   Updated: 2020/02/26 17:30:24 by zszeredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFFER_SIZE 21
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include "libft/libft.h"

typedef	struct	s_c_var
{
	int i;
	int j;
	int m;
	int counter;
}				t_c_var;

typedef struct	s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef	struct	s_tetra
{
	int			tab[4][4];
	int			total_tetroes;
	int			letter;
	t_coords	cordis[4];
}				t_tetra;

typedef struct	s_table
{
	char		**square;
	int			table_size;
}				t_table;

t_tetra			*read_file(const int fd);
int				ft_nbt(int number_tetroes, char **str);
int				ft_m_last_line(char **str, int number_tetroes);
int				ft_s_last_line(char **str);
int				check_charachters(char *str);
int				ft_check_nl(char *str);
int				ft_check_for_charachter(char *str, int x);
int				ft_charachter(char *str, int j, int n, char c);
int				ft_check_connections(char *str, char c);
int				move_up(t_tetra *tetra);
int				move_left(t_tetra *tetra);
void			move_up_left(t_tetra **t, int nb);
void			ft_conversion(int i, t_tetra *res, int bv, char **tetros);
t_tetra			*ft_store_teros(char **tetros, int nb);
void			*ft_delete_double_array(char **str);
t_c_var			declare(t_c_var *p);
t_tetra			cordi (t_tetra s, t_c_var *p);
void			save_cordis(t_tetra **s, int nb);
void			dot(char *s, int i);
int				ft_sqrt(int nb);
int				min_table(int i);
t_table			*ft_ptr_alloc();
char			**ft_allocate(t_table *s2, t_tetra *s, int size);
int				ft_letter(t_table *s2, t_tetra s, int i, int j);
int				ft_compare(t_table *s2, t_tetra s, int i, int j);
char			**tetri_del(t_table *s2, int letter);
t_table			*delete_table (char **str, t_table *s2);
int				solver(t_table *s2, t_tetra *s);
void			ft_print_table(t_table *t);

#endif
